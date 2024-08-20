/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 08:02:58 by belmiro           #+#    #+#             */
/*   Updated: 2024/08/19 11:40:44 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	free_images(t_game *game)
{
	int	i;

	i = 0;
	mlx_destroy_image(game->init, game->image.background);
	mlx_destroy_image(game->init, game->image.coin);
	mlx_destroy_image(game->init, game->image.exit);
	mlx_destroy_image(game->init, game->image.wall);
	while (i < 8)
	{
		mlx_destroy_image(game->init, game->image.player[i]);
		i++;
	}
}

void	free_game_resources(t_game *game)
{
	int	i;

	if (game->map)
	{
		i = 0;
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
	free_images(game);
	if (game->window)
	{
		mlx_destroy_window(game->init, game->window);
	}
	if (game->init)
	{
		mlx_destroy_display(game->init);
		free(game->init);
	}
}
