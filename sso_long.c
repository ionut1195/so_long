/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sso_long.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:13:59 by itomescu          #+#    #+#             */
/*   Updated: 2022/01/09 13:49:18 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int	ft_free(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->wall.img);
	mlx_destroy_image(vars->mlx, vars->player.img);
	mlx_destroy_image(vars->mlx, vars->floor.img);
	mlx_destroy_image(vars->mlx, vars->exit.img);
	mlx_destroy_image(vars->mlx, vars->food.img);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->map.map);
	if (vars->mlx)
		free(vars->mlx);
	return (0);

}

void	print_collectible(t_vars vars, int row, int col)
{
	vars.food.img = mlx_xpm_file_to_image(vars.mlx,"./img/food.xpm", &vars.food.img_w, &vars.food.img_h);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.food.img,(vars.food.img_w * 2 * col), (vars.food.img_h * 2 * row));
}

void	print_player(t_vars vars, int row, int col)
{
	vars.player.img = mlx_xpm_file_to_image(vars.mlx,"./img/courage.xpm", &vars.player.img_w, &vars.player.img_h);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.player.img,(vars.player.img_w * col), (vars.player.img_h * row));
}

void	print_exit(t_vars vars, int row, int col)
{
	vars.exit.img = mlx_xpm_file_to_image(vars.mlx,"./img/exit.xpm", &vars.exit.img_w, &vars.exit.img_h);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.exit.img,(vars.exit.img_w * col), (vars.exit.img_h * row));
}

void	print_wall(t_vars vars, int row, int col)
{
	vars.wall.img = mlx_xpm_file_to_image(vars.mlx,"./img/brick_wall.xpm", &vars.wall.img_w, &vars.wall.img_h);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.wall.img,(vars.wall.img_w * col), (vars.wall.img_h * row));
}

void	print_floor(t_vars vars, int row, int col)
{
	vars.floor.img = mlx_xpm_file_to_image(vars.mlx,"./img/floor.xpm", &vars.floor.img_w, &vars.floor.img_h);
	mlx_put_image_to_window(vars.mlx, vars.win, vars.floor.img,(vars.floor.img_w * col), (vars.floor.img_h * row));
}

// void	loop(t_vars vars)
// {
// 	mlx_loop_hook(vars.mlx, &print_map, &vars);

// }

void	move_player(t_vars vars)
{
	mlx_destroy_image(vars.mlx, vars.player.img);
	print_player(vars, vars.py,vars.px + 1);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	int		valid;
	
	if (argc <= 1)
		return (-1);
	vars.mlx = mlx_init();
	
	//rel_path =  "./img/brick_wall.xpm";
	valid = get_map_and_validate(&vars, argv);
	vars.win = mlx_new_window(vars.mlx, vars.map.row_len * 50, vars.map.rows * 50, "SpaceCow");
	//vars.img.img = mlx_xpm_file_to_image(vars.mlx, rel_path, &vars.img.img_height, &vars.img.img_width);
	//init_images(vars);
	//mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, 0,0);
	if (valid)
		print_map(vars, &vars);
	//vars.img.player = mlx_xpm_file_to_image(vars.mlx,"./img/courage.xpm", &vars.img.img_width, &vars.img.img_height);
	//load_images(&vars);

	/*while (my_line[i] != '\0')
	{
		mlx_put_image_to_window(vars.mlx, vars.win, vars.img.img, st,0);
		i++;
		st += vars.img.img_height;
	}
	*/
	mlx_hook(vars.win, 2, 1L<<0, ft_free, &vars);
	//move_player(vars);
	mlx_loop(vars.mlx);
}