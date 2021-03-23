/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:37:34 by masharla          #+#    #+#             */
/*   Updated: 2021/03/14 00:38:52 by ruslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../srcs/gnl/get_next_line.h"
# include "cub3d.h"

int		ft_is_map(char *str);
void	ft_lstclear_save_content(t_list **lst);
char	*ft_remove_spaces(char *str);
int		check_map(char **map);
void	clear_t_conf(t_conf *config);
int		spcs_end(char *str);
int		check_config(t_conf *cfg, int check_map);

#endif
