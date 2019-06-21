/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawinfo.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/17 15:35:17 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/17 15:35:17 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void		drawfractalinfo(t_mlx *mlx, int colour, int y)
{
	if (mlx->fract->fractdraw == julia)
		mlx_string_put(mlx->mlx, mlx->win, 5, y, colour, "Type : Julia");
	else if (mlx->fract->fractdraw == mandelbrot)
		mlx_string_put(mlx->mlx, mlx->win, 5, y, colour, "Type : Mandelbrot");
	else if (mlx->fract->fractdraw == burningship)
		mlx_string_put(mlx->mlx, mlx->win, 5, y, colour, "Type : Burning Ship");
	else if (mlx->fract->fractdraw == sierpinskic)
		mlx_string_put(mlx->mlx, mlx->win, 5, y, colour,
			"Type : Sierpinski Carpet");
	else if (mlx->fract->fractdraw == sierpinskit)
		mlx_string_put(mlx->mlx, mlx->win, 5, y, colour,
			"Type : Sierpinski Triangle");
	else if (mlx->fract->fractdraw == tricorn)
		mlx_string_put(mlx->mlx, mlx->win, 5, y, colour, "Type : Tricorn");
	else if (mlx->fract->fractdraw == crosses)
		mlx_string_put(mlx->mlx, mlx->win, 5, y, colour, "Type : Crosses");
	else if (mlx->fract->fractdraw == tentacle)
		mlx_string_put(mlx->mlx, mlx->win, 5, y, colour, "Type : Tentacle");
}

void			drawinfo(t_mlx *mlx, int colour)
{
	mlx_string_put(mlx->mlx, mlx->win, 5, 5, colour, "Change Colour : c");
	drawfractalinfo(mlx, colour, 25);
	mlx_string_put(mlx->mlx, mlx->win, 5, 45, colour, "Detail : + -");
	mlx_string_put(mlx->mlx, mlx->win, 5, 65, colour, "Freeze : space");
	mlx_string_put(mlx->mlx, mlx->win, 5, 85, colour, "Reset : r");
	mlx_string_put(mlx->mlx, mlx->win, 5, 105, colour, "Rave Mode : f");
}
