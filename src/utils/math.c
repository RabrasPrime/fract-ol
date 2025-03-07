/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 10:03:57 by tjooris           #+#    #+#             */
/*   Updated: 2025/03/07 16:29:57 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

double	lin_intrp(double transform, double l1, double l2, double res)
{
	return (transform * (l2 - l1) / (res) + l1);
}

void	is_double(char *str)
{
	int	i;
	int	sign;
	int	point;

	i = 0;
	point = 0;
	sign = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+')
			ft_error("error, invalid number");
		if ((str[i] < '0' || str[i] > '9')
			&& (str[i] == '.' && point))
			ft_error("error, invalid number");
		else if ((str[i] == '.' && !point))
			point = 1;
		i++;
	}
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
