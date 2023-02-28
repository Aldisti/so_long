/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 12:02:53 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/25 17:10:59 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# include "gnl/get_next_line.h"
# include "printf/ft_printf.h"

typedef struct s_npc
{
	char	*up[5];
	char	*bk[5];
	char	*lt[5];
	char	*rt[5];
	void	*img;
	int		size;
	int		x;
	int		y;
	int		is;
}	t_npc;

typedef struct s_pg
{
	char	*up_v[5];
	char	*bk_v[5];
	char	*lt_v[5];
	char	*rt_v[5];
	void	*img;
	int		size;
	int		moves;
	int		coll;
	int		exit;
	int		x;
	int		y;
	int		speed;
}	t_pg;

typedef struct s_map
{
	void	*bg;
	void	*wall;
	void	*coll;
	void	*exit;
	void	*exiton;
	void	*banner;
	int		size;
	int		ban_w;
	int		ban_h;
	int		coll_n;
}	t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	t_pg	pg;
	t_map	map;
	t_npc	npc;
	char	**mat;
	int		width;
	int		height;
	int		w;
	int		h;
}	t_game;

/* win_init */
int		ft_win_init(t_game *game);
void	ft_get_dim(t_game *game, char *path, int h);
int		ft_get_mat(t_game *game, char *path);
int		ft_check_mat(t_game *game, char **mat);
int		ft_check_str(char *str);
/* draw */
int		ft_draw_map(t_game *game, int size);
int		ft_draw_pgs(t_game *game, int size);
int		ft_draw_banner(t_game *game);
int		ft_enable_exit(t_game *game);
int		ft_write_info(t_game *game);
/* sets */
int		ft_set_vars(t_game *game);
int		ft_image_load(t_game *game);
void	ft_pg_images(t_pg *pg);
void	ft_npc_images(t_npc *npc);
/* hooks */
int		ft_key_hook(int key, t_game *game);
void	ft_update(t_game *game);
/* close */
void	ft_close(t_game *game, char *str, int type);
void	ft_destroy(t_game *game);
int		ft_xclose(t_game *game);
void	ft_free(char **ptr);
/* help */
int		ft_img(t_game *game, void *img, int x, int y);
void	ft_str(t_game *game, char *str, int x, int y);
/* moves */
int		ft_up(t_game *game, t_pg *pg, int size);
int		ft_down(t_game *game, t_pg *pg, int size);
int		ft_left(t_game *game, t_pg *pg, int size);
int		ft_right(t_game *game, t_pg *pg, int size);
/* npc_moves */
int		ft_npc_move(t_game *game, t_npc *npc);
int		ft_npc_up(t_game *game, t_map *map, t_npc *npc, int size);
int		ft_npc_down(t_game *game, t_map *map, t_npc *npc, int size);
int		ft_npc_left(t_game *game, t_map *map, t_npc *npc, int size);
int		ft_npc_right(t_game *game, t_map *map, t_npc *npc, int size);

#endif
