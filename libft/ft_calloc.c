/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:07:32 by itomescu          #+#    #+#             */
/*   Updated: 2021/06/18 14:30:51 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	char	*pt;
	size_t	s;

	s = nmemb * size;
	pt = (char *)malloc(s);
	if (!pt)
		return (NULL);
	ptr = pt;
	while (s)
	{
		*pt = 0;
		pt++;
		s--;
	}
	return (ptr);
}
