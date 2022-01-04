/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:13:25 by itomescu          #+#    #+#             */
/*   Updated: 2021/06/12 09:13:25 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1c;
	unsigned char	*s2c;

	s1c = (unsigned char *)s1;
	s2c = (unsigned char *)s2;
	while (*s1c || *s2c)
	{
		if (n > 0)
		{	
			if (*s1c != *s2c)
			{
				return (*s1c - *s2c);
			}
			s1c++;
			s2c++;
			n--;
		}
		else
			break ;
	}
	return (0);
}
