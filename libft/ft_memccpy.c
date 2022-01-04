/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:09:46 by itomescu          #+#    #+#             */
/*   Updated: 2021/06/12 09:09:50 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int	i;
	char			*dest_copy;
	char			*src_copy;
	char			*ptr;

	dest_copy = (char *)dest;
	src_copy = (char *)src;
	i = 0;
	ptr = 0;
	while (i < n && ptr == 0)
	{
		dest_copy[i] = src_copy[i];
		if (src_copy[i] == ((char)c))
			ptr = dest + i + 1;
		i++;
	}
	return (ptr);
}
