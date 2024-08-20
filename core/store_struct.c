/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:38:47 by belmiro           #+#    #+#             */
/*   Updated: 2024/08/19 12:34:40 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	store_player_image(t_game *game)
{
	int	size;

	size = 100;
	game->image.player[0] = mlx_xpm_file_to_image(game->init,
			"./assets/bird.xpm", &size, &size);
	game->image.player[1] = mlx_xpm_file_to_image(game->init,
			"./assets/bird_sprite/1.xpm", &size, &size);
	game->image.player[2] = mlx_xpm_file_to_image(game->init,
			"./assets/bird_sprite/2.xpm", &size, &size);
	game->image.player[3] = mlx_xpm_file_to_image(game->init,
			"./assets/bird_sprite/3.xpm", &size, &size);
	game->image.player[4] = mlx_xpm_file_to_image(game->init,
			"./assets/bird_sprite/4.xpm", &size, &size);
	game->image.player[5] = mlx_xpm_file_to_image(game->init,
			"./assets/bird_sprite/5.xpm", &size, &size);
	game->image.player[6] = mlx_xpm_file_to_image(game->init,
			"./assets/bird_sprite/6.xpm", &size, &size);
	game->image.player[7] = mlx_xpm_file_to_image(game->init,
			"./assets/bird_sprite/7.xpm", &size, &size);
}

void	store_to_struct(t_game *game)
{
	int	size;

	size = 100;
	game->move_count = 0;
	game->frame_count = 0;
	game->current_frame = 0;
	store_player_image(game);
	game->image.background = mlx_xpm_file_to_image(game->init,
			"./assets/background.xpm", &size, &size);
	game->image.exit = mlx_xpm_file_to_image(game->init,
			"./assets/door.xpm", &size, &size);
	game->image.wall = mlx_xpm_file_to_image(game->init,
			"./assets/wall.xpm", &size, &size);
	game->image.coin = mlx_xpm_file_to_image(game->init,
			"./assets/coin.xpm", &size, &size);
}
