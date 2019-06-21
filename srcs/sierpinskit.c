/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sierpinskit.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/19 18:06:05 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/19 18:06:05 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void			sierpinskit(t_vec2 vec2, t_mlx *mlx, int colour)
{
	int y;
	int x;

	x = (vec2.x + mlx->fract->trans.x) * mlx->fract->zoom;
	y = (vec2.y + mlx->fract->trans.y) * mlx->fract->zoom;
	if (x == 0 || y == 0)
		plot(x, y, BLACK, mlx);
	else
	{
		if ((x & y) == 0)
			plot(vec2.x, vec2.y, colour, mlx);
		else
			plot(vec2.x, vec2.y, BLACK, mlx);
	}
}
