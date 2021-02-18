#ifndef CUB3D_H
# define CUB3D_H

#include "../srcs/libft/libft.h"
#include "../srcs/gnl/get_next_line.h"

typedef struct	s_conf
{
	int		res_x;
	int		res_y;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char 	*sprite;
	char 	*floor_c;
	char 	*ceilling_c;
	char 	**map;
}				t_conf;

#endif
