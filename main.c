/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 11:28:16 by badriano          #+#    #+#             */
/*   Updated: 2024/08/20 06:36:40 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/so_long.h"

int	ft_close_game(t_game *game)
{
	close_game(game);
	return (0);
}

void	start_game(t_game *game, int *size)
{
	int	y;
	int	x;

	y = size[0];
	x = size[1];
	free(size);
	game->window = mlx_new_window (game->init,
			x * 100,
			y * 100,
			"So_long");
	store_to_struct(game);
	mlx_loop_hook(game->init, render_loop, game);
	mlx_hook(game->window, 2, 1L << 0, move_player, game);
	mlx_hook(game->window, 17, 0L, ft_close_game, game);
	mlx_loop(game->init);
}

void	check_empty_map(char **map)
{
	if (!map || !map[0])
	{
		write(1, "Error\nempty file!", 17);
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	int		fd;
	char	**map;
	int		*size;
	t_game	game;

	if (argc == 2)
	{
		is_valid_map_file(argv[1]);
		fd = open(argv[1], O_RDONLY);
		map = ft_get_map(fd);
		check_empty_map(map);
		size = ft_map_size(map);
		if (ft_check_map_error(map, size) == 1)
		{
			game.map = map;
			game.init = mlx_init();
			start_game(&game, size);
		}
	}
	else
	{
		write(1, "Error\n wrong format", 19);
	}
	return (0);
}
