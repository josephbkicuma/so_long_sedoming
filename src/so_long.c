/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:12:01 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/27 22:16:53 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


int    key_press(int key, t_mlx *mlx)
{
    (void)mlx;
    if (key == ESC)
        free_all(mlx);
    return (0);
}

int main(int ac, char *av[])
{
    t_mlx   mlx;
    
    if (ac < 2)
        exit(EXIT_FAILURE);
    mlx.ptr = mlx_init();
    read_map(av[1], &mlx);
    map_width_heigh(&mlx);
    mlx.win = mlx_new_window(mlx.ptr, mlx.comprimento * PIXELS, mlx.altura * PIXELS, "5 ATG");
    printf("A: %d\nC: %d\n", mlx.altura, mlx.comprimento);
    mlx_key_hook(mlx.win, key_press, &mlx);
    mlx_loop(mlx.ptr);
    return (0);
}
