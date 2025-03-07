/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:53:32 by tjooris           #+#    #+#             */
/*   Updated: 2025/03/07 11:06:56 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fractol.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10)) || (argc == 4
			&& !ft_strncmp(argv[1], "julia", 5))
		|| (argc == 2 && !ft_strncmp(argv[1], "beetle", 6)))
	{
		if (!ft_strncmp(argv[1], "mandelbrot", 10))
			data.fractal = MANDELBROT;
		else if (!ft_strncmp(argv[1], "julia", 5))
			data.fractal = JULIA;
		else
			data.fractal = BEETLE;
		fractal_init(&data, argv);
		fractal_render(&data);
		mlx_loop(data.mlx);
	}
	else
		ft_error("Usage: ./fractol beetle-mandelbrot-julia <real> <imaginary>");
}
