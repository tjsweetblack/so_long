/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: belmiro <belmiro@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 09:51:44 by belmiro           #+#    #+#             */
/*   Updated: 2024/08/21 11:31:53 by belmiro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	move_right(t_game *game, int y, int x)
{
	int	flag;

	flag = end_of_game(game, x + 1, y);
	if ((game->map[y][x + 1] == 'E') && (flag == 0))
	{
		return ;
	}
	end_of_game(game, x + 1, y);
	if (game->map[y][x + 1] != '1')
	{
		game->map[y][x] = '0';
		game->map[y][x + 1] = 'P';
		game->move_count++;
		ft_printf("Moves: %d\n", game->move_count);
	}
}

void	move_left(t_game *game, int y, int x)
{
	int	flag;

	flag = end_of_game(game, x - 1, y);
	if ((game->map[y][x - 1] == 'E') && (flag == 0))
	{
		return ;
	}
	if (game->map[y][x - 1] != '1')
	{
		game->map[y][x] = '0';
		game->map[y][x - 1] = 'P';
		game->move_count++;
		ft_printf("Moves: %d\n", game->move_count);
	}
}

void	move_down(t_game *game, int y, int x)
{
	int	flag;

	flag = end_of_game(game, x, y + 1);
	if ((game->map[y + 1][x] == 'E') && (flag == 0))
	{
		return ;
	}
	end_of_game(game, x, y + 1);
	if (game->map[y + 1][x] != '1')
	{
		game->map[y][x] = '0';
		game->map[y + 1][x] = 'P';
		game->move_count++;
		ft_printf("Moves: %d\n", game->move_count);
	}
}

void	move_up(t_game *game, int y, int x)
{
	int	flag;

	flag = end_of_game(game, x, y - 1);
	if ((game->map[y - 1][x] == 'E') && (flag == 0))
	{
		return ;
	}
	end_of_game(game, x, y - 1);
	if (game->map[y - 1][x] != '1')
	{
		game->map[y][x] = '0';
		game->map[y - 1][x] = 'P';
		game->move_count++;
		ft_printf("Moves: %d\n", game->move_count);
	}
}
