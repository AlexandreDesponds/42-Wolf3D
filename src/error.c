/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adespond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 12:30:49 by adespond          #+#    #+#             */
/*   Updated: 2016/03/19 12:22:58 by adespond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/wolf.h"

void	error_malloc(void)
{
	write(1, "error malloc\n", 13);
	exit(1);
}

void	error_arg(void)
{
	write(1, "error argv\n", 12);
	write(1, "<filename> <map>\n", 18);
	exit(1);
}

void	error_map(void)
{
	write(1, "error map\n", 10);
	exit(1);
}
