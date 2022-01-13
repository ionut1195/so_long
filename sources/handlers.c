/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 15:38:01 by itomescu          #+#    #+#             */
/*   Updated: 2022/01/12 18:51:58 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	handle_keypress(int keysym, t_vars *vars)
{
	if (keysym == 0xFF1B)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = NULL;
	}
	else
	{
		move_player(vars, keysym);
	}
	printf("Moves: %d\n", vars->moves);
	return (0);
}

int	handle_btnrealease(t_vars *v)
{
	mlx_destroy_window(v->mlx, v->win);
	v->win = NULL;
	return (0);
}
