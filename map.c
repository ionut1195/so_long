/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:24:37 by itomescu          #+#    #+#             */
/*   Updated: 2022/01/09 20:13:28 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_nr_lines(char *argv[])
{
	char	*line;
	int		itr;
	int		fd;
	int		n;

	itr = 0;
	n = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (-1);
	else
	{
		ft_gnl(fd, &line);
		while (line != NULL)
		{
			n++;
			free(line);
			ft_gnl(fd, &line);
		}
		close(fd);
	}
	return (n);
}

int	check_first_last(char *row)
{
	int	len;
	int	col;

	col = 0;
	len = ft_strlen(row) - 1;
	while (col < len)
	{
		if (row[col] != '1')
			return (0);
		col++;
	}
	return (1);
}

int	valid_walls(char *mtx[])
{
	int	rows;
	int	col;
	int	itr;

	itr = 0;
	rows = 0;
	while (mtx[rows] != NULL)
		rows++;
	while (itr < rows)
	{
		col = 0;
		if ((itr == 0) || (itr == rows - 1))
		{
			if (!check_first_last(mtx[itr]))
				return (0);
		}
		else
		{
			if (mtx[itr][0] != '1' || mtx[itr][ft_strlen(mtx[0]) - 2] != '1')
				return (0);
		}
		itr++;
	}
	return (1);
}
void	is_pec(char chr, int *p, int *e, int *c)
{
	if (chr == 'P')
		(*p)++;
	else if (chr  == 'C')
		(*c)++;
	else if (chr  == 'E')
		(*e)++;
}

int	has_p_e_c(char *mtx[], int rows)
{
	int	p;
	int	c;
	int	e;
	int	row;
	int	col;

	p = 0;
	c = 0;
	e = 0;
	row = 1;
	while (mtx[row] != NULL && row < rows)
	{
		col = 1;
		while (col < (int)(ft_strlen(mtx[0]) - 2))
		{
			is_pec(mtx[row][col], &p, &e, &c);
			col++;
		}
		row++;
	}
	if (p > 0 && c > 0 && e > 0)
		return (1);
	return (0);
}

int	get_map_and_validate(t_vars *vars, char *argv[])
{
	int	map_fd;
	int	lines;

	lines = get_nr_lines(argv);
	vars->map.rows = 0;
	map_fd = open(argv[1], O_RDONLY);
	vars->map.map = (char **)malloc((lines + 1) * sizeof(char **));
	if (map_fd)
		while (ft_gnl(map_fd, &vars->map.map[vars->map.rows]))
			vars->map.rows++;
	vars->map.rows++;
	vars->map.row_len = ft_strlen(vars->map.map[0]) - 1;
	vars->map.map[vars->map.rows] = NULL;
	close(map_fd);
	if (valid_walls(vars->map.map) && has_p_e_c(vars->map.map, vars->map.rows))
		return (1);
	return (0);
}

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

void	init_player(t_vars *v)
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
			c++;
		}
		r++;
	}
}

void	print_element(char elem, t_vars *vars, int col, int row)
{
	if (elem == '1')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->wall.img, (col * 50), (row * 50));
	else if (elem == '0')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->floor.img, (col * 50), (row * 50));
	else if (elem == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->exit.img, (col * 50), (row * 50));
	else if (elem == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->food.img, (col * 50), (row * 50));
	else if (elem == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win, vars->player.img, (col * 50), (row * 50));
}

int	print_map(t_vars *vars)
{
	int		col;
	int		row;
	char	elem;

	row = 0;
	while (vars->map.map[row] != NULL)
	{
		col = 0;
		
		while (vars->map.map[row][col] != '\n' && vars->map.map[row][col] != '\0')
		{
			elem = vars->map.map[row][col];
			print_element(elem, vars, col, row);
			col++;
		}
		row++;
	}
	return (0);
}
