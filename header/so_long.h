/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:43:48 by itomescu          #+#    #+#             */
/*   Updated: 2022/01/15 10:18:27 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

typedef struct s_data {
	void	*img;
	int		img_w;
	int		img_h;
}				t_data;

typedef struct s_map
{
	char	**map;
	int		row_len;
	int		rows;
	int		to_collect;
	int		collected;
}				t_map;

typedef struct s_vars {
	void	*mlx;
	void	*win;
	t_data	wall;
	t_data	floor;
	t_data	player;
	t_data	food;
	t_data	exit;
	t_map	map;
	int		p_r;
	int		p_c;
	int		moves;
}				t_vars;

// so_long.c
void	move_player(t_vars *v, char c);
void	looping(t_vars vars);
int		check_extension(char *file);
int		valid_char(char *mtx[], int rows);

// map.c
int		get_nr_lines(char *argv[]);
int		is_rectangle(t_vars v);
int		get_map_and_validate(t_vars *vars, char *argv[]);
void	print_element(char elem, t_vars *vars, int col, int row);
int		print_map(t_vars *vars);

// handlers.c
int		handle_keypress(int keysym, t_vars *vars);
int		handle_btnrealease(t_vars *v);

// inits.c
void	init_images(t_vars *vars);
void	init_plr_col(t_vars *v);
void	init_v(t_vars *v);
void	count_moves(t_vars *v, char c);

// validate.c
int		valid_move(t_vars *v, char dir);
int		check_first_last(char *row, int c_r, int t_r);
int		valid_walls(char *mtx[]);
void	is_pec(char chr, int *p, int *e, int *c);
int		has_p_e_c(char *mtx[], int rows);

// exit.c

void	ft_close(t_vars vars);
int		ft_exit(t_vars *v);
#endif