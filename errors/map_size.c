/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:14:21 by badriano          #+#    #+#             */
/*   Updated: 2024/08/19 06:57:59 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	*ft_map_size(char **map)
{
	int	y;
	int	x;
	int	i;
	int	*size;

	y = 0;
	x = 0;
	i = 0;
	size = malloc (sizeof(int) * 3);
	size[0] = 0;
	size[1] = 0;
	size[2] = 0;
	if (!size)
		write(1, "no map size", 11);
	while (map[y] != NULL)
		y++;
	i = 0;
	while (map[i][x] != '\0')
		x++;
	size[0] = y;
	size[1] = x;
	return (size);
}
