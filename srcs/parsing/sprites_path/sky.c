/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:41:43 by namenega          #+#    #+#             */
/*   Updated: 2021/01/23 15:56:59 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void		ft_empty_line(char *strs)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (strs[i] != '\0')
	{
		if (strs[i] >= '0' && strs[i] <= '9')
			x++;
		i++;
	}
	if (x == 0)
		ft_error_exit("Error\nMissing an argument (F/C)\nExit Program");
}

t_data		*ft_error_sky_2(t_data *data)
{
	if (data->r_sky_verif != 0 || data->g_sky_verif != 0 ||
data->b_sky_verif != 0)
		ft_error_exit("Error\nThis data (C) exists twice or more\n\
Exit Program");
	data->r_sky_verif++;
	data->g_sky_verif++;
	data->b_sky_verif++;
	return (data);
}

void		ft_error_skyground_1(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && !ft_isspace(line[i]) && line[i] != ',')
			ft_error_exit("Error\nOnly digits & whitespaces allowed(C).\n\
Exit Program");
		i++;
	}
}

/*
** We get RGB of the Cellar
*/

int			ft_color_sky(t_data *data, char *line)
{
	char	**strs;

	data->parsed++;
	ft_error_skyground_1(line);
	ft_error_sky_2(data);
	strs = split_rgb_ground(line);
	ft_error_skyground_6(strs);
	data->r_sky = ft_atoi_2(strs[0]);
	data->g_sky = ft_atoi_2(strs[1]);
	data->b_sky = ft_atoi_2(strs[2]);
	ft_error_skyground_5(data);
	return (1);
}
