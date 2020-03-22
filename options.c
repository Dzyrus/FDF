//
// Created by Daria on 22/03/2020.
//

#include "fdf.h"

void reset(t_fdf *fdf)
{
    fdf->win_x = 1440;
    fdf->win_y = 770;
    fdf->zoom = 20;
    fdf->iso = 1;
    fdf->x_offset = 0;
    fdf->y_offset = 0;
//    fdf->mlx_ptr = mlx_init();
//    fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->win_x, fdf->win_y,"FDF");
}