/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jquicuma <jquicuma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 23:27:19 by jquicuma          #+#    #+#             */
/*   Updated: 2024/08/28 02:04:10 by jquicuma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../includes/so_long.h"

static int	is_valid_position(char c, t_mlx *var)
{
    (void)var;
	if (c == '0')
		return (1);
	else if (c == '1')
		return (0);
	else if (c == 'C')
		return (1);
	return (0);
}

static int	check(t_mlx *var, int key, size_t *pos)
{
	int	new_x;
	int	new_y;

	new_x = pos[1];
	new_y = pos[0];
	if (key == R)
		new_x += 1;
	else if (key == L)
		new_x -= 1;
	else if (key == U)
		new_y -= 1;
	else if (key == D)
		new_y += 1;
	if (is_valid_position(var->map[new_y][new_x], var))
	{
		var->map[new_y][new_x] = 'P';
		var->map[pos[0]][pos[1]] = '0';
		return (1);
	}
	return (0);
}

int	player_mov(int key, t_mlx *var)
{
	size_t		pos[2];

	verify_char_in_position(var->map, pos, 'P');
	check(var, key, pos);
	draw_on_screen(var, var->map);
	return (1);
}


int	verify_char_in_position(char **map, size_t *pos, char c)
{
	size_t	heigh;
	size_t	width;

	heigh = -1;
	while (map[++heigh])
	{
		width = -1;
		while (map[heigh][++width])
		{
			if (map[heigh][width] == c)
			{
				pos[0] = heigh;
				pos[1] = width;
				return (1);
			}
		}
	}
	return (0);
}