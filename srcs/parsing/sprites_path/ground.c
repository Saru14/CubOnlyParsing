/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ground.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:44:07 by namenega          #+#    #+#             */
/*   Updated: 2021/01/23 15:56:41 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void			ft_error_skyground_5(t_data *data)
{
	if (data->r_sky > 255 || data->r_sky < 0)
		ft_error_exit("Error\nRGB must be between 0 & 255 (C).\nExit Program");
	if (data->g_sky > 255 || data->g_sky < 0)
		ft_error_exit("Error\nRGB must be between 0 & 255 (C).\nExit Program");
	if (data->b_sky > 255 || data->b_sky < 0)
		ft_error_exit("Error\nRGB must be between 0 & 255 (C).\nExit Program");
	if (data->r_ground > 255 || data->r_ground < 0)
		ft_error_exit("Error\nRGB must be between 0 & 255 (F).\nExit Program");
	if (data->g_ground > 255 || data->g_ground < 0)
		ft_error_exit("Error\nRGB must be between 0 & 255 (F).\nExit Program");
	if (data->b_ground > 255 || data->b_ground < 0)
		ft_error_exit("Error\nRGB must be between 0 & 255 (F).\nExit Program");
}

t_data			*ft_error_ground(t_data *data)
{
	if (data->r_ground_verif != 0 || data->g_ground_verif != 0 ||
		data->b_ground_verif != 0)
		ft_error_exit("Error\nThis data (F) exists twice or more\n\
Exit Program");
	data->r_ground_verif++;
	data->g_ground_verif++;
	data->b_ground_verif++;
	return (data);
}

char			**split_rgb_ground(char *line)
{
	int		n;
	int		i;
	int		j;
	char	**strs;

	i = 0;
	j = 0;
	n = 0;
	while (line[i])
	{
		if (line[i] == ',')
			n++;
		i++;
	}
	if (n != 2)
		ft_error_exit("Error\nToo many/few ','\nExit Program");
	strs = ft_split(line, ',');
	while (strs[j])
		j++;
	if (j != 3)
		ft_error_exit("Error\nToo many/few arguments (F).\n\
Exit Program");
	return (strs);
}

void			ft_error_skyground_6(char **strs)
{
	int	i;
	int	j;

	j = 0;
	while (strs[j])
	{
		ft_empty_line(strs[j]);
		i = 0;
		strs[j] = ft_strtrim(strs[j], " \t\v\r\f");
		while (strs[j][i])
		{
			if (ft_isspace(strs[j][i]))
				ft_error_exit("Error\nToo many arguments (F/C).\n\
Exit Program");
			i++;
		}
		j++;
	}
}

/*
** We get RGB of the Floor
*/

int				ft_color_ground(t_data *data, char *line)
{
	char	**strs;

	data->parsed++;
	ft_error_skyground_1(line);
	ft_error_ground(data);
	strs = split_rgb_ground(line);
	ft_error_skyground_6(strs);
	data->r_ground = ft_atoi_2(strs[0]);
	data->g_ground = ft_atoi_2(strs[1]);
	data->b_ground = ft_atoi_2(strs[2]);
	ft_error_skyground_5(data);
	return (1);
}
