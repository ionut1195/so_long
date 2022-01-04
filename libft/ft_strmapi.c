/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:13:15 by itomescu          #+#    #+#             */
/*   Updated: 2021/06/12 09:13:16 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*dst;
	unsigned int	itr;
	char			*sc;

	sc = (char *)s;
	dst = (char *)malloc((ft_strlen(s) + 1));
	if (!dst)
		return (NULL);
	itr = 0;
	while (sc[itr] != '\0')
	{
		dst[itr] = f(itr, sc[itr]);
		itr++;
	}
	dst[itr] = '\0';
	return (dst);
}
