/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:25:38 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/24 10:26:55 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

/* if the up function works just copy that for the others */
/* maybe i don't need the 2nd put_image in the last if (to test) */
int	ft_up(t_game *game, t_pg *pg, int size)
{
	int	i;

	if (game->mat[pg->y - 1][pg->x] == 49 || (!pg->exit
			&& game->mat[pg->y - 1][pg->x] == 69))
		return (0);
	i = -1;
	while (++i < 5)
	{
		mlx_destroy_image(game->mlx, pg->img);
		pg->img = mlx_xpm_file_to_image(game->mlx, pg->up_v[i],
				&game->w, &game->h);
		if (i > 3)
			ft_img(game, game->map.bg, pg->x * size, (pg->y - 1) * size);
		ft_img(game, game->map.bg, pg->x * size, pg->y * size);
		ft_img(game, pg->img, pg->x * size, pg->y * size - (i + 1) * 10);
		usleep(pg->speed);
	}
	pg->moves++;
	pg->y--;
	ft_update(game);
	return (1);
}

int	ft_down(t_game *game, t_pg *pg, int size)
{
	int	i;

	if (game->mat[pg->y + 1][pg->x] == 49 || (!pg->exit
			&& game->mat[pg->y + 1][pg->x] == 69))
		return (0);
	i = -1;
	while (++i < 5)
	{
		mlx_destroy_image(game->mlx, pg->img);
		pg->img = mlx_xpm_file_to_image(game->mlx, pg->bk_v[i],
				&game->w, &game->h);
		if (i > 3)
			ft_img(game, game->map.bg, pg->x * size, (pg->y + 1) * size);
		ft_img(game, game->map.bg, pg->x * size, pg->y * size);
		ft_img(game, pg->img, pg->x * size, pg->y * size + (i + 1) * 10);
		usleep(pg->speed);
	}
	pg->moves++;
	pg->y++;
	ft_update(game);
	return (1);
}

int	ft_left(t_game *game, t_pg *pg, int size)
{
	int	i;

	if (game->mat[pg->y][pg->x - 1] == 49 || (!pg->exit
			&& game->mat[pg->y][pg->x - 1] == 69))
		return (0);
	i = -1;
	while (++i < 5)
	{
		mlx_destroy_image(game->mlx, pg->img);
		pg->img = mlx_xpm_file_to_image(game->mlx, pg->lt_v[i],
				&game->w, &game->h);
		if (i >= 3)
			ft_img(game, game->map.bg, (pg->x - 1) * size, pg->y * size);
		ft_img(game, game->map.bg, pg->x * size, pg->y * size);
		ft_img(game, pg->img, pg->x * size - (i + 1) * 10, pg-> y * size);
		usleep(pg->speed);
	}
	pg->moves++;
	pg->x--;
	ft_update(game);
	return (1);
}

int	ft_right(t_game *game, t_pg *pg, int size)
{
	int	i;

	if (game->mat[pg->y][pg->x + 1] == 49 || (!pg->exit
			&& game->mat[pg->y][pg->x + 1] == 69))
		return (0);
	i = -1;
	while (++i < 5)
	{
		mlx_destroy_image(game->mlx, pg->img);
		pg->img = mlx_xpm_file_to_image(game->mlx, pg->rt_v[i],
				&game->w, &game->h);
		if (i >= 3)
			ft_img(game, game->map.bg, (pg->x + 1) * size, pg->y * size);
		ft_img(game, game->map.bg, pg->x * size, pg->y * size);
		ft_img(game, pg->img, pg->x * size + (i + 1) * 10, pg->y * size);
		usleep(pg->speed);
	}
	pg->moves++;
	pg->x++;
	ft_update(game);
	return (1);
}
