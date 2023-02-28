/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   npc_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:25:48 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/23 15:25:50 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_npc_up(t_game *game, t_map *map, t_npc *npc, int size)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		mlx_destroy_image(game->mlx, npc->img);
		npc->img = mlx_xpm_file_to_image(game->mlx, npc->up[i],
				&game->w, &game->h);
		if (i > 3)
		{
			ft_img(game, map->bg, npc->x * size, (npc->y - 1) * size);
			if (game->mat[npc->y - 1][npc->x] == 67)
				ft_img(game, map->coll, npc->x * size, (npc->y - 1) * size);
		}
		ft_img(game, map->bg, npc->x * size, npc->y * size);
		if (game->mat[npc->y][npc->x] == 67)
			ft_img(game, map->coll, npc->x * size, npc->y * size);
		ft_img(game, npc->img, npc->x * size, npc->y * size - (i + 1) * 10);
		usleep(30000);
	}
	npc->y--;
	return (1);
}

int	ft_npc_down(t_game *game, t_map *map, t_npc *npc, int size)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		mlx_destroy_image(game->mlx, npc->img);
		npc->img = mlx_xpm_file_to_image(game->mlx, npc->bk[i],
				&game->w, &game->h);
		if (i > 3)
		{
			ft_img(game, map->bg, npc->x * size, (npc->y + 1) * size);
			if (game->mat[npc->y + 1][npc->x] == 67)
				ft_img(game, map->coll, npc->x * size, (npc->y + 1) * size);
		}
		ft_img(game, map->bg, npc->x * size, npc->y * size);
		if (game->mat[npc->y][npc->x] == 67)
			ft_img(game, map->coll, npc->x * size, npc->y * size);
		ft_img(game, npc->img, npc->x * size, npc->y * size + (i + 1) * 10);
		usleep(30000);
	}
	npc->y++;
	return (1);
}

int	ft_npc_left(t_game *game, t_map *map, t_npc *npc, int size)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		mlx_destroy_image(game->mlx, npc->img);
		npc->img = mlx_xpm_file_to_image(game->mlx, npc->lt[i],
				&game->w, &game->h);
		if (i > 3)
		{
			ft_img(game, map->bg, (npc->x - 1) * size, npc->y * size);
			if (game->mat[npc->y][npc->x - 1] == 67)
				ft_img(game, map->coll, (npc->x - 1) * size, npc->y * size);
		}
		ft_img(game, map->bg, npc->x * size, npc->y * size);
		if (game->mat[npc->y][npc->x] == 67)
			ft_img(game, map->coll, npc->x * size, npc->y * size);
		ft_img(game, npc->img, npc->x * size - (i + 1) * 10, npc->y * size);
		usleep(30000);
	}
	npc->x--;
	return (1);
}

int	ft_npc_right(t_game *game, t_map *map, t_npc *npc, int size)
{
	int	i;

	i = -1;
	while (++i < 5)
	{
		mlx_destroy_image(game->mlx, npc->img);
		npc->img = mlx_xpm_file_to_image(game->mlx, npc->rt[i],
				&game->w, &game->h);
		if (i > 3)
		{
			ft_img(game, map->bg, (npc->x + 1) * size, npc->y * size);
			if (game->mat[npc->y][npc->x + 1] == 67)
				ft_img(game, map->coll, (npc->x + 1) * size, npc->y * size);
		}
		ft_img(game, map->bg, npc->x * size, npc->y * size);
		if (game->mat[npc->y][npc->x] == 67)
			ft_img(game, map->coll, npc->x * size, npc->y * size);
		ft_img(game, npc->img, npc->x * size + (i + 1) * 10, npc->y * size);
		usleep(30000);
	}
	npc->x++;
	return (1);
}

int	ft_npc_move(t_game *game, t_npc *npc)
{
	int	i;

	i = rand() % 4;
	if (i == 0 && game->mat[npc->y][npc->x - 1] != 49
			&& game->mat[npc->y][npc->x - 1] != 69)
		return (ft_npc_left(game, &game->map, npc, npc->size));
	else if (i == 1 && game->mat[npc->y + 1][npc->x] != 49
			&& game->mat[npc->y + 1][npc->x] != 69)
		return (ft_npc_down(game, &game->map, npc, npc->size));
	else if (i == 2 && game->mat[npc->y][npc->x + 1] != 49
			&& game->mat[npc->y][npc->x + 1] != 69)
		return (ft_npc_right(game, &game->map, npc, npc->size));
	else if (i == 3 && game->mat[npc->y - 1][npc->x] != 49
			&& game->mat[npc->y - 1][npc->x] != 69)
		return (ft_npc_up(game, &game->map, npc, npc->size));
	return (0);
}
