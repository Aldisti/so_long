/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:25:25 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/24 10:38:48 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

// W:13 A:0 S:1 D:2 Up:126 Dw:125 Lt:123 Rt:124 Esc:53
int	ft_key_hook(int key, t_game *game)
{
	if (key == 13 || key == 126)
		return (ft_up(game, &game->pg, game->map.size));
	else if (key == 1 || key == 125)
		return (ft_down(game, &game->pg, game->map.size));
	else if (key == 0 || key == 123)
		return (ft_left(game, &game->pg, game->map.size));
	else if (key == 2 || key == 124)
		return (ft_right(game, &game->pg, game->map.size));
	else if (key == 53)
		ft_xclose(game);
	else if (key == 257)
	{
		if (game->pg.speed == 50000)
			game->pg.speed = 25000;
		else
			game->pg.speed = 50000;
	}
	else
		return (0);
	return (1);
}

void	ft_update(t_game *game)
{
	if (game->mat[game->pg.y][game->pg.x] == 67)
	{
		game->mat[game->pg.y][game->pg.x] = 48;
		game->pg.coll++;
	}
	if (game->pg.x == game->npc.x && game->pg.y == game->npc.y
		&& game->npc.is)
		ft_close(game, "Loser... try again...", 0);
	if (game->npc.is)
		ft_npc_move(game, &game->npc);
	if (game->pg.coll == game->map.coll_n)
		ft_enable_exit(game);
	ft_write_info(game);
	ft_printf("Moves: %d\n", game->pg.moves);
	if (game->pg.exit && game->mat[game->pg.y][game->pg.x] == 69)
		ft_close(game, "Win!!!", 0);
	if (game->pg.x == game->npc.x && game->pg.y == game->npc.y
		&& game->npc.is)
		ft_close(game, "Loser... try again...", 0);
}
