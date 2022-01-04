/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:12:13 by itomescu          #+#    #+#             */
/*   Updated: 2021/06/12 10:53:16 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	length;
	char	*duplicate;
	size_t	iterator;

	length = ft_strlen(s) + 1;
	iterator = 0;
	duplicate = (char *)malloc(length);
	if (!duplicate)
		return (NULL);
	while (iterator < length)
	{
		duplicate[iterator] = s[iterator];
		iterator++;
	}
	return (duplicate);
}
