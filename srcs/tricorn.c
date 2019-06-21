/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tricorn.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/20 14:34:08 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/20 14:34:08 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static float	mmtranslationx(int x, t_mlx *mlx)
{
	return ((((float)x / (float)mlx->window.x) * 3.5));
}

static float	mmtranslationy(int y, t_mlx *mlx)
{
	return ((((float)y / (float)mlx->window.y) * 2));
}

static void		setp0(t_vec2 *p0, t_vec2 *vec2, t_mlx *mlx, float *oldzoom)
{
	float change;

	change = mlx->fract->zoom - *oldzoom;
	p0->x = ((mmtranslationx(vec2->x, mlx) - 2.5) * mlx->fract->zoom)
		- ((mmtranslationx(mlx->fract->fracpos.x + mlx->fract->trans.x, mlx)
		- 2.5) * change);
	p0->y = ((mmtranslationy(vec2->y, mlx) - 1) * mlx->fract->zoom)
		- ((mmtranslationy(mlx->fract->fracpos.y + mlx->fract->trans.y, mlx)
		- 1) * change);
}

void			tricorn(t_vec2 vec2, t_mlx *mlx, int colour)
{
	static float	oldzoom = 1;
	int				n;
	t_vec2			v0;
	t_vec2			p0;
	float			xtemp;

	setp0(&p0, &vec2, mlx, &oldzoom);
	v0.x = p0.x;
	v0.y = p0.y;
	n = 0;
	while ((v0.x * v0.x) + (v0.y * v0.y) < 4 && n < mlx->fract->maxiter)
	{
		xtemp = (v0.x * v0.x) - (v0.y * v0.y) + (p0.x);
		v0.y = (-2 * v0.x * v0.y) + (p0.y);
		v0.x = xtemp;
		n++;
	}
	if (n >= mlx->fract->maxiter)
		n = 0;
	plot(vec2.x, vec2.y,
		doubletocolour(((float)n / (float)mlx->fract->maxiter), colour),
		mlx);
}
