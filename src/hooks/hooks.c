/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 11:06:57 by tjooris           #+#    #+#             */
/*   Updated: 2025/03/07 14:20:46 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	my_hooks(t_data *data)
{
	mlx_hook(data->win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->win, ButtonPress, ButtonPressMask, mouse_press, data);
	mlx_hook(data->win, DestroyNotify, StructureNotifyMask, exit_hook, data);
}

int	key_press(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		free_data(data, 0);
	else if (keycode == XK_Right)
		shift_x(data, 1);
	else if (keycode == XK_Left)
		shift_x(data, -1);
	else if (keycode == XK_Up)
		shift_y(data, -1);
	else if (keycode == XK_Down)
		shift_y(data, 1);
	else if (keycode == XK_plus || keycode == XK_equal)
		data->iter_ceil += 50;
	else if (keycode == XK_minus)
		data->iter_ceil -= 50;
	else if (keycode == XK_s || keycode == XK_S)
	{
		if (data-> sharpness < 2048)
			data->sharpness += 10;
	}
	else if (keycode == XK_d || keycode == XK_D)
		if (data-> sharpness > 50)
			data->sharpness -= 10;
	fractal_render(data);
	return (0);
}

int	mouse_press(int button, int x, int y, t_data *data)
{
	if (button == 5)
		zoom_in(data, x, y);
	else if (button == 4)
		zoom_out(data, x, y);
	if (button == 1)
	{
		if (data->pallet == RAINBOW)
			data->pallet = MAGMA;
		else
			data->pallet = RAINBOW;
	}
	fractal_render(data);
	return (0);
}

int	exit_hook(t_data *data)
{
	free_data(data, 0);
	return (0);
}
