/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_newline_index.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/02 15:21:12 by itomescu          #+#    #+#             */
/*   Updated: 2022/01/02 15:22:52 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_get_newline_index(char *line, int *index)
{
	while (line[*index] && line[*index] != '\n')
		(*index)++;
	if (line[*index] == '\n')
		(*index)++;
}
