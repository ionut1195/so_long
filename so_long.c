/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:13:59 by itomescu          #+#    #+#             */
/*   Updated: 2022/01/09 22:43:04 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
//#include <X11/X.h>
//#include <X11/keysym.h>

int	ft_close(t_vars vars)
{
	mlx_destroy_image(vars.mlx, vars.player.img);
	mlx_destroy_image(vars.mlx, vars.wall.img);
	mlx_destroy_image(vars.mlx, vars.floor.img);
	mlx_destroy_image(vars.mlx, vars.food.img);
	mlx_destroy_image(vars.mlx, vars.exit.img);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	if (vars.map.map)
		free(vars.map.map);
	return (0);
}

int		valid_move(t_vars *v, char dir)
{
	if (dir == 'w')
	{
		if (v->map.map[v->p_r - 1][v->p_c] == '1')
			return (0);
	}
	else if (dir == 'a')
	{
		if (v->map.map[v->p_r][v->p_c - 1] == '1')
			return (0);
	}
	else if (dir == 's')
	{
		if (v->map.map[v->p_r + 1][v->p_c] == '1')
			return (0);
	}
	else if (dir == 'd')
	{
		if (v->map.map[v->p_r][v->p_c + 1] == '1')
			return (0);
	}
	return (1);
}

void	move_player(t_vars *v, char c)
{
	if (!valid_move(v, c))
		return ;
	if (c == 'w')
	{
		v->map.map[v->p_r][v->p_c] = '0';
		v->p_r -= 1;
	}
	else if (c == 'a')
	{
		v->map.map[v->p_r][v->p_c] = '0';
		v->p_c -= 1;
	}
	else if (c == 's')
	{
		v->map.map[v->p_r][v->p_c] = '0';
		v->p_r += 1;
	}
	else if (c == 'd')
	{
		v->map.map[v->p_r][v->p_c] = '0';
		v->p_c += 1;
	}
	v->map.map[v->p_r][v->p_c] = 'P';
}

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
	printf("Keypress: %d\n", keysym);
	return (0);
}

void	init_v(t_vars *v)
{
	v->p_r = 0;
	v->p_c = 0;
	v->steps = 0;
	v->map.to_collect = 0;
	v->map.collected = 0;
}

void	looping(t_vars vars)
{
	mlx_loop_hook(vars.mlx, &print_map, &vars);
	mlx_hook(vars.win, 2, 1L<<0, &handle_keypress, &vars);
	mlx_loop(vars.mlx);	
}
int	main(int argc, char *argv[])
{
	t_vars	vars;
	int		valid;
	//char	*rel_path;
	
	if (argc <= 1)
		return (-1);
	vars.mlx = mlx_init();
	
	//rel_path =  "./player/brick_wall.xpm";
	init_v(&vars);
	valid = get_map_and_validate(&vars, argv);
	vars.win = mlx_new_window(vars.mlx, vars.map.row_len * 50, vars.map.rows * 50, "SpaceCow");
	//vars.player.player = mlx_xpm_file_to_image(vars.mlx, rel_path, &vars.player.player_height, &vars.player.player_width);
	init_images(&vars);
	init_player(&vars);
	//mlx_put_image_to_window(vars.mlx, vars.win, vars.player.player, 0,0);
	looping(vars);
	ft_close(vars);
	//vars.player.player = mlx_xpm_file_to_image(vars.mlx,"./player/courage.xpm", &vars.player.player_width, &vars.player.player_height);
	//load_images(&vars);

	/*while (my_line[i] != '\0')
	{
		mlx_put_image_to_window(vars.mlx, vars.win, vars.player.player, st,0);
		i++;
		st += vars.player.player_height;
	}
	*/
	//mlx_loop_hook(vars.mlx, &handle_no_event, &vars);
	 /* ADDED */
	//mlx_hook(vars.win, 3, 1L<<1, &handle_keyrelease, &vars); /* CHANGED */
	
}