/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/12 09:11:47 by itomescu          #+#    #+#             */
/*   Updated: 2021/06/21 13:52:08 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static char	**ft_free(char **str_arr, int i)
{
	int	j;

	j = 0;
	while (j < i && str_arr[j] != 0)
	{
		free (str_arr[j]);
		j++;
	}
	free (str_arr);
	return (0);
}

static size_t	ft_words(char const *s, char c)
{
	size_t	words;
	size_t	i;

	i = 0;
	words = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		if (s[i] != c)
			words++;
		while (s[i] != c && s[i + 1])
			i++;
		i++;
	}
	return (words);
}

static size_t	word_length(const char *s, char c)
{
	size_t	len;
	size_t	itr;

	itr = 0;
	len = 0;
	while (s[itr] == c)
		itr++;
	while ((s[itr] != c) && (s[itr] != '\0'))
	{	
		len++;
		itr++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**sp;
	size_t	w;
	size_t	itr;
	size_t	k;

	itr = 0;
	k = 0;
	sp = (char **)malloc((sizeof(char *) * (ft_words(s, c) + 1)));
	if (!sp || s == 0)
		return (0);
	while (itr < ft_words(s, c))
	{
		sp[itr] = (char *)malloc(sizeof(char) * (word_length(&s[k], c) + 1));
		if (!sp[itr])
			return (ft_free(sp, itr));
		w = 0;
		while (s[k] == c)
			k++;
		while (s[k] != c && s[k])
			sp[itr][w++] = s[k++];
		sp[itr][w] = '\0';
		itr++;
	}
	sp[itr] = 0;
	return (sp);
}
