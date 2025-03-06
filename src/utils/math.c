/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:03:57 by tjooris           #+#    #+#             */
/*   Updated: 2025/03/07 00:31:10 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

// linear interpolation, used to map pixel coordinates to complex plane
double	lin_intrp(double transform, double l1, double l2, double res)
{
	return (transform * (l2 - l1) / (res) + l1);
}

double	atodbl(char *s)
{
	long	i;
	double	f;
	double	pow;
	int		sign;

	i = 0;
	f = 0;
	sign = 1;
	pow = 1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		s++;
	while (*s == '-' || *s == '+')
		if (*s++ == '-')
			sign = -1;
	while (*s != '.' && *s)
		i = (i * 10) + (*s++ - '0');
	if (*s == '.')
		s++;
	while (*s)
	{
		pow /= 10;
		f = f + (*s++ - '0') * pow;
	}
	return ((double)(i + f) *sign);
}