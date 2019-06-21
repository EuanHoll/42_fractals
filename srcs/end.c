/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   end.c                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: ehollidg <ehollidg@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/06/17 11:28:43 by ehollidg       #+#    #+#                */
/*   Updated: 2019/06/17 11:28:43 by ehollidg      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fract.h"

int		end(void *param)
{
	if (param != NULL && *((int*)param) == 2)
		ft_putendl("Uneable to allocate any more memory");
	exit(0);
}
