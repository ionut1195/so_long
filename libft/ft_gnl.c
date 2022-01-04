/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itomescu <itomescu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 22:50:48 by itomescu          #+#    #+#             */
/*   Updated: 2022/01/03 19:57:44 by itomescu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_rtn(char *line)
{
	int		i;
	char	*rtn;

	i = 0;
	if (!line)
		return (0);
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n')
	{
		rtn = (char *)malloc(sizeof(char) * (i + 2));
		if (!rtn)
			return (0);
		ft_strlcpy(rtn, line, i + 2);
	}
	else
	{
		rtn = (char *)malloc(sizeof(char) * (i + 1));
		if (!rtn)
			return (0);
		ft_strlcpy(rtn, line, i + 1);
	}
	return (rtn);
}

char	*get_remainder(char *line)
{
	int		i;
	int		z;
	int		y;
	char	*rtn;

	if (!line)
		return (0);
	i = 0;
	z = ft_strlen(line);
	y = 0;
	ft_get_newline_index(line, &i);
	if (z == i)
	{
		free(line);
		return (0);
	}
	rtn = (char *)malloc(sizeof(char) * (z - i + 1));
	if (!rtn)
		return (0);
	while (line[i])
		rtn[y++] = line[i++];
	rtn[y] = '\0';
	free(line);
	return (rtn);
}

char	*ft_strjoin_gnl(char const *s1, char const *s2)
{
	char	*ptr;
	int		length;
	int		itr;
	int		i;

	itr = 0;
	i = 0;
	length = ft_strlen(s1) + ft_strlen(s2);
	if (length < 1)
		return (0);
	ptr = (char *)malloc((length * sizeof(char)) + 1);
	if (!ptr)
		return (0);
	if (s1)
	{
		while ((itr < length) && s1[i])
			ptr[itr++] = s1[i++];
	}
	i = 0;
	while ((itr < length) && s2[i])
		ptr[itr++] = s2[i++];
	ptr[itr] = '\0';
	free((char *)s1);
	return (ptr);
}

int	ft_check_and_free(int *reading, char *buf)
{
	if (*reading == -1)
	{
		free(buf);
		return (1);
	}
	return (0);
}

int	ft_gnl(int fd, char **lines)
{
	char		*buffer;
	int			reading;
	static char	*line;

	reading = 1;
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (0);
	while (!ft_has_newline(line) && reading != 0)
	{
		reading = read(fd, buffer, BUFFER_SIZE);
		if (ft_check_and_free(&reading, buffer))
			return (0);
		if (reading == 0)
			break ;
		buffer[reading] = '\0';
		line = ft_strjoin_gnl(line, buffer);
	}
	free(buffer);
	*lines = get_rtn(line);
	line = get_remainder(line);
	if (line)
		return (1);
	return (0);
}
