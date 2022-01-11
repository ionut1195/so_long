/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:40:09 by itomescu          #+#    #+#             */
/*   Updated: 2022/01/11 21:11:10 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	init_images(t_vars *vars)
{
	vars->wall.img = mlx_xpm_file_to_image(vars->mlx, "./img/brick_wall.xpm",
			&vars->wall.img_h, &vars->wall.img_w);
	vars->floor.img = mlx_xpm_file_to_image(vars->mlx, "./img/floor.xpm",
			&vars->floor.img_h, &vars->floor.img_w);
	vars->player.img = mlx_xpm_file_to_image(vars->mlx, "./img/courage.xpm",
			&vars->player.img_h, &vars->player.img_w);
	vars->exit.img = mlx_xpm_file_to_image(vars->mlx, "./img/exit.xpm",
			&vars->exit.img_h, &vars->exit.img_w);
	vars->food.img = mlx_xpm_file_to_image(vars->mlx, "./img/food.xpm",
			&vars->food.img_h, &vars->food.img_w);
}

void	init_plr_col(t_vars *v)
{
	int	r;
	int	c;

	r = 0;
	while (v->map.map[r])
	{
		c = 0;
		while (v->map.map[r][c])
		{
			if (v->map.map[r][c] == 'P')
			{
				v->p_r = r;
				v->p_c = c;
			}
			else if (v->map.map[r][c] == 'C')
				v->map.to_collect++;
			c++;
		}
		r++;
	}
}

void	init_v(t_vars *v)
{
	v->p_r = 0;
	v->p_c = 0;
	v->moves = 0;
	v->map.to_collect = 0;
	v->map.collected = 0;
}
