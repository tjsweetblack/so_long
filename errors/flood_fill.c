/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 12:02:37 by belmiro           #+#    #+#             */
/*   Updated: 2024/08/21 11:47:25 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	*ft_find_player(char **map, int *pos)
{
	int	y;
	int	x;

	y = 0;
	while (map[y] != NULL)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (map[y][x] == 'P')
				break ;
			(x)++;
		}
		if (map[y][x] == 'P')
			break ;
		(y)++;
	}
	pos[0] = y;
	pos[1] = x;
	return (pos);
}

void	ft_flood_fill(char **map, int *pos, int *coins_found)
{
	int	new_pos[2];

	if (map[pos[0]][pos[1]] == '1'
		|| map[pos[0]][pos[1]] == 'V'
		|| map[pos[0]][pos[1]] == 'E')
		return ;
	if (map[pos[0]][pos[1]] == 'C')
		(*coins_found)++;
	map[pos[0]][pos[1]] = 'V';
	new_pos[0] = pos[0] - 1;
	new_pos[1] = pos[1];
	ft_flood_fill(map, new_pos, coins_found);
	new_pos[0] = pos[0] + 1;
	new_pos[1] = pos[1];
	ft_flood_fill(map, new_pos, coins_found);
	new_pos[0] = pos[0];
	new_pos[1] = pos[1] - 1;
	ft_flood_fill(map, new_pos, coins_found);
	new_pos[0] = pos[0];
	new_pos[1] = pos[1] + 1;
	ft_flood_fill(map, new_pos, coins_found);
}

void	flood_fill(char **map, int *pos, int *exit_found)
{
	int		new_pos[2];

	if (map[pos[0]][pos[1]] == '1' || map[pos[0]][pos[1]] == 'V')
		return ;
	if (map[pos[0]][pos[1]] == 'E')
		(*exit_found) = 1;
	map[pos[0]][pos[1]] = 'V';
	new_pos[0] = pos[0] - 1;
	new_pos[1] = pos[1];
	flood_fill(map, new_pos, exit_found);
	new_pos[0] = pos[0] + 1;
	new_pos[1] = pos[1];
	flood_fill(map, new_pos, exit_found);
	new_pos[0] = pos[0];
	new_pos[1] = pos[1] - 1;
	flood_fill(map, new_pos, exit_found);
	new_pos[0] = pos[0];
	new_pos[1] = pos[1] + 1;
	flood_fill(map, new_pos, exit_found);
}

int	ft_total_coins(char **map)
{
	int	total_coins;
	int	y;
	int	x;

	total_coins = 0;
	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C')
				total_coins++;
			x++;
		}
		y++;
	}
	return (total_coins);
}

int	is_map_playable(char **map)
{
	int		coins_found;
	int		exit_found;
	int		total_coins;
	char	**map_copy;
	int		*pos;

	coins_found = 0;
	exit_found = 0;
	map_copy = copy_map(map);
	total_coins = ft_total_coins(map);
	pos = (int *) malloc(sizeof(int) * 2);
	pos = ft_find_player(map, pos);
	ft_flood_fill(map_copy, pos, &coins_found);
	free_map(map_copy);
	map_copy = copy_map(map);
	flood_fill(map_copy, pos, &exit_found);
	free_map(map_copy);
	free(pos);
	if (coins_found == total_coins && exit_found)
		return (1);
	else
		write(1, "Error\n", 6);
	return (0);
}
