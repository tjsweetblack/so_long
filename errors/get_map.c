/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:35:21 by badriano          #+#    #+#             */
/*   Updated: 2024/08/20 06:06:06 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*left_str(char *chars_read, char *buf, int fd)
{
	int	bytes_read;

	bytes_read = 1;
	while (bytes_read != 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		chars_read = ft_strjoin(chars_read, buf);
		if (bytes_read == 0)
			break ;
	}
	return (chars_read);
}

char	**ft_get_map(int fd)
{
	char	buf[BUFFER_SIZE + 1];
	char	*chars_read;
	char	**matrix;

	if (fd < 0)
	{
		write(1, "Error\nfile does not exits", 25);
		exit(0);
	}
	chars_read = NULL;
	chars_read = left_str(chars_read, buf, fd);
	if (!chars_read || chars_read[0] == '\0')
	{
		free(chars_read);
		return (NULL);
	}
	matrix = ft_split(chars_read, '\n');
	free(chars_read);
	return (matrix);
}
