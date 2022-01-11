/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:32:48 by itomescu          #+#    #+#             */
/*   Updated: 2022/01/11 21:11:14 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/so_long.h"

int	valid_move(t_vars *v, char dir)
{
	if ((dir == 'w' && v->map.map[v->p_r - 1][v->p_c] == '1')
		|| (dir == 'a' && v->map.map[v->p_r][v->p_c - 1] == '1')
		|| (dir == 's' && v->map.map[v->p_r + 1][v->p_c] == '1')
		|| (dir == 'd' && v->map.map[v->p_r][v->p_c + 1] == '1'))
		return (0);
	if ((dir == 'w' && v->map.map[v->p_r - 1][v->p_c] == 'C')
		|| (dir == 'a' && v->map.map[v->p_r][v->p_c - 1] == 'C')
		|| (dir == 's' && v->map.map[v->p_r + 1][v->p_c] == 'C')
		|| (dir == 'd' && v->map.map[v->p_r][v->p_c + 1] == 'C'))
		v->map.collected++;
	if (((dir == 'w' && v->map.map[v->p_r - 1][v->p_c] == 'E')
		|| (dir == 'a' && v->map.map[v->p_r][v->p_c - 1] == 'E')
		|| (dir == 's' && v->map.map[v->p_r + 1][v->p_c] == 'E')
		|| (dir == 'd' && v->map.map[v->p_r][v->p_c + 1] == 'E'))
		&& v->map.collected < v->map.to_collect)
		return (0);
	return (1);
}

int	check_first_last(char *row, int c_r, int t_r)
{
	int	len;
	int	col;

	col = 0;
	len = ft_strlen(row);
	if (c_r < t_r -1)
		len -= 1;
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
			if (!check_first_last(mtx[itr], itr, rows))
				return (0);
		}
		else
		{
			if (mtx[itr][0] != '1' || mtx[itr][ft_strlen(mtx[itr]) - 2] != '1')
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
	else if (chr == 'C')
		(*c)++;
	else if (chr == 'E')
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
