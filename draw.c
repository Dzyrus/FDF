//
// Created by Daria on 19/03/2020.
//

#include "fdf.h"
#include <math.h>

float maximum(float a, float b)
{
    return (a > b ? a : b);
}

float mod(float a)
{
    return (a > 0 ? a : -a);
}

void isometric(float *x, float *y, int z)
{
    *x = (*x - *y) * cos(0.523599);
    *y = (*x + *y) * sin(0.523599) - z;
}

void draw_line(float x, float y, float x1, float y1, t_fdf *fdf)
{
    float y_step;
    float x_step;
    float max;
    int z;
    int z1;

    z = fdf->z_values[(int)y][(int)x];
    z1 = fdf->z_values[(int)y1][(int)x1];

    x *= (float)(fdf->zoom);
    x1 *= (float)(fdf->zoom);
    y *= (float)(fdf->zoom);
    y1 *= (float)(fdf->zoom);

    y_step = y1 - y;
    x_step = x1 - x;
    //isometric(&x, &y, z);
    //isometric(&x1, &y1, z1);
    max = maximum(mod(y_step), mod(x_step));
    fdf->color = (z) ? 0xe80c0c : 0xffffff;
    y_step /= max;
    x_step /= max;
    while((int)(x1 - x) || (int)(y1 - y))
    {
        mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, (int)x, (int)y, fdf->color);
        x += x_step;
        y += y_step;
    }
}

void draw_map(t_fdf *fdf)
{
    int x;
    int y;

    y = 0;
    while(y < fdf->y)
    {
        x = 0;
        while(x < fdf->x)
        {
            if(x < fdf->x - 1)
                draw_line((float)x, (float)y, (float)(x + 1), (float)y, fdf);
            if(y < fdf->y - 1)
                draw_line((float)x, (float)y, (float)x, (float)(y + 1), fdf);
            x++;
        }
        y++;
    }
}