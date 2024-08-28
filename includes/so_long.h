/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 20:58:50 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/28 02:04:17 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../library/libft/libft.h"
# include "../library/minilibx-linux/mlx.h"
# include <stdio.h>

# define PIXELS 50
# define ESC 65307
# define R 65363
# define L 65361
# define U 65362
# define D 65364

typedef struct s_mlx
{
    void    *ptr;
    void    *win;
    void    *img_p;
    void    *img_o;
    void    *img_c;
    void    *img_i;
    void    *img_e;
    int     altura;
    int     comprimento;
    char    **map;
}   t_mlx;

void    free_all(t_mlx *mlx);
void    read_map(char *map_path, t_mlx *mlx);
void    map_width_heigh(t_mlx *mlx);
void    draw_on_screen(t_mlx *mlx, char **maps);
void    player_position(int *position, char **map);
int	    player_mov(int key, t_mlx *var);
void    free_map(char **map);
int	verify_char_in_position(char **map, size_t *pos, char c);

#endif
