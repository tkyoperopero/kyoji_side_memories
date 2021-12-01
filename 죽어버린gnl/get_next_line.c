/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:09:43 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/07/01 14:12:51 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		save_line(char **line, char **save)
{
	char		*tem;
	char		*new;

	if ((new = ft_strchr(*save, '\n')) != 0)
	{
		tem = *line;
		*line = ft_substr(*save, 0, new - *save);
		free(tem);
		if (!(*line))
			return (-1);
		tem = *save;
		*save = ft_substr(new + 1, 0, ft_strlen(new + 1));
		free(tem);
		if (!(*save))
			return (-1);
		return (1);
	}
	else
	{
		tem = *line;
		*line = *save;
		*save = NULL;
		free(tem);
		return (-2);
	}
}

static int		split_line(char **line, char **save, char *buff)
{
	char		*now;
	char		*tem;
	char		*new;

	new = ft_strchr(buff, '\n');
	if (!(tem = ft_substr(buff, 0, new - buff)))
		return (-1);
	now = *line;
	*line = ft_strjoin(*line, tem);
	free(now);
	free(tem);
	if (!(*line))
		return (-1);
	if (!(*save = ft_substr(new + 1, 0, ft_strlen(new + 1))))
		return (-1);
	return (1);
}

static int		line_buff(char **line, char *buff)
{
	char		*tem;

	tem = *line;
	*line = ft_strjoin(*line, buff);
	free(tem);
	if (!(*line))
		return (-1);
	return (-2);
}

static int		reading(int fd, char **line, char **save)
{
	ssize_t		size;
	int			ret;
	char		*buff;

	ret = -2;
	if (!(buff = malloc(BUFFER_SIZE + 1)))
		return (-1);
	while (ret == -2 && (size = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[size] = '\0';
		if (ft_strchr(buff, '\n'))
			ret = split_line(line, save, buff);
		else
			ret = line_buff(line, buff);
	}
	free(buff);
	if (ret == -2 && size == 0)
		ret = 0;
	else if (ret == -2 && size == -1)
		ret = -1;
	return (ret);
}

int				get_next_line(int fd, char **line)
{
	int			ret;
	static char	*save;

	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !(*line = ft_strdup("")))
		return (-1);
	ret = -2;
	if (save)
		ret = save_line(line, &save);
	if (ret == -2)
		ret = reading(fd, line, &save);
	return (ret);
}
