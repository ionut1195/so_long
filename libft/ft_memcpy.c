/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:10:23 by itomescu          #+#    #+#             */
/*   Updated: 2021/06/18 14:22:35 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const unsigned char	*src_copy;
	unsigned char		*dest_copy;

	dest_copy = dest;
	src_copy = src;
	while (n)
	{
		*dest_copy = *src_copy;
		dest_copy++;
		src_copy++;
		n--;
	}
	return (dest);
}
