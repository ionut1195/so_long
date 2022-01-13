/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:24:37 by itomescu          #+#    #+#             */
/*   Updated: 2022/01/13 13:33:21 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

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

int	is_rectangle(t_vars v)
{
	int	i;
	int	len;

	i = 1;
	while (i < v.map.rows)
	{
		len = (int)ft_strlen(v.map.map[i]);
		if (i < v.map.rows - 1)
			len -= 1;
		if (len != v.map.row_len)
			return (0);
		i++;
	}
	return (1);
}

int	get_map_and_validate(t_vars *vars, char *argv[])
{
	int	map_fd;
	int	lines;

	lines = get_nr_lines(argv);
	vars->map.rows = 0;
	map_fd = open(argv[1], O_RDONLY);
	if (map_fd < 0)
		return (0);
	vars->map.map = (char **)malloc((lines + 1) * sizeof(char **));
	while (ft_gnl(map_fd, &vars->map.map[vars->map.rows]))
		vars->map.rows++;
	vars->map.rows++;
	vars->map.row_len = ft_strlen(vars->map.map[0]) - 1;
	vars->map.map[vars->map.rows] = NULL;
	close(map_fd);
	if (valid_walls(vars->map.map) && has_p_e_c(vars->map.map, vars->map.rows)
		&& is_rectangle(*vars) && valid_char(vars->map.map, vars->map.rows))
		return (1);
	return (0);
}

void	print_element(char elem, t_vars *vars, int col, int row)
{
	if (elem == '1')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->wall.img, (col * 60), (row * 60));
	else if (elem == '0')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->floor.img, (col * 60), (row * 60));
	else if (elem == 'E')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->exit.img, (col * 60), (row * 60));
	else if (elem == 'C')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->food.img, (col * 60), (row * 60));
	else if (elem == 'P')
		mlx_put_image_to_window(vars->mlx, vars->win,
			vars->player.img, (col * 60), (row * 60));
}

int	print_map(t_vars *vars)
{
	int		col;
	int		row;
	char	elem;

	row = 0;
	if (vars->win == NULL)
		return (1);
	while (vars->map.map[row] != NULL)
	{
		col = 0;
		while (vars->map.map[row][col] != '\n'
			&& vars->map.map[row][col] != '\0')
		{
			elem = vars->map.map[row][col];
			print_element(elem, vars, col, row);
			col++;
		}
		row++;
	}
	return (0);
}
