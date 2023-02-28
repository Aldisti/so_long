/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adi-stef <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 10:04:57 by adi-stef          #+#    #+#             */
/*   Updated: 2023/02/25 16:49:37 by adi-stef         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	main(int argc, char **argv)
{
	static t_game	game;

	if (argc != 2)
	{
		ft_printf("Error\nYou must insert only one path!\n");
		exit(1);
	}
	if (!ft_check_str(argv[1]))
	{
		ft_printf("Error\nYou must insert a valid path!\n");
		exit(1);
	}
	ft_set_vars(&game);
	if (!ft_get_mat(&game, argv[1]))
		ft_close(&game, "one or more characters are missing", 7);
	ft_win_init(&game);
	mlx_key_hook(game.win, ft_key_hook, &game);
	mlx_hook(game.win, 17, 0, ft_xclose, &game);
	mlx_loop(game.mlx);
	return (1);
}
