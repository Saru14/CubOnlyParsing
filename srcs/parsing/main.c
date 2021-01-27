/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 15:36:53 by namenega          #+#    #+#             */
/*   Updated: 2021/01/25 16:21:20 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error_exit(char *s)
{
	ft_putstr_fd(s, 1);
	write(1, "\n", 1);
	//free(data);
	exit(0);
}

int		ft_error_msg(char *s)
{
	ft_putstr_fd(s, 1);
	write(1, "\n", 1);
	return (0);
}

int		main(int ac, char const **av)
{
	t_data		*data;
	t_map		*map;
	t_pos		*pos;

	data = (t_data*)malloc(sizeof(t_data));
	map = malloc(sizeof(t_map));
	if (!map)
		return (0);
	pos = malloc(sizeof(t_pos));
	if (!pos)
		return (0);
	if (!(ac == 2 || ac == 3))
		return (ft_error_msg("Error\nToo many/few arguments.\nExit Program"));
	if (!(data = ft_data((char*)av[1], (ac == 2), map, pos, data)))
		return (ft_error_msg("Error\nParsing : Fail\nExit Program"));
	if (ac == 2)
	{
		ft_event(data);
		ft_free_data(data, "End Of Program");
	}
	/*if (ac == 3 && !ft_strncmp((char*)av[2], "-save", 6))
		ft_save(data, (char*)av[1]);*/
	return (0);
}



/*
** Mettre error si ligne random
*/