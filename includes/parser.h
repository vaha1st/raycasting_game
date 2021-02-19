/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: masharla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/19 18:37:34 by masharla          #+#    #+#             */
/*   Updated: 2021/02/19 18:44:00 by masharla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "../srcs/gnl/get_next_line.h"
# include "cub3d.h"

int		ft_is_map(char *str);
void	ft_lstclear_save_content(t_list **lst);
char	*ft_remove_spaces(char *str);
void	initialize_t_conf(t_conf *config);
void	clear_t_conf(t_conf *config);

#endif
