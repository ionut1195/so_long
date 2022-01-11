/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 16:13:59 by itomescu          #+#    #+#             */
/*   Updated: 2022/01/11 21:11:13 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

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
	ft_exit(v);
	v->map.map[v->p_r][v->p_c] = 'P';
	v->moves++;
}

void	looping(t_vars vars)
{
	if (vars.win != NULL)
	{
		mlx_loop_hook(vars.mlx, &print_map, &vars);
		mlx_hook(vars.win, 2, 1L << 0, &handle_keypress, &vars);
		mlx_hook(vars.win, 33, 1L << 5, &handle_btnrealease, &vars);
		mlx_loop(vars.mlx);
	}
}

int	check_extension(char *file)
{
	int len;
	int	i;
	char	ext[5];

	i = 0;
	len = ft_strlen(file) - 4;
	while (file[len] != '\0')
		ext[i++] = file[len++];
	ext[i] = '\0';
	if (ft_strncmp(ext, ".ber", 4) != 0)
	{
		printf("Error\nWrong file extension. Please use a \".ber\" file!");
		return (0);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;
	int		valid;

	if (argc <= 1 || (!check_extension(argv[1])))
		return (-1);
	vars.mlx = mlx_init();
	init_v(&vars);
	valid = get_map_and_validate(&vars, argv);
	if (valid)
	{
	vars.win = mlx_new_window(vars.mlx, vars.map.row_len
		* 50, vars.map.rows * 50, "SpaceCow");
	init_images(&vars);
	init_plr_col(&vars);
	looping(vars);
	ft_close(vars);
	if (vars.map.map)
		free(vars.map.map);
	return (0);
	}
	else
		printf("Error\nInvalid Map!");
}
