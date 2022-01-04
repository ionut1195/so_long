/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:11:58 by itomescu          #+#    #+#             */
/*   Updated: 2021/06/12 09:12:02 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	cr;
	char	*sp;

	sp = (char *)s;
	cr = (char)c;
	while (*sp)
	{
		if (*sp == cr)
		{
			return (sp);
		}
		sp++;
	}
	if (c == '\0')
		return (sp);
	return (NULL);
}
