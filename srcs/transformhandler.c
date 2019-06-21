/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   transformhandler.c                                 :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/20 17:59:46 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/20 17:59:46 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void		transformhandler(int key, t_mlx *mlx)
{
	if (key == KEY_UP)
	{
		mlx->fract->trans.y += 10 * mlx->fract->zoom;
		mlx->fract->redraw = 1;
	}
	else if (key == KEY_DOWN)
	{
		mlx->fract->trans.y -= 10 * mlx->fract->zoom;
		mlx->fract->redraw = 1;
	}
	else if (key == KEY_LEFT)
	{
		mlx->fract->trans.x += 10 * mlx->fract->zoom;
		mlx->fract->redraw = 1;
	}
	else if (key == KEY_RIGHT)
	{
		mlx->fract->trans.x -= 10 * mlx->fract->zoom;
		mlx->fract->redraw = 1;
	}
}
