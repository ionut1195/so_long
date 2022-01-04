/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:10:01 by itomescu          #+#    #+#             */
/*   Updated: 2021/06/18 14:18:47 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*sp;
	unsigned char	cp;

	sp = (unsigned char *)s;
	cp = (unsigned char)c;
	while (n)
	{
		if (*sp == cp)
		{
			return (sp);
		}
		n--;
		sp++;
	}
	return (0);
}
