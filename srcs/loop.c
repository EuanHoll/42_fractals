/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   loop.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/17 13:48:02 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/17 13:48:02 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void	bcolour(t_mlx *mlx, int colour)
{
	int x;
	int y;

	y = 0;
	while (y < mlx->window.y)
	{
		x = 0;
		while (x < mlx->window.x)
		{
			plot(x, y, colour, mlx);
			x++;
		}
		y++;
	}
}

static int	redraw(t_mlx *mlx, t_mspos *pre, int *colour)
{
	int i;

	i = (mlx->fract->redraw)
		|| (pre->x == -1 || pre->y == -1)
		|| *colour != mlx->fract->colour;
	return (i);
}

int			loop(void *param)
{
	static t_mspos	pre = (t_mspos){-1, -1};
	static int		colour = -1;
	static float	prezoom = -1;
	t_mlx			*mlx;

	mlx = (t_mlx*)param;
	if (mlx->fract->ravemode == 1)
		colourswitcher(mlx);
	if (redraw(mlx, &pre, &colour))
	{
		bcolour(mlx, BLACK);
		drawmap(mlx);
		pre = mlx->fract->mspos;
		colour = mlx->fract->colour;
		prezoom = mlx->fract->zoom;
		mlx->fract->redraw = 0;
		mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
		drawinfo(mlx, WHITE);
	}
	return (0);
}
