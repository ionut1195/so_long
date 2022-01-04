/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:14:14 by itomescu          #+#    #+#             */
/*   Updated: 2021/06/21 15:41:58 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	itr;
	char	*sc;

	itr = 0;
	sc = (char *)s;
	ptr = (char *)malloc(len + 1);
	if (start > ft_strlen(s))
	{
		ptr[0] = '\0';
		return (ptr);
	}
	if (!ptr)
		return (0);
	while (itr < len && sc[start])
	{
		ptr[itr] = sc[start];
		itr++;
		start++;
	}
	ptr[itr] = '\0';
	return (ptr);
}
