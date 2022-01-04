/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:14:04 by itomescu          #+#    #+#             */
/*   Updated: 2021/06/21 13:02:47 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_start(const char *st, const char *set)
{
	size_t		start;
	size_t		set_itr;

	start = 0;
	while (*st)
	{
		set_itr = 0;
		while (set[set_itr])
		{
			if (set[set_itr] != *st)
				set_itr++;
			else
			{
				start++;
				break ;
			}
		}
		if (set[set_itr] == '\0')
			break ;
		st++;
	}
	return (start);
}

static size_t	get_end(const char *st, const char *set)
{
	size_t		end;
	size_t		set_itr;
	size_t		result;

	result = 0;
	end = ft_strlen(st) - 1;
	while (st[end])
	{
		set_itr = 0;
		while (set[set_itr])
		{
			if (set[set_itr] != st[end])
				set_itr++;
			else
			{
				end--;
				result++;
				break ;
			}
		}
		if (set[set_itr] == '\0')
			break ;
	}
	return (result);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char		*ptr;
	size_t		i;
	size_t		size;
	size_t		start;
	size_t		end;

	start = get_start(s1, set);
	if (start == ft_strlen(s1))
		end = 0;
	else
		end = get_end(&s1[start], set);
	size = ft_strlen(s1) - start - end;
	ptr = (char *)malloc(sizeof(char) * (size + 1));
	i = 0;
	if (!s1)
		return (0);
	if (!ptr)
		return (0);
	while (i < size)
		ptr[i++] = s1[start++];
	ptr[i] = '\0';
	return (ptr);
}
