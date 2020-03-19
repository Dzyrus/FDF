#include <stdio.h>
#include "fdf.h"


int main(int ac, char **av) {

    t_fdf *fdf;
    int win_x = 1440;
    int win_y = 770;

    fdf = (t_fdf *)malloc(sizeof(t_fdf));
    fdf->mlx_ptr = mlx_init();
    fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, win_x, win_y, "FDF");

    mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, win_x / 2, win_y / 2, 0xe80c0c);
    mlx_pixel_put(fdf->mlx_ptr, fdf->win_ptr, win_x / 2 + 100, win_y / 2, 0xe80c0c);
    mlx_loop(fdf->mlx_ptr);

    read_file(av[1], fdf);
    return 0;
}
