/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:53:32 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/24 13:45:09 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/minilibx/mlx.h"

int main()
{
    void *mlx;
    void *win;

    mlx = mlx_init();
    if (!mlx)
        return (1);
    win = mlx_new_window(mlx, 800, 600, "Ma Fenêtre MLX");
    if (!win)
        return (1);
    mlx_loop(mlx);
    return (0);
}
