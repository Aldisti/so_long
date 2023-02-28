/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:24:47 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/27 13:28:39 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

void	ft_free(char **ptr)
{
	int	i;

	i = -1;
	while (ptr[++i])
		free(ptr[i]);
	free(ptr);
}

void	ft_destroy(t_game *game)
{
	if (game->map.bg)
		mlx_destroy_image(game->mlx, game->map.bg);
	if (game->map.wall)
		mlx_destroy_image(game->mlx, game->map.wall);
	if (game->map.coll)
		mlx_destroy_image(game->mlx, game->map.coll);
	if (game->map.banner)
		mlx_destroy_image(game->mlx, game->map.banner);
	if (game->map.exit)
		mlx_destroy_image(game->mlx, game->map.exit);
	if (game->map.exiton)
		mlx_destroy_image(game->mlx, game->map.exiton);
	if (game->pg.img)
		mlx_destroy_image(game->mlx, game->pg.img);
	if (game->npc.img)
		mlx_destroy_image(game->mlx, game->npc.img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
}

int	ft_xclose(t_game *game)
{
	ft_close(game, "Game closed in a clean way", 2);
	return (1);
}

void	ft_close(t_game *game, char *str, int type)
{
	if (type == 1 || type == 7)
	{
		ft_free(game->mat);
		if (type == 1)
			ft_destroy(game);
		ft_printf("Error\nType: %s\n", str);
	}
	else if (type == 3)
		ft_printf("Error\nType: %s\n", str);
	else if (type == 5)
	{
		free(game->mat);
		ft_printf("Error\nType: %s\n", str);
	}
	else if (type == 0 || type == 2)
	{
		ft_free(game->mat);
		ft_destroy(game);
		if (game->pg.coll <= game->map.coll_n / 2 && type != 2)
			ft_printf("What a loser... How can you be so noob...\n");
		else
			ft_printf("%s\n", str);
	}
	exit(1);
}
