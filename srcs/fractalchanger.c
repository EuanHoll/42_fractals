/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractalchanger.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/20 12:03:29 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/20 12:03:29 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void		fractalswitcher(t_mlx *mlx)
{
	if (mlx->fract->fractdraw == julia)
		mlx->fract->fractdraw = mandelbrot;
	else if (mlx->fract->fractdraw == mandelbrot)
		mlx->fract->fractdraw = burningship;
	else if (mlx->fract->fractdraw == burningship)
		mlx->fract->fractdraw = sierpinskic;
	else if (mlx->fract->fractdraw == sierpinskic)
		mlx->fract->fractdraw = sierpinskit;
	else if (mlx->fract->fractdraw == sierpinskit)
		mlx->fract->fractdraw = tricorn;
	else if (mlx->fract->fractdraw == tricorn)
		mlx->fract->fractdraw = crosses;
	else if (mlx->fract->fractdraw == crosses)
		mlx->fract->fractdraw = tentacle;
	else if (mlx->fract->fractdraw == tentacle)
		mlx->fract->fractdraw = julia;
	mlx->fract->redraw = 1;
	mlx->fract->colour = LIGHT_GREEN;
	mlx->fract->zoom = 1;
}
