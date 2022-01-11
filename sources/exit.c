/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:35:23 by itomescu          #+#    #+#             */
/*   Updated: 2022/01/11 21:11:06 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

void	ft_close(t_vars vars)
{
	mlx_destroy_image(vars.mlx, vars.player.img);
	mlx_destroy_image(vars.mlx, vars.wall.img);
	mlx_destroy_image(vars.mlx, vars.floor.img);
	mlx_destroy_image(vars.mlx, vars.food.img);
	mlx_destroy_image(vars.mlx, vars.exit.img);
	mlx_destroy_display(vars.mlx);
}

int	ft_exit(t_vars *v)
{
	if (v->map.map[v->p_r][v->p_c] == 'E')
	{
		mlx_destroy_window(v->mlx, v->win);
		v->win = NULL;
		return (0);
	}
	else
		return (1);
}
