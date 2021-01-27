/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 15:20:48 by namenega          #+#    #+#             */
/*   Updated: 2021/01/26 17:23:03 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	ft_dir_to_vec(int c, t_pos *pos)
{
	if (c == 3)
	{
		pos->dir.x = 0;
		pos->dir.y = 1;
	}
	else if (c == 4)
	{
		pos->dir.x = 0;
		pos->dir.y = -1;
	}
	else if (c == 5)
	{
		pos->dir.x = -1;
		pos->dir.y = 0;
	}
	else if (c == 6)
	{
		pos->dir.x = 1;
		pos->dir.y = 0;
	}
}

void	ft_verif_holes_2(t_map *map, int i, int j)
{
	if (map->real_map[i][j] <= 7 && map->real_map[i][j] >= 2)
	{
		if (!(j < map->width - 1) || (j == 0))
			ft_error_exit("Error\nMap Error\nExit Program");
		if (!(i < map->height_tmp - 1) || (i == 0))
			ft_error_exit("Error\nMap Error\nExit Program");
		if (map->real_map[i][j - 1] == -1)
			ft_error_exit("Error\nMap Error\nExit Program");
		if (map->real_map[i][j + 1] == -1)
			ft_error_exit("Error\nMap Error\nExit Program");
		if (map->real_map[i + 1][j] == -1)
			ft_error_exit("Error\nMap Error\nExit Program");
		if (map->real_map[i - 1][j] == -1)
			ft_error_exit("Error\nMap Error\nExit Program");
	}
}

int		ft_verif_holes(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->height_tmp)
	{
		j = 0;
		while (j < map->width)
		{
			ft_verif_holes_2(map, i, j);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_verif_char(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->height_tmp)
	{
		j = 0;
		while (j < map->width)
		{
			if (map->real_map[i][j] > 7 || map->real_map[i][j] < -1)
				ft_error_exit("Error\nWrong char in map\nExit Program");
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_verif_map(t_map *map)
{
	ft_verif_char(map);
	ft_verif_holes(map);
	return (1);
}
