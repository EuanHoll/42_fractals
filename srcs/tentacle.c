/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   tentacle.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/17 11:42:27 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/17 11:42:27 by ehollidg      ########   odam.nl         */
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
	p0->x = ((mmtranslationx(vec2->x, mlx) - 2) * mlx->fract->zoom)
		- ((mmtranslationx(mlx->fract->mspos.x + mlx->fract->trans.x, mlx) - 2)
		* change);
	p0->y = ((mmtranslationy(vec2->y, mlx) - 1) * mlx->fract->zoom)
		- ((mmtranslationy(mlx->fract->mspos.y + mlx->fract->trans.y, mlx) - 1)
		* change);
}

static float	scalepos(float pos, float max)
{
	return (((pos / max) * 2) - 1.5);
}

void			tentacle(t_vec2 vec2, t_mlx *mlx, int colour)
{
	static float	oldzoom = 1;
	int				n;
	t_vec2			v0;
	t_vec2			p0;
	float			xtemp;

	setp0(&p0, &vec2, mlx, &oldzoom);
	v0.x = scalepos(mlx->fract->fracpos.x, mlx->window.x);
	v0.y = scalepos(mlx->fract->fracpos.y, mlx->window.y);
	n = 0;
	while ((p0.x * p0.x) + (p0.y * p0.y) <= 4 && n < mlx->fract->maxiter)
	{
		xtemp = (p0.x * p0.x) - (p0.y * p0.y) + v0.x;
		p0.y = fabs((-2 * p0.x * p0.y) + v0.y);
		p0.x = fabs(xtemp);
		n++;
	}
	if (n < mlx->fract->maxiter)
		n = n + 1 - (log((log((p0.x * p0.x)
			+ (p0.y * p0.y)) / 2) / LOG2) / LOG2);
	while (n >= mlx->fract->maxiter)
		n -= mlx->fract->maxiter;
	plot(vec2.x, vec2.y,
		doubletocolour(((float)n / (float)mlx->fract->maxiter), colour),
		mlx);
}
