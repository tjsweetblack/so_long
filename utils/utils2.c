/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/18 08:41:38 by belmiro           #+#    #+#             */
/*   Updated: 2024/08/19 11:47:41 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

char	*ft_strrchr(const char *str, int c)
{
	char	*last_occurrence;

	last_occurrence = NULL;
	while (*str)
	{
		if (*str == (char)c)
		{
			last_occurrence = (char *)str;
		}
		str++;
	}
	if (*str == (char)c)
	{
		last_occurrence = (char *)str;
	}
	return (last_occurrence);
}

void	is_valid_map_file(const char *filename)
{
	char	*ext;

	ext = ft_strrchr(filename, '.');
	if (!ext || ft_strcmp(ext, ".ber") != 0)
	{
		write(1, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}

int	ft_forbiden(char **map, int y_count, int x_count)
{
	if (map[y_count][x_count] == 'C'
		|| map[y_count][x_count] == 'P'
		|| map[y_count][x_count] == 'E'
		|| map[y_count][x_count] == '1'
		|| map[y_count][x_count] == '0')
	{
		return (1);
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	size_t	len;

	len = ft_strlen(s1);
	s2 = (char *)malloc(len + 1);
	if ((s2) == NULL)
		return (NULL);
	ft_memcpy(s2, s1, len + 1);
	return (s2);
}
