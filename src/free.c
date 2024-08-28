/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:36:21 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/27 22:48:58 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    free_map(char **map)
{
    int i;

    i = -1;
    while (map[++i])
        free(map[i]);
    free(map);
}

void    free_images(t_mlx *mlx)
{
    if (mlx->img_c)
        mlx_destroy_image(mlx->ptr, mlx->img_c);
    if (mlx->img_p)
        mlx_destroy_image(mlx->ptr, mlx->img_p);
    if (mlx->img_i)
        mlx_destroy_image(mlx->ptr, mlx->img_i);
    if (mlx->img_o)
        mlx_destroy_image(mlx->ptr, mlx->img_o);
    if (mlx->img_e)
        mlx_destroy_image(mlx->ptr, mlx->img_e);
}

void    free_all(t_mlx *mlx)
{
    free_map(mlx->map);
    free_images(mlx);
    mlx_destroy_window(mlx->ptr, mlx->win);
    mlx_destroy_display(mlx->ptr);
    free(mlx->ptr);
    exit(EXIT_SUCCESS);
}
