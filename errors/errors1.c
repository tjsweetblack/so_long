/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:50:34 by belmiro           #+#    #+#             */
/*   Updated: 2024/08/19 06:44:22 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_number_of_elements(char **map)
{
	int	map_p_value;
	int	map_c_value;
	int	map_e_value;

	map_c_value = charector_count_c(map, 0, 0);
	map_e_value = charector_count_e(map, 0, 0);
	map_p_value = charector_count_p(map, 0, 0);
	if (map_p_value != 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (map_c_value < 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (map_e_value != 1)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	return (1);
}

int	ft_forbiden_elements(char **map, int y_count, int x_count)
{
	int	flag;

	flag = 0;
	while (map[y_count])
	{
		x_count = 0;
		while (map[y_count][x_count])
		{
			if ((ft_forbiden(map, y_count, x_count)) == 1)
			{
				x_count++;
			}
			else
			{
				write(1, "Error\n", 6);
				return (0);
			}
		}
		y_count++;
	}
	flag = 1;
	if ((flag == 1) && (ft_number_of_elements(map) == 1))
		return (1);
	return (0);
}

int	ft_first_and_last_line(char **map, int x_count)
{
	int	flag;

	flag = 0;
	while (map[0][x_count])
	{
		if (map[0][x_count] != '1')
		{
			write(1, "Error\n", 6);
			return (0);
		}
		x_count++;
	}
	flag = 1;
	if ((flag == 1) && (ft_forbiden_elements(map, 0, 0) == 1))
		return (1);
	return (0);
}

int	ft_first_and_last(char **map, int *size, int y_count)
{
	int	flag;

	flag = 0;
	while (map[y_count])
	{
		if (map[y_count][0] != '1')
		{
			write(1, "Error\n", 6);
			return (0);
		}
		if (map[y_count][size[1] - 1] != '1')
		{
			write(1, "Error\n", 6);
			return (0);
		}
		y_count++;
	}
	flag = 1;
	if ((flag == 1) && (ft_first_and_last_line(map, 0) == 1))
		return (1);
	return (0);
}

int	ft_equal_lines(char **map, int *size, int y_count, int x_count)
{
	int	flag;

	flag = 0;
	while (map[y_count] != NULL)
	{
		x_count = 0;
		while (map[y_count][x_count] != '\0')
			x_count++;
		if (x_count < size[1])
		{
			write(1, "Error\n", 6);
			return (0);
		}
		else if (x_count != size[1])
		{
			write(1, "Error\n", 6);
			return (0);
		}
		y_count++;
	}
	flag = 1;
	if ((flag == 1) && (ft_first_and_last(map, size, 0) == 1))
		return (1);
	return (0);
}
