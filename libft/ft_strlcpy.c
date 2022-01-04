/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:12:56 by itomescu          #+#    #+#             */
/*   Updated: 2022/01/02 15:27:35 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	itr;

	if (!dst)
		return (0);
	if (!size)
		return (ft_strlen(src));
	itr = 0;
	while ((itr < size - 1) && src[itr])
	{
		dst[itr] = src[itr];
		itr++;
	}
	dst[itr] = '\0';
	return (ft_strlen(src));
}
