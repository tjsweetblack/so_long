/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:44:56 by badriano          #+#    #+#             */
/*   Updated: 2024/08/19 06:11:29 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_map_error(char **map, int *size)
{
	if ((ft_is_rectangle(map, size) == 1) && (is_map_playable(map) == 1))
	{
		return (1);
	}
	else
	{
		free_map(map);
		free(size);
		exit(0);
	}
}
