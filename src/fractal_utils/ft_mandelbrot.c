/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mandelbrot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjooris <tjooris@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 12:40:26 by tjooris           #+#    #+#             */
/*   Updated: 2025/02/24 13:44:20 by tjooris          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

#define MAX_ITER 1000

typedef struct s_mandelbrot {
    double cx, cy;   
    double dx, dy;  
    int width, height; 
    int max_iter;    
    int *output;     
} t_mandelbrot;

typedef struct s_perturbation {
    double pert_x, pert_y;    
    double pert_zx, pert_zy;  
    double pert_zx2, pert_zy2; 
    int pert_iter;            
} t_perturbation;


void	mandelbrot_perturbation(t_mandelbrot *m) {
    double zx = 0.0, zy = 0.0;
    double zx2 = 0.0, zy2 = 0.0;
    int iter = 0;

    double ref_x = m->cx;
    double ref_y = m->cy;

    double dzx, dzy;

    while (zx2 + zy2 < 4.0 && iter < m->max_iter) {
        zy = 2.0 * zx * zy + ref_y;
        zx = zx2 - zy2 + ref_x;
        zx2 = zx * zx;
        zy2 = zy * zy;
        iter++;
    }

    dzx = zx - ref_x;
    dzy = zy - ref_y;

    t_perturbation p;

    for (int j = 0; j < m->height; j++) {
        for (int i = 0; i < m->width; i++) {
            p.pert_x = ref_x + i * m->dx;
            p.pert_y = ref_y + j * m->dy;
            p.pert_zx = p.pert_x + dzx;
            p.pert_zy = p.pert_y + dzy;
            p.pert_zx2 = p.pert_zx * p.pert_zx;
            p.pert_zy2 = p.pert_zy * p.pert_zy;
            p.pert_iter = iter;
            while (p.pert_zx2 + p.pert_zy2 < 4.0 && p.pert_iter < m->max_iter) {
                p.pert_zy = 2.0 * p.pert_zx * p.pert_zy + p.pert_y;
                p.pert_zx = p.pert_zx2 - p.pert_zy2 + p.pert_x;
                p.pert_zx2 = p.pert_zx * p.pert_zx;
                p.pert_zy2 = p.pert_zy * p.pert_zy;
                p.pert_iter++;
            }
            m->output[j * m->width + i] = p.pert_iter;
        }
    }
}
