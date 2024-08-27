/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 21:29:13 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/27 22:20:07 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"


void    read_map(char *map_path, t_mlx *mlx)
{
    char    *line;
    int     fd;
    int     i;

    mlx->map = malloc(sizeof(char *) * 100);
    (void)i;
    fd = open(map_path, O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        close(fd);
        return ;
    }
    i = -1;
    line = get_next_line(fd);
    while (line != NULL)
    {
        mlx->map[++i] = ft_strdup((const char *)line);
        free(line);
        line = get_next_line(fd);
    }
    mlx->map[++i] = NULL; 
}

void    map_width_heigh(t_mlx *mlx)
{
    int i;

    i = -1;
    while (mlx->map[++i])
        ;
    mlx->altura = i;
    mlx->comprimento = ft_strlen(mlx->map[0]) - 1;
}

void    draw_on_screen(t_mlx *mlx)
{
    
}
