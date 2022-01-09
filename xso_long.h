/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xso_long.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:43:48 by itomescu          #+#    #+#             */
/*   Updated: 2022/01/09 13:44:08 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "libft/libft.h"
# include "mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		img_w;
	int		img_h;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map
{
	char	**map;
	int		row_len;
	int		rows;
}				t_map;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	wall;
	t_data	floor;
	t_data	food;
	t_data	player;
	t_data	exit;
	t_map	map;
	int		px;
	int		py;
}				t_vars;

int		get_map_and_validate(t_vars *vars, char *argv[]);
int		print_map(t_vars vars, t_vars *v);
int		get_nr_lines(char *argv[]);
void	init_images(t_vars vars);
int		valid_walls(char *mtx[]);
int		check_first_last(char *row);
int		has_p_e_c(char *mtx[], int rows);
void	is_pec(char chr, int *p, int *e, int *c);
void	print_player(t_vars vars, int row, int col);
void	print_collectible(t_vars vars, int row, int col);
void	print_wall(t_vars vars, int row, int col);
void	print_floor(t_vars vars, int row, int col);
void	print_exit(t_vars vars, int row, int col);
void	move_player(t_vars vars);
//void	loop(t_vars vars);
#endif