/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:12:39 by itomescu          #+#    #+#             */
/*   Updated: 2021/06/21 12:58:15 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	counter;
	size_t	dst_len;
	size_t	src_len;
	size_t	itr;

	itr = 0;
	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	counter = dst_len;
	itr = 0;
	if (counter < dstsize)
	{
		while (src[itr] != '\0')
		{
			if (counter == dstsize - 1)
				break ;
			dst[counter] = src[itr];
			itr++;
			counter++;
		}
		dst[counter] = '\0';
		return (dst_len + src_len);
	}
	return (dstsize + src_len);
}
