//
// Created by Daria on 19/03/2020.
//

#ifndef FDF_FDF_H
#define FDF_FDF_H

#include <math.h>
#include "./libft/libft.h"
#include "./minilibx_macos/mlx.h"

//gcc main.c fdf.h ./libft/libft.a ./minilibx/libmlx_intel-mac.a  -framework OpenGL -framework AppKit

typedef struct
{
    void *mlx_ptr;
    void *win_ptr;

    int x;
    int y;
    int **z_values;

}               t_fdf;

void    read_file(char *file, t_fdf *fdf);
#endif //FDF_FDF_H
