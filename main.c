#include <stdio.h>
#include "fdf.h"


int main(int ac, char **av) {

    t_fdf *fdf;
    int win_x = 1440;
    int win_y = 770;


    fdf = (t_fdf *)malloc(sizeof(t_fdf));
    read_file(av[1], fdf);
    fdf->mlx_ptr = mlx_init();
    fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, win_x, win_y, "FDF");


    draw_line(10, 10, 300, 600, fdf);
    mlx_loop(fdf->mlx_ptr);


}
