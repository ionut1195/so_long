/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:13:35 by itomescu          #+#    #+#             */
/*   Updated: 2021/06/21 13:02:29 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	match_body(char *big, char *little, size_t *length)
{
	size_t		len;

	len = *length;
	while (*big && len && *little)
	{
		if (*big == *little)
		{
			big++;
			little++;
			len--;
		}
		else
			return (0);
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		itr;

	itr = 0;
	if (!(*little))
		return ((char *)big);
	if (ft_strlen(big) < ft_strlen(little))
		return (0);
	while (big[itr] != '\0' && len)
	{
		while ((big[itr] != little[0]) && big[itr])
		{
			itr++;
			len--;
			if (len < ft_strlen(little))
				return (0);
		}
		if (big[itr] && match_body(&((char *)big)[itr], (char *)little, &len))
			return (&((char *)big)[itr]);
		else
		{
			len--;
			itr++;
		}	
	}
	return (0);
}
