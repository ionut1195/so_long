/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:43:48 by itomescu          #+#    #+#             */
/*   Updated: 2022/01/03 20:04:45 by itomescu         ###   ########.fr       */
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
	int		img_width;
	int		img_height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_map
{
	char	**map;
	int		size;
}				t_map;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	t_data	img;
	t_map	map;
}				t_vars;

void	get_map(t_vars vars, char *argv[]);

#endif