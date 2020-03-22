//
// Created by Daria on 22/03/2020.
//
#include "fdf.h"

void print_menu(t_fdf *fdf)
{
    char *title;
    title = "press +/- to zoom";
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1000, 10, 0x03fc35, title);
    title = "press R to reset";
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1000, 30, 0x03fc35, title);
    title = "press ESC to exit";
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1000, 50, 0x03fc35, title);
    title = "press I to change POV";
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1000, 70, 0x03fc35, title);
    title = "use WASD to move image";
    mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 1000, 90, 0x03fc35, title);
}