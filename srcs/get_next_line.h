/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:57:22 by namenega          #+#    #+#             */
/*   Updated: 2021/01/06 18:00:21 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <limits.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);
int		ft_strlen2(char *s);
char	*ft_strjoin_modified(char *s1, char *s2, int ret);
int		ft_endline(char *s);

#endif
