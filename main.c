#include "fdf.h"

int deal_key(int key,t_fdf *fdf)
{
    if(key == 24)
        fdf->zoom += 5;
    if(key == 27)
        if(fdf->zoom - 5 >= 0)
            fdf->zoom -= 5;
    if(key == 15)
        reset(fdf);
    if(key == 34)
        fdf->iso = fdf->iso > 0 ? -1 : 1;
    if (key == 13)
        if(fdf->y + fdf->win_y / 2 + fdf->y_offset > 46)
            fdf->y_offset -= 50;
    if (key == 0)
        if(fdf->x + fdf->win_x / 3 + fdf->x_offset > 249)
            fdf->x_offset -= 50;
    if(key == 1)
        if(fdf->y + fdf->win_y / 2  + fdf->y_offset < 596)

            fdf->y_offset += 50;
    if (key == 2)

        if(fdf->x + fdf->win_x / 3 + fdf->x_offset < 1099)
            fdf->x_offset += 50;
    if(key == 53)
    {
        mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
        free(fdf);
        exit(0);
    }
    mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
    print_menu(fdf);
    draw_map(fdf);
    printf("%d\n", key);
    return(0);
}
int main(int ac, char **av)
{
    t_fdf *fdf;

    fdf = (t_fdf *)malloc(sizeof(t_fdf));
    read_file(av[1], fdf);
    reset(fdf);
    fdf->mlx_ptr = mlx_init();
    fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, (int)fdf->win_x, (int)fdf->win_y,"FDF");
    print_menu(fdf);
    draw_map(fdf);
    mlx_key_hook(fdf->win_ptr, deal_key, fdf);
    mlx_loop(fdf->mlx_ptr);
    return(0);
}
