/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/03 18:24:37 by itomescu          #+#    #+#             */
/*   Updated: 2022/01/09 13:44:15 by itomescu         ###   ########.fr       */
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

int	print_map(t_vars vars, t_vars *v)
{
	int	col;
	int	row;

	row = 0;
	while (vars.map.map[row] != NULL)
	{
		col = 0;
		while (vars.map.map[row][col] != '\n' && vars.map.map[row][col] != '\0')
		{
			if (vars.map.map[row][col] == '1')
			{
				print_wall(vars, row, col);
				col++;
			}
			else
			{
				print_floor(vars, row, col);
				if (vars.map.map[row][col] == 'P')
				{
					print_player(vars, row, col);
					v->py = row;
					v->px = col;
				}
				else if (vars.map.map[row][col] == 'C')
					print_collectible(vars, row, col);
				else if (vars.map.map[row][col] == 'E')
					print_exit(vars, row, col);
				col++;
			}
		}
		row++;
	}

	return (1);
}
