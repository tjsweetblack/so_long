/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/13 13:04:56 by belmiro           #+#    #+#             */
/*   Updated: 2024/08/19 12:08:48 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_render_player(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->init,
		game->window,
		game->image.player[game->current_frame], x * 100, y * 100);
	game->frame_count++;
	if (game->frame_count == 400)
	{
		game->current_frame++;
		if (game->current_frame >= 8)
			game->current_frame = 0;
		game->frame_count = 0;
	}
}

void	ft_render(t_game *game, int y, int x)
{
	if (game->map[y][x] == 'P')
	{
		ft_render_player(game, x, y);
	}
	else if (game->map[y][x] == '0')
	{
		mlx_put_image_to_window(game->init,
			game->window, game->image.background, x * 100, y * 100);
	}
	else if (game->map[y][x] == 'E')
	{
		mlx_put_image_to_window(game->init,
			game->window, game->image.exit, x * 100, y * 100);
	}
	else if (game->map[y][x] == '1')
	{
		mlx_put_image_to_window(game->init,
			game->window, game->image.wall, x * 100, y * 100);
	}
	else if (game->map[y][x] == 'C')
	{
		mlx_put_image_to_window(game->init,
			game->window, game->image.coin, x * 100, y * 100);
	}
}

int	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			ft_render(game, y, x);
			x++;
		}
		y++;
	}
	return (0);
}

int	render_loop(t_game *game)
{
	render_map(game);
	return (0);
}
