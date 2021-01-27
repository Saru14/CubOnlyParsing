/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: namenega <namenega@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 17:55:41 by namenega          #+#    #+#             */
/*   Updated: 2021/01/06 18:18:49 by namenega         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

/*
** cpyline = on copie statik dans line
*/

static char	*ft_cpyline(char *statik)
{
	int		i;
	char	*line;

	i = 0;
	while (statik && statik[i] && statik[i] != '\n')
		i++;
	if (!(line = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (statik && statik[i] && statik[i] != '\n')
	{
		line[i] = statik[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

/*
** on ecrit la fin de la statik dans str (apres \n)
*/

static char	*ft_reline(char *s1, int *ret, int a)
{
	char	*str;
	int		i;

	*ret = 0;
	if ((i = ft_endline(s1)) < 0)
	{
		if (i == -1)
			free(s1);
		return (0);
	}
	if (!(str = (char *)malloc(sizeof(char) * (ft_strlen2(s1) - i + 1))))
	{
		*ret = -1;
		free(s1);
		return (0);
	}
	i++;
	while (s1[i + a])
	{
		str[a] = s1[i + a];
		a++;
	}
	str[a] = '\0';
	free(s1);
	return (str);
}

int			get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*statik[OPEN_MAX] = {0};
	int			ret;

	if (!line || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	*line = NULL;
	ret = 0;
	while (ft_endline(statik[fd]) < 0 && (ret = read(fd, buf, BUFFER_SIZE)))
		if (!(statik[fd] = ft_strjoin_modified(statik[fd], buf, ret)))
			return (-1);
	if (!(*line = ft_cpyline(statik[fd])))
		return (-1);
	statik[fd] = ft_reline(statik[fd], &ret, 0);
	if (!statik[fd])
		return (ret);
	return (1);
}
