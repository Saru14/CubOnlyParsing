/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/04 17:57:45 by namenega          #+#    #+#             */
/*   Updated: 2021/01/22 14:36:59 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "cub3d.h"
# include "get_next_line.h"
# include "../includes/libft/libft.h"

/*
** UTILS/LIB_FUNCTIONS_1.C
*/

int			ft_isspace(int c);
int			ft_atoi_2(const char *s);
int			ft_inset(int c, char *set);
int			ft_next_arg(char *l);
int			ft_next_arg_2(char *l);

#endif
