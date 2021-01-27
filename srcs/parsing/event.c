/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/08 17:28:35 by namenega          #+#    #+#             */
/*   Updated: 2021/01/22 18:26:45 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

// int		ft_exit_hook(void *x)
// {
// 	ft_free_data(((t_data*)x), "Task - Close Window !");
// 	return (0);
// }

// int		ft_key(int key, void *p)
// {
// 	if (key == 8)
// 	{
// 		if (!((t_data*)p))
// 	}
// }

int		ft_event(t_data *data)
{
	// mlx_hook(data->mlx_win, 17, 0, ft_exit_hook, (void*)data);
	// mlx_key_hook(data->mlx_win, ft_key, (void*)data);

	// mlx_loop_hook(mlx_ptr, &f, (void *)truc);

	// mlx_hook(win_ptr, XEVENT_KEYPRESS, 0, &f, (void *)truc);

	// mlx_hook(win_ptr, XEVENT_KEYRELEASE, 0, &f, (void *)truc);

	// mlx_hook(win_ptr, XEVENT_EXIT, 0, &f, (void *)truc);
	data->b_ground = data->b_ground;
	//mlx_loop(data->mlx_ptr);
	return (0);
}
