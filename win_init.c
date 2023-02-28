/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:26:12 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/25 17:11:06 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

/* initialize the mlx, the window and calls the functions to draw the map */
int	ft_win_init(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		ft_close(game, "mlx failed", 3);
	game->win = mlx_new_window(game->mlx, game->width,
			game->height + game->map.ban_h, "./so_long");
	if (!game->win)
		ft_close(game, "mlx failed to initialize the window", 3);
	if (!ft_image_load(game))
		ft_close(game, "failed to load images", 1);
	if (!ft_draw_map(game, game->map.size))
		ft_close(game, "failed to draw the map", 1);
	ft_write_info(game);
	return (1);
}

/* gets the width and the height of the window from the input map */
void	ft_get_dim(t_game *game, char *path, int h)
{
	char	*line;
	int		fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_close(game, "path not found", 3);
	line = get_next_line(fd);
	if (!line)
		ft_close(game, "get_next_line failed", 3);
	game->width = game->map.size * (ft_strlen(line) - 1);
	while (line && ++h)
	{
		line[ft_strlen(line) - 1] = 0;
		if (ft_strlen(line) * game->map.size != game->width && *line)
			h = 0;
		h -= !(*line) * 1;
		free(line);
		if (!h)
			ft_close(game, "map must be rectangular", 3);
		line = get_next_line(fd);
	}
	game->height = game->map.size * h;
	if (game->width == game->height)
		ft_close(game, "map must be rectangular", 3);
}

/* creates a matrix from the input map */
int	ft_get_mat(t_game *game, char *path)
{
	char	*line;
	int		fd;
	int		i;

	ft_get_dim(game, path, 0);
	game->mat = (char **) malloc ((game->height + 1) * sizeof(char *));
	if (!game->mat)
		ft_close(game, "matrix malloc failed", 3);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		ft_close(game, "path not found", 3);
	line = get_next_line(fd);
	if (!line)
		ft_close(game, "get_next_line failed", 5);
	i = 0;
	while (line)
	{
		line[ft_strlen(line) - 1] = 0;
		game->mat[i++] = line;
		line = get_next_line(fd);
	}
	game->mat[i] = 0;
	return (ft_check_mat(game, game->mat));
}

// checks the input map
// saves the number of collectibles
// and the coordinates of the player
int	ft_check_mat(t_game *game, char **mat)
{
	int	i;
	int	j;
	int	exit;

	j = -1;
	exit = 0;
	while (mat[++j])
	{
		i = -1;
		while (mat[j][++i])
		{
			if (mat[j][i] != 48 && mat[j][i] != 49 && mat[j][i] != 67
				&& mat[j][i] != 69 && mat[j][i] != 80 && mat[j][i] != 78)
				ft_close(game, "unknown symbols in map", 1);
			if (((j == 0 || !(mat[j + 1])) && mat[j][i] != 49)
				|| ((i == 0 || !(mat[j][i + 1])) && mat[j][i] != 49))
				ft_close(game, "map is not surrounded by walls", 1);
			if (mat[j][i] == 80)
				game->pg.x = i;
			exit += (mat[j][i] == 69);
			game->pg.x += i * (mat[j][i] == 80);
			game->map.coll_n += (mat[j][i] == 67);
		}
	}
	return (game->pg.x > 0 && exit > 0 && game->map.coll_n > 0);
}

int	ft_check_str(char *str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
		;
	if (i < 5)
		return (0);
	j = 0;
	if (str[i - 1] != 'r' || str[i - 2] != 'e' || str[i - 3] != 'b'
		|| str[i - 4] != 46)
		return (0);
	return (1);
}
