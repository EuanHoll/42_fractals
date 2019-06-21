/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   drawmap.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/17 13:37:42 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/17 13:37:42 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

void			*mapwork(void *param)
{
	t_info	*info;
	t_mlx	*mlx;
	int		max;
	int		y;
	int		x;

	info = (t_info*)param;
	max = info->max;
	y = info->y;
	mlx = info->mlx;
	while (y < max && y < mlx->window.y)
	{
		x = 0;
		while (x < mlx->window.x)
		{
			mlx->fract->fractdraw((t_vec2){x, y}, mlx, mlx->fract->colour);
			x++;
		}
		y++;
	}
	pthread_exit(NULL);
}

void			drawmap(t_mlx *mlx)
{
	int				max;
	int				y;
	pthread_t		threads[4];
	t_info			hate[4];

	y = 0;
	max = mlx->window.y / 4;
	while (y < 4)
	{
		hate[y] = ((t_info){((y) * max) + max, (y) * max, mlx});
		pthread_create(&threads[y], NULL, mapwork, &hate[y]);
		y++;
	}
	y = 0;
	while (y < 4)
	{
		pthread_join(threads[y], NULL);
		y++;
	}
}
