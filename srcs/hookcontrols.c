/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hookcontrols.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/17 11:25:45 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/17 11:25:45 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void	changeiter(t_mlx *mlx, int amount)
{
	mlx->fract->maxiter += amount;
	mlx->fract->redraw = 1;
}

static void	reset(t_mlx *mlx)
{
	mlx->fract->zoom = 1;
	mlx->fract->trans.x = 0;
	mlx->fract->trans.y = 0;
	mlx->fract->redraw = 1;
}

static int	keycontroller(int key, void *param)
{
	t_mlx	*mlx;

	mlx = (t_mlx*)param;
	if (key == KEY_ESC)
		end(NULL);
	else if (key == KEY_C)
		colourswitcher(mlx);
	else if (key == KEY_P)
		fractalswitcher(mlx);
	else if (key == KEY_SPACE)
		mlx->fract->movelock = !mlx->fract->movelock;
	else if (key == KEY_PLUS)
		changeiter(mlx, 1);
	else if (key == KEY_MINUS)
		changeiter(mlx, -1);
	else if (key == KEY_R)
		reset(mlx);
	else if (key == KEY_F)
		mlx->fract->ravemode = !mlx->fract->ravemode;
	transformhandler(key, mlx);
	return (0);
}

static int	mousezoom(int button, int x, int y, void *param)
{
	t_mlx *mlx;

	x -= y;
	mlx = (t_mlx*)param;
	if (button == MOUSE_ZOOMP && mlx->fract->zoom < 1)
		mlx->fract->zoom *= 1.1;
	else if (button == MOUSE_ZOOMM)
		mlx->fract->zoom /= 1.1;
	else
		return (0);
	mlx->fract->redraw = 1;
	return (0);
}

void		hookcontrols(t_mlx *mlx)
{
	mlx_hook(mlx->win, KEY_PRESS_EVENT, 1L << KEY_PRESS_EVENT,
			keycontroller, (void*)mlx);
	mlx_hook(mlx->win, MOUSE_MOVE_EVENT, 1L << MOUSE_MOVE_EVENT,
			mousemove, (void*)mlx);
	mlx_hook(mlx->win, CLOSE_EVENT, 1L << CLOSE_EVENT, end, NULL);
	mlx_hook(mlx->win, MOUSE_PRESSED_EVENT, 1L << MOUSE_PRESSED_EVENT,
			mousezoom, mlx);
}
