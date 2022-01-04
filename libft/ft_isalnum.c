/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:08:25 by itomescu          #+#    #+#             */
/*   Updated: 2021/06/12 09:08:29 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	unsigned int	i;

	i = (unsigned int)c;
	if (48 <= i && i <= 57)
		return (1);
	else if (65 <= i && i <= 90)
		return (1);
	else if (97 <= i && i <= 122)
		return (1);
	return (0);
}
