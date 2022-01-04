/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:12:29 by itomescu          #+#    #+#             */
/*   Updated: 2021/06/13 12:46:10 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		length;
	int		itr;

	itr = 0;
	length = ft_strlen(s1) + ft_strlen(s2);
	ptr = (char *)malloc((length * sizeof(char)) + 1);
	if (!ptr)
		return (0);
	while ((itr < length) && *s1)
	{
		ptr[itr] = *s1;
		itr++;
		s1++;
	}
	while ((itr < length) && *s2)
	{
		ptr[itr] = *s2;
		itr++;
		s2++;
	}
	ptr[itr] = '\0';
	return (ptr);
}
