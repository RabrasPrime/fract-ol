/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 11:06:01 by tjooris           #+#    #+#             */
/*   Updated: 2025/03/07 12:08:09 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

void	free_data(t_data *data)
{
	if (data->imgd.img)
		mlx_destroy_image(data->mlx, data->imgd.img);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
		mlx_destroy_display(data->mlx);
	if (data->mlx)
		free(data->mlx);
	if (errno && errno != 11)
	{
		perror("something bad happened. have fun debugging (p");
		exit(EXIT_FAILURE);
	}
	exit(EXIT_SUCCESS);
}
