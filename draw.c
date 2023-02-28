/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:24:59 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/24 10:21:31 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

// 49: 1
// 69: E
// 67: C
// 78: N
// 80: P
int	ft_draw_map(t_game *game, int size)
{
	int	i;
	int	j;

	j = -1;
	while (game->mat[++j])
	{
		i = -1;
		while (game->mat[j][++i])
		{
			ft_img(game, game->map.bg, i * size, j * size);
			if (game->mat[j][i] == 49)
				ft_img(game, game->map.wall, i * size, j * size);
			else if (game->mat[j][i] == 69)
				ft_img(game, game->map.exit, i * size, j * size);
			else if (game->mat[j][i] == 67)
				ft_img(game, game->map.coll, i * size, j * size);
		}
	}
	ft_draw_pgs(game, size);
	return (1);
}

int	ft_draw_pgs(t_game *game, int size)
{
	int	i;
	int	j;

	j = -1;
	while (game->mat[++j])
	{
		i = -1;
		while (game->mat[j][++i])
		{
			if (game->mat[j][i] == 80)
			{
				ft_img(game, game->pg.img, i * size, j * size);
				game->pg.x = i;
				game->pg.y = j;
			}
			else if (game->mat[j][i] == 78)
			{
				ft_img(game, game->npc.img, i * size, j * size);
				game->npc.x = i;
				game->npc.y = j;
				game->npc.is = 1;
			}
		}
	}
	return (1);
}

int	ft_write_info(t_game *game)
{
	char	*num;
	int		size;
	int		x;
	int		y;

	ft_draw_banner(game);
	size = game->map.ban_w;
	x = game->width / 4 * 3;
	y = game->height + game->map.ban_h / 2;
	ft_str(game, "Moves:", game->width / 8, y);
	num = ft_itoa(game->pg.moves);
	ft_str(game, num, game->width / 4, y);
	free(num);
	ft_str(game, "Rupees collected:", game->width / 2, y);
	num = ft_itoa(game->pg.coll);
	ft_str(game, num, x + 10, y);
	free(num);
	ft_str(game, "/", x + game->map.ban_w, y);
	num = ft_itoa(game->map.coll_n);
	ft_str(game, num, x + game->map.ban_w + 10, y);
	free(num);
	return (1);
}

int	ft_enable_exit(t_game *game)
{
	int	i;
	int	j;

	if (game->pg.exit || game->pg.coll != game->map.coll_n)
		return (0);
	game->pg.exit = 1;
	j = -1;
	while (game->mat[++j])
	{
		i = 0;
		while (game->mat[j][i] && game->mat[j][i] != 69)
			i++;
		if (game->mat[j][i] == 69)
			break ;
	}
	if (game->mat[j][i] != 69)
		return (0);
	ft_img(game, game->map.bg, i * game->map.size, j * game->map.size);
	ft_img(game, game->map.exiton, i * game->map.size, j * game->map.size);
	return (1);
}

int	ft_draw_banner(t_game *game)
{
	int	i;
	int	w;
	int	h;

	i = -1;
	w = game->map.ban_w;
	h = game->height;
	while (++i < game->width / game->map.ban_w)
		ft_img(game, game->map.banner, i * w, h);
	return (1);
}
