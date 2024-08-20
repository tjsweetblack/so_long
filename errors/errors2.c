/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:52:58 by belmiro           #+#    #+#             */
/*   Updated: 2024/08/20 05:39:44 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	charector_count_p(char **map, int y_count, int x_count)
{
	char	map_element;
	int		charector_value;

	charector_value = 0;
	while (map[y_count])
	{
		x_count = 0;
		while (map[y_count][x_count])
		{
			map_element = map[y_count][x_count];
			if (map_element == 'P')
				charector_value++;
			x_count++;
		}
		y_count++;
	}
	return (charector_value);
}

int	charector_count_e(char **map, int y_count, int x_count)
{
	char	map_element;
	int		charector_value;

	charector_value = 0;
	while (map[y_count])
	{
		x_count = 0;
		while (map[y_count][x_count])
		{
			map_element = map[y_count][x_count];
			if (map_element == 'E')
				charector_value++;
			x_count++;
		}
		y_count++;
	}
	return (charector_value);
}

int	charector_count_c(char **map, int y_count, int x_count)
{
	char	map_element;
	int		charector_value;

	charector_value = 0;
	while (map[y_count])
	{
		x_count = 0;
		while (map[y_count][x_count])
		{
			map_element = map[y_count][x_count];
			if (map_element == 'C')
				charector_value++;
			x_count++;
		}
		y_count++;
	}
	return (charector_value);
}

int	ft_is_rectangle(char **map, int *size)
{
	int	flag;

	flag = 0;
	if (size[0] == size[1])
	{
		write(1, "Error\n", 6);
		return (0);
	}
	flag = 1;
	if ((flag == 1) && (ft_equal_lines(map, size, 0, 0) == 1))
		return (1);
	return (0);
}
