/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 21:05:05 by masharla          #+#    #+#             */
/*   Updated: 2021/03/12 12:47:56 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITMAP_H
# define BITMAP_H

# include <fcntl.h>
# include <stdlib.h>
# include "../srcs/libft/libft.h"
# include "cub3d.h"

typedef	struct	s_bmpfileheader
{
	uint8_t		filetype[2];
	uint32_t	filesize;
	uint32_t	reserved;
	uint32_t	pixel_data_offset;
}				t_bmpfileheader;

typedef struct	s_bmpinfoheader
{
	uint32_t	headersize;
	int32_t		image_w;
	int32_t		image_h;
	uint16_t	planes;
	uint16_t	bit_per_pixel;
	uint32_t	compression;
	uint32_t	image_size;
	int32_t		x_pixelspermeter;
	int32_t		y_pixelspermeter;
	uint32_t	totalcolors;
	uint32_t	importantcolors;
}				t_bmpinfoheader;

typedef	struct	s_bitmap
{
	t_bmpfileheader	fileheader;
	t_bmpinfoheader	infoheader;
}				t_bitmap;
#endif
