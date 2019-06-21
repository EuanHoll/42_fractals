/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sierpinskic.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/19 17:40:16 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/19 17:40:16 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void			sierpinskic(t_vec2 vec2, t_mlx *mlx, int colour)
{
	int x;
	int y;

	x = (vec2.x + mlx->fract->trans.x) * mlx->fract->zoom;
	y = (vec2.y + mlx->fract->trans.y) * mlx->fract->zoom;
	while (y > 0 && x > 0)
	{
		if (x % 3 == 1 && y % 3 == 1)
		{
			plot(vec2.x, vec2.y, colour, mlx);
			return ;
		}
		x /= 3;
		y /= 3;
	}
	plot(vec2.x, vec2.y, BLACK, mlx);
}
