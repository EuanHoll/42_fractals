/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fract.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/17 11:05:51 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/17 11:05:51 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACT_H
# define FRACT_H

# include "mlx.h"
# include "libft.h"
# include "values.h"
# include <stdlib.h>
# include <math.h>
# include <pthread.h>

typedef struct	s_vec2
{
	float		x;
	float		y;
}				t_vec2;

typedef struct	s_mspos
{
	int			x;
	int			y;
}				t_mspos;

typedef struct s_fract	t_fract;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	void		*img;
	void		*img_add;
	t_fract		*fract;
	t_mspos		window;
}				t_mlx;

typedef struct	s_info
{
	int				max;
	int				y;
	t_mlx			*mlx;
}				t_info;

struct			s_fract
{
	t_vec2		trans;
	t_mspos		mspos;
	t_mspos		fracpos;
	void		(*fractdraw)(t_vec2 vec2, t_mlx *mlx, int colour);
	int			colour;
	float		zoom;
	int			redraw;
	int			movelock;
	int			maxiter;
	int			ravemode;
	int			animate;
};

void			hookcontrols(t_mlx *mlx);
int				end(void *param);
int				mousemove(int x, int y, void *param);
void			plot(int x, int y, int colour, t_mlx *mlx);
void			mandelbrot(t_vec2 vec2, t_mlx *mlx, int colour);
void			julia(t_vec2 vec2, t_mlx *mlx, int colour);
void			burningship(t_vec2 vec2, t_mlx *mlx, int colour);
void			sierpinskic(t_vec2 vec2, t_mlx *mlx, int colour);
void			sierpinskit(t_vec2 vec2, t_mlx *mlx, int colour);
void			tricorn(t_vec2 vec2, t_mlx *mlx, int colour);
void			crosses(t_vec2 vec2, t_mlx *mlx, int colour);
void			tentacle(t_vec2 vec2, t_mlx *mlx, int colour);
int				loop(void *param);
void			drawmap(t_mlx *mlx);
int				doubletocolour(float val, int colour);
void			drawinfo(t_mlx *mlx, int colour);
void			colourswitcher(t_mlx *mlx);
void			fractalswitcher(t_mlx *mlx);
void			startfractol(int type, t_mlx *mlx);
void			transformhandler(int key, t_mlx *mlx);

#endif
