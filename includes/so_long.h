/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:58:50 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/27 22:15:21 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../library/libft/libft.h"
# include "../library/minilibx-linux/mlx.h"
# include <stdio.h>

# define PIXELS 50
# define ESC 65307

typedef struct s_mlx
{
    void    *ptr;
    void    *win;
    int     altura;
    int     comprimento;
    char    **map;
}   t_mlx;

void    free_all(t_mlx *mlx);
void    read_map(char *map_path, t_mlx *mlx);
void    map_width_heigh(t_mlx *mlx);

#endif
