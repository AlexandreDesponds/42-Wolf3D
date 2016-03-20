/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 11:32:27 by adespond          #+#    #+#             */
/*   Updated: 2016/03/17 18:20:07 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

static void		read_option(t_env *e, int argc, char **argv)
{
	if (argc != 2)
		error_arg();
	if (open_file(e, argv[1]) == 0)
		error_map();
}

int				main(int argc, char **argv)
{
	t_env	*e;

	e = init_env();
	read_option(e, argc, argv);
	e->mlx.win = mlx_new_window(e->mlx.mlx, WIDTH, HEIGHT,
			"Wolf3d adespond@42");
	mlx_do_key_autorepeatoff(e->mlx.mlx);
	mlx_loop_hook(e->mlx.mlx, loop_hook, e);
	mlx_hook(e->mlx.win, KEY_PRESS, KEY_PRESS_MASK, key_press, e);
	mlx_key_hook(e->mlx.win, key_hook, e);
	mlx_loop(e->mlx.mlx);
	return (0);
}
