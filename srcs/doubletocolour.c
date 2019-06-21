/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   doubletocolour.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/17 14:35:01 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/17 14:35:01 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int			doubletocolour(float val, int colour)
{
	long	hex;
	int		r;
	int		g;
	int		b;

	if (val < 0)
		val = 0;
	r = ((colour >> (8 * 0)) & 0xff) * val;
	g = ((colour >> (8 * 1)) & 0xff) * val;
	b = ((colour >> (8 * 2)) & 0xff) * val;
	hex = (r << 16L);
	hex += g << 8L;
	hex += b;
	return ((int)(hex));
}
