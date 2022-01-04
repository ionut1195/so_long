/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:10:31 by itomescu          #+#    #+#             */
/*   Updated: 2021/06/12 10:08:06 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dp;
	unsigned char	*sp;
	size_t			itr;

	if (dest == NULL && src == NULL)
		return (NULL);
	itr = 0;
	sp = (unsigned char *)src;
	dp = (unsigned char *)dest;
	if (dest < src)
	{
		while (itr < n)
		{
			dp[itr] = sp[itr];
			itr++;
		}
	}	
	else
	{
		while (n--)
			dp[n] = sp[n];
	}
	return (dest);
}
