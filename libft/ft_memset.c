/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:10:47 by itomescu          #+#    #+#             */
/*   Updated: 2021/06/18 14:26:20 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			itr;

	itr = 0;
	p = (unsigned char *)s;
	while (itr < n)
	{
		p[itr] = (unsigned char)c;
		itr++;
	}
	return (p);
}
