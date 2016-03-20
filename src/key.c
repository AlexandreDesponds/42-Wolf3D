/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 15:54:05 by adespond          #+#    #+#             */
/*   Updated: 2016/03/18 11:10:03 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	key_move(int k, t_env *e)
{
	if (k == KEY_UP)
		e->player.move_up = !e->player.move_up;
	if (k == KEY_DOWN)
		e->player.move_down = !e->player.move_down;
	if (k == KEY_LEFT)
		e->player.move_left = !e->player.move_left;
	if (k == KEY_RIGHT)
		e->player.move_right = !e->player.move_right;
	if (k == KEY_JUMP && e->player.move_jump == 0)
		e->player.move_jump = 1;
	if (k == KEY_ESC)
	{
		mlx_destroy_window(e->mlx.mlx, e->mlx.win);
		exit(0);
	}
}

int		key_press(int k, t_env *e)
{
	key_move(k, e);
	return (0);
}

int		key_hook(int k, t_env *e)
{
	key_move(k, e);
	return (0);
}
