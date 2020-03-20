//
// Created by Daria on 19/03/2020.
//

#include "fdf.h"

float maximum(float a, float b)
{
    return (a > b ? a : b);
}

float mod(float a)
{
    return (a > 0 ? a : -a);
}

void draw_line(float x, float y, float x1, float y1, t_fdf *fdf)
{
    float y_step;
    float x_step;
    float max;

    y_step = y1 - y;
    x_step = x1 - x;
    max = maximum(mod(y_step), mod(x_step));

    y_step /= max;
    x_step /= max;
    while((int)(x1 - x) || (int)(y1 - x))
    {
        mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, x, y, 0xffffff);
        x += x_step;
        y += y_step;
    }
}

//void draw_map(t_fdf *fdf)
//{
//    int x;
//    int y;
//
//    y = 0;
//    while(fdf->z_values[y])
//    {
//        x = 0;
//        while(fdf->z_values[y][x] != '\0')
//        {
//            if(fdf->z_values[y])
//                draw_line(fdf)
//        }
//    }
//}