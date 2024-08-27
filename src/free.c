/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:36:21 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/27 22:02:26 by jquicuma         ###   ########.fr       */
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

void    free_all(t_mlx *mlx)
{
    free_map(mlx->map);
    mlx_destroy_window(mlx->ptr, mlx->win);
    mlx_destroy_display(mlx->ptr);
    free(mlx->ptr);
    exit(EXIT_SUCCESS);
}
