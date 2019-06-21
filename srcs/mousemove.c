/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mousemove.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/17 11:52:39 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/17 11:52:39 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int			mousemove(int x, int y, void *param)
{
	t_mlx *mlx;

	mlx = (t_mlx*)param;
	mlx->fract->mspos.x = x;
	mlx->fract->mspos.y = y;
	if (mlx->fract->movelock == 0)
	{
		mlx->fract->fracpos.x = x;
		mlx->fract->fracpos.y = y;
	}
	mlx->fract->redraw = 1;
	return (0);
}
