/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obstacle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 17:44:57 by namenega          #+#    #+#             */
/*   Updated: 2021/01/20 17:41:06 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

/*
** We get here the string of obstacle_sprite's path
*/

int			ft_sprite(t_data *data, char *line)
{
	int		i;

	i = 0;
	data->parsed++;
	if (data->path_sprite_verif != 0)
		ft_error_exit("Error\nThis data (S) exists twice or more\n\
Exit Program");
	data->path_sprite_verif++;
	data->path_sprite = ft_strtrim(line, " \t\v\r\f");
	while (data->path_sprite[i])
	{
		if (ft_isspace(data->path_sprite[i]))
			ft_error_exit("Error\nToo many arguments(S).\nExit Program");
		i++;
	}
	if (data->path_sprite == NULL)
		return (0);
	else
		return (1);
}
