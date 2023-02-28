/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:25:57 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/24 10:24:56 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_image_load(t_game *game)
{
	game->map.bg = mlx_xpm_file_to_image(game->mlx, "images/Grass.xpm",
			&game->w, &game->h);
	game->map.wall = mlx_xpm_file_to_image(game->mlx, "images/Rock.xpm",
			&game->w, &game->h);
	game->map.coll = mlx_xpm_file_to_image(game->mlx, "images/Rupee.xpm",
			&game->w, &game->h);
	game->map.exit = mlx_xpm_file_to_image(game->mlx, "images/PortalOff.xpm",
			&game->w, &game->h);
	game->map.exiton = mlx_xpm_file_to_image(game->mlx, "images/PortalOn.xpm",
			&game->w, &game->h);
	game->pg.img = mlx_xpm_file_to_image(game->mlx, game->pg.bk_v[0],
			&game->w, &game->h);
	game->map.banner = mlx_xpm_file_to_image(game->mlx, "images/Banner.xpm",
			&game->w, &game->h);
	game->npc.img = mlx_xpm_file_to_image(game->mlx, game->npc.bk[0],
			&game->w, &game->h);
	if (!game->map.bg || !game->map.wall || !game->map.coll || !game->map.exit
		|| !game->map.banner || !game->pg.img || !game->npc.img
		|| !game->map.exiton)
		return (0);
	return (1);
}

void	ft_npc_images(t_npc *npc)
{
	npc->up[0] = "images/NpcFront.xpm";
	npc->up[1] = "images/NpcFrontR.xpm";
	npc->up[2] = npc->up[0];
	npc->up[3] = "images/NpcFrontL.xpm";
	npc->up[4] = npc->up[0];
	npc->bk[0] = "images/NpcBack.xpm";
	npc->bk[1] = "images/NpcBackR.xpm";
	npc->bk[2] = npc->bk[0];
	npc->bk[3] = "images/NpcBackL.xpm";
	npc->bk[4] = npc->bk[0];
	npc->lt[0] = "images/NpcLeft.xpm";
	npc->lt[1] = "images/NpcLeftR.xpm";
	npc->lt[2] = npc->lt[0];
	npc->lt[3] = "images/NpcLeftL.xpm";
	npc->lt[4] = npc->lt[0];
	npc->rt[0] = "images/NpcRight.xpm";
	npc->rt[1] = "images/NpcRightR.xpm";
	npc->rt[2] = npc->rt[0];
	npc->rt[3] = "images/NpcRightL.xpm";
	npc->rt[4] = npc->rt[0];
}

void	ft_pg_images(t_pg *pg)
{
	pg->up_v[0] = "images/PgFront.xpm";
	pg->up_v[1] = "images/PgFrontL.xpm";
	pg->up_v[2] = pg->up_v[0];
	pg->up_v[3] = "images/PgFrontR.xpm";
	pg->up_v[4] = pg->up_v[0];
	pg->bk_v[0] = "images/PgBack.xpm";
	pg->bk_v[1] = "images/PgBackL.xpm";
	pg->bk_v[2] = pg->bk_v[0];
	pg->bk_v[3] = "images/PgBackR.xpm";
	pg->bk_v[4] = pg->bk_v[0];
	pg->lt_v[0] = "images/PgLeft.xpm";
	pg->lt_v[1] = "images/PgLeftL.xpm";
	pg->lt_v[2] = pg->lt_v[0];
	pg->lt_v[3] = "images/PgLeftR.xpm";
	pg->lt_v[4] = pg->lt_v[0];
	pg->rt_v[0] = "images/PgRight.xpm";
	pg->rt_v[1] = "images/PgRightL.xpm";
	pg->rt_v[2] = pg->rt_v[0];
	pg->rt_v[3] = "images/PgRightR.xpm";
	pg->rt_v[4] = pg->rt_v[0];
}

int	ft_set_vars(t_game *game)
{
	ft_pg_images(&game->pg);
	ft_npc_images(&game->npc);
	game->map.size = 50;
	game->pg.size = 50;
	game->npc.size = 50;
	game->map.ban_w = 25;
	game->map.ban_h = 30;
	game->map.coll_n = 0;
	game->pg.exit = 0;
	game->pg.moves = 0;
	game->pg.speed = 50000;
	game->npc.is = 0;
	game->pg.x = 0;
	game->pg.y = 0;
	return (1);
}
