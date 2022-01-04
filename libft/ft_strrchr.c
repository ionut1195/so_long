/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:13:52 by itomescu          #+#    #+#             */
/*   Updated: 2021/06/21 12:58:42 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_last_index(const char *s, int c)
{
	unsigned char	*sp;
	int				itr;
	int				last_seen;

	sp = (unsigned char *)s;
	itr = 0;
	last_seen = -1;
	while (*sp)
	{
		if (*sp == (unsigned char)c)
			last_seen = itr;
		itr++;
		sp++;
	}
	return (last_seen);
}

char	*ft_strrchr(const char *s, int c)
{
	char	*sp;
	int		index;

	sp = (char *)s;
	if (c == '\0')
	{
		while (*sp != '\0')
			sp++;
		return (sp);
	}
	index = get_last_index(s, c);
	if (index >= 0)
		return (&sp[index]);
	return (NULL);
}
