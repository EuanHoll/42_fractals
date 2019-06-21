/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/17 11:07:25 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/17 11:07:25 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

static void	invalidfractol(void)
{
	ft_putendl("Usage : ./fractol [Valid Fractal Type]");
	ft_putendl("Or      ./fractol [Valid Fractal Type] [sizex] [sizey]");
	ft_putendl("Valid Fractals : julia, mandelbrot, burningship");
	ft_putendl("                 sierpinskicarpet, sierpinskitrig");
	ft_putendl("                 crosses, tricorn, tentacle");
}

static void	switchstatement(char **argv, t_mlx *mlx)
{
	if (ft_strcmp("julia", argv[1]) == 0)
		startfractol(JULIA, mlx);
	else if (ft_strcmp("mandelbrot", argv[1]) == 0)
		startfractol(MANDELBROT, mlx);
	else if (ft_strcmp("burningship", argv[1]) == 0)
		startfractol(BURNINGSHIP, mlx);
	else if (ft_strcmp("sierpinskicarpet", argv[1]) == 0)
		startfractol(SIERPINSKIC, mlx);
	else if (ft_strcmp("sierpinskitrig", argv[1]) == 0)
		startfractol(SIERPINSKIT, mlx);
	else if (ft_strcmp("tricorn", argv[1]) == 0)
		startfractol(TRICORN, mlx);
	else if (ft_strcmp("crosses", argv[1]) == 0)
		startfractol(CROSSES, mlx);
	else if (ft_strcmp("tentacle", argv[1]) == 0)
		startfractol(TENTACLE, mlx);
	else
		invalidfractol();
}

static void	switchwindowsize(char **argv, t_mlx *mlx, int i)
{
	mlx->window.x = 0;
	mlx->window.y = 0;
	if (i == 1)
	{
		mlx->window.x = ft_atoi(argv[2]);
		mlx->window.y = ft_atoi(argv[3]);
	}
	if (i == 0 || mlx->window.x <= 0 || mlx->window.y <= 0)
	{
		mlx->window.x = 1280;
		mlx->window.y = 720;
	}
	switchstatement(argv, mlx);
}

int			main(int argc, char **argv)
{
	t_mlx mlx;

	if (argc == 2)
		switchwindowsize(argv, &mlx, 0);
	else if (argc == 4)
		switchwindowsize(argv, &mlx, 1);
	else
		invalidfractol();
	exit(0);
	return (0);
}
