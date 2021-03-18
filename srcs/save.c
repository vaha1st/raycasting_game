/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 20:46:03 by masharla          #+#    #+#             */
/*   Updated: 2021/03/18 17:54:16 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bitmap.h"
#include "../includes/utils.h"

static void	init_bmp_headers(t_global *global, t_bitmap *bmp, int fd)
{
	uint32_t img_size;

	img_size = global->config->res_x * global->config->res_y * 4;
	ft_strlcpy((char *)&bmp->fileheader.filetype, "BM", 3);
	bmp->fileheader.filesize = img_size * global->window.bit_per_pixel / 8 + 54;
	bmp->fileheader.reserved = 0;
	bmp->fileheader.pixel_data_offset = 54;
	bmp->infoheader.headersize = sizeof(t_bmpinfoheader);
	bmp->infoheader.image_w = global->config->res_x;
	bmp->infoheader.image_h = global->config->res_y;
	bmp->infoheader.planes = 1;
	bmp->infoheader.bit_per_pixel = global->window.bit_per_pixel;
	bmp->infoheader.compression = 0;
	bmp->infoheader.image_size = img_size;
	bmp->infoheader.x_pixelspermeter = 0;
	bmp->infoheader.y_pixelspermeter = 0;
	bmp->infoheader.totalcolors = 0;
	bmp->infoheader.importantcolors = 0;
	write(fd, &bmp->fileheader.filetype, 2);
	write(fd, &bmp->fileheader.filesize, 4);
	write(fd, &bmp->fileheader.reserved, 4);
	write(fd, &bmp->fileheader.pixel_data_offset, 4);
	write(fd, &bmp->infoheader, sizeof(t_bmpinfoheader));
}

static void	write_pixels(t_global *global, t_bitmap *bmp, int fd)
{
	int32_t		i;
	int32_t		j;
	uint8_t		rgb[4];

	i = (bmp->infoheader.image_w * bmp->infoheader.image_h\
			- bmp->infoheader.image_w) * 4;
	while (i >= 0)
	{
		j = 0;
		while (j < bmp->infoheader.image_w)
		{
			rgb[0] = global->window.address[i] % 256;
			rgb[1] = global->window.address[i + 1] % 256;
			rgb[2] = global->window.address[i + 2] % 256;
			rgb[3] = 0;
			write(fd, rgb, 4);
			j++;
			i += 4;
		}
		i -= bmp->infoheader.image_w * 2 * 4;
	}
}

void		make_screenshot(t_global *global)
{
	int			fd;
	t_bitmap	bmp;

	fd = open("./screenshot.bmp", O_CREAT | O_WRONLY | O_TRUNC, 0755);
	if (!fd)
	{
		ft_putstr_fd("Error: cannot create file", 1);
		exit(0);
	}
	global->window.bit_per_pixel = BPP;
	global->window.line_len = L_LEN;
	global->window.endian = ENDIAN;
	global->window.window = NULL;
	global->window.image = mlx_new_image(global->window.mlx,\
			global->config->res_x, global->config->res_y);
	global->window.address = mlx_get_data_addr(global->window.image,\
			&global->window.bit_per_pixel, &global->window.line_len,\
			&global->window.endian);
	draw_floor_ceiling(global);
	draw_player_view(global);
	init_bmp_headers(global, &bmp, fd);
	write_pixels(global, &bmp, fd);
	close(fd);
	window_exit(global);
}
