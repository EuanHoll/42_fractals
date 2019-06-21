/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   plot.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/05 16:36:24 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/06 11:50:32 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static int	inbounds(int x, int y, t_mlx *mlx)
{
	if (x >= 0 && y >= 0 && x < mlx->window.x && y < mlx->window.y)
		return (1);
	return (0);
}

void		plot(int x, int y, int colour, t_mlx *mlx)
{
	int *i_img;

	i_img = mlx->img_add;
	if (inbounds(x, y, mlx))
		ft_memcpy(&i_img[(y * mlx->window.x) + x], &colour, 4);
}
