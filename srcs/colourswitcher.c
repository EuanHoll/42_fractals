/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   colourswitcher.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/17 15:38:49 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/17 15:38:49 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void		colourswitcher(t_mlx *mlx)
{
	if (mlx->fract->colour == LIGHT_GREEN)
		mlx->fract->colour = LIGHT_BLUE;
	else if (mlx->fract->colour == LIGHT_BLUE)
		mlx->fract->colour = RED;
	else if (mlx->fract->colour == RED)
		mlx->fract->colour = ORANGE;
	else if (mlx->fract->colour == ORANGE)
		mlx->fract->colour = PINK;
	else if (mlx->fract->colour == PINK)
		mlx->fract->colour = YELLOW;
	else if (mlx->fract->colour == YELLOW)
		mlx->fract->colour = DARK_BLUE;
	else if (mlx->fract->colour == DARK_BLUE)
		mlx->fract->colour = PURPLE;
	else if (mlx->fract->colour == PURPLE)
		mlx->fract->colour = WHITE;
	else if (mlx->fract->colour == WHITE)
		mlx->fract->colour = LIGHT_GREEN;
	mlx->fract->redraw = 1;
}
