/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   startfractol.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/20 14:44:45 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/20 14:44:45 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void	choosefract(t_mlx *mlx, int type)
{
	if (type == MANDELBROT)
		mlx->fract->fractdraw = mandelbrot;
	else if (type == JULIA)
		mlx->fract->fractdraw = julia;
	else if (type == BURNINGSHIP)
		mlx->fract->fractdraw = burningship;
	else if (type == SIERPINSKIC)
		mlx->fract->fractdraw = sierpinskic;
	else if (type == SIERPINSKIT)
		mlx->fract->fractdraw = sierpinskit;
	else if (type == TRICORN)
		mlx->fract->fractdraw = tricorn;
	else if (type == CROSSES)
		mlx->fract->fractdraw = crosses;
	else if (type == TENTACLE)
		mlx->fract->fractdraw = tentacle;
}

static void	setfract(t_mlx *mlx, int type)
{
	int i;

	i = 2;
	mlx->fract = (t_fract*)ft_memalloc(sizeof(t_fract));
	if (mlx->fract == NULL)
		end((void*)(&i));
	mlx->fract->colour = LIGHT_GREEN;
	mlx->fract->zoom = 1;
	mlx->fract->redraw = 0;
	mlx->fract->mspos.x = -1;
	mlx->fract->mspos.y = -1;
	mlx->fract->movelock = 0;
	mlx->fract->maxiter = 40;
	mlx->fract->ravemode = 0;
	mlx->fract->animate = 0;
	mlx->fract->trans.x = 0;
	mlx->fract->trans.y = 0;
	choosefract(mlx, type);
}

void		startfractol(int type, t_mlx *mlx)
{
	int		tmp;

	tmp = 0;
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, mlx->window.x,
								mlx->window.y, "Fractol");
	mlx->img = mlx_new_image(mlx->mlx, mlx->window.x, mlx->window.y);
	mlx->img_add = mlx_get_data_addr(mlx->img, &tmp, &tmp, &tmp);
	setfract(mlx, type);
	hookcontrols(mlx);
	mlx_loop_hook(mlx->mlx, loop, (void*)(mlx));
	mlx_loop(mlx->mlx);
}
