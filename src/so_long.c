/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:12:01 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/28 02:04:45 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


int    key_press(int key, t_mlx *mlx)
{
    (void)mlx;
    if (key == ESC)
        free_all(mlx);
    else
        player_mov(key, mlx);
    return (0);
}

void    import_images(t_mlx *mlx)
{
    int i;

    i  = 50;
    mlx->img_c = mlx_xpm_file_to_image(mlx->ptr, "./assets/C.xpm", &i, &i);
    mlx->img_o = mlx_xpm_file_to_image(mlx->ptr, "./assets/0.xpm", &i, &i);
    mlx->img_i = mlx_xpm_file_to_image(mlx->ptr, "./assets/1.xpm", &i, &i);
    mlx->img_p = mlx_xpm_file_to_image(mlx->ptr, "./assets/P.xpm", &i, &i);
    mlx->img_e = mlx_xpm_file_to_image(mlx->ptr, "./assets/E.xpm", &i, &i);
}

int main(int ac, char *av[])
{
    t_mlx   mlx;
    
    if (ac < 2)
        exit(EXIT_FAILURE);
    mlx.ptr = mlx_init();
    read_map(av[1], &mlx);
    map_width_heigh(&mlx);
    import_images(&mlx);
    mlx.win = mlx_new_window(mlx.ptr, mlx.comprimento * PIXELS, mlx.altura * PIXELS, "5 ATG");
    draw_on_screen(&mlx, mlx.map);
    mlx_key_hook(mlx.win, key_press, &mlx);
    mlx_loop(mlx.ptr);
    return (0);
}
