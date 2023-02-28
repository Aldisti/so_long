/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 15:25:14 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/23 15:25:16 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	ft_img(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x - 1, y - 1);
	return (1);
}

void	ft_str(t_game *game, char *str, int x, int y)
{
	mlx_string_put(game->mlx, game->win, x, y, 0xFFFFFF, str);
}
