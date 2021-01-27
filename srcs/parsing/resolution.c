/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolution.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:42:59 by namenega          #+#    #+#             */
/*   Updated: 2021/01/22 18:41:02 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

unsigned long int	ft_uli_error(const char *line)
{
	int					i;
	unsigned long int	result;

	i = 0;
	result = 0;
	while (ft_isdigit(line[i]))
		i++;
	if (i >= 11)
		result = 2147483647;
	else
	{
		i = 0;
		while (line[i] != '\0' && line[i] >= '0' && line[i] <= '9')
		{
			result = result * 10 + (line[i] - '0');
			i++;
		}
	}
	return (result);
}

void				ft_error_resolution_4(char *line)
{
	int	i;

	i = 0;
	if (line[i])
	{
		while (line[i])
		{
			if (!ft_isspace(line[i]))
				ft_error_exit("Error\nToo many arguments(R).\nExit Program");
			i++;
		}
	}
}

void				ft_error_resolution_3(char *line)
{
	if (!(*line))
		ft_error_exit("Error\nMissing an argument(R).\nExit Program");
	while (ft_isspace(*line))
		line++;
	if (!ft_isdigit(*line))
		ft_error_exit("Error\nMissing an argument(R).\nExit Program");
}

void				ft_error_resolution_1(char *line)
{
	int		i;

	i = 0;
	while (line[i])
	{
		if (!ft_isdigit(line[i]) && !ft_isspace(line[i]))
			ft_error_exit("Error\nOnly digits & whitespaces allowed(R).\n\
Exit Program");
		i++;
	}
}

/*
** We get the width & the height of the window's resolution
*/

int					ft_resolution(t_data *data, char *line)
{
	int		x;
	int		y;

	data->parsed++;
	mlx_get_screen_size(data->mlx_ptr, &x, &y);
	ft_error_resolution_1(line);
	if (data->width_verif != 0 || data->height_verif != 0)
		ft_error_exit("Error\nThis data (R) exists twice or more\n\
Exit Program");
	data->width_verif++;
	data->height_verif++;
	data->width = ft_atoi_2(line);
	if (data->width > x)
		data->width = x;
	line += ft_next_arg(line);
	ft_error_resolution_3(line);
	data->height = ft_atoi_2(line);
	if (data->height > y)
		data->height = y;
	line += ft_next_arg(line);
	ft_error_resolution_4(line);
	if (!data->height || !data->width)
		return (0);
	return (1);
}
