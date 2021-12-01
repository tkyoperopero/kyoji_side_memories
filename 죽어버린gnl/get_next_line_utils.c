/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:10:38 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/07/01 14:20:19 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char		*ft_strdup(char *str)
{
	char	*arr;
	size_t	len;
	size_t	i;

	len = ft_strlen(str);
	if (!(arr = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	i = 0;
	while (i < len)
	{
		arr[i] = str[i];
		i++;
	}
	arr[i] = '\0';
	return (arr);
}

char		*ft_strchr(const char *str, int n)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)n)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == (char)n)
		return ((char *)&str[i]);
	return (0);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	l;
	size_t	i;

	if (!s)
		return (0);
	if ((unsigned int)ft_strlen(s) <= start)
		return (ft_strdup(""));
	else
	{
		l = ft_strlen(s + start);
		if (l < len)
			len = l;
		if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
			return (0);
		i = 0;
		while (s[i])
		{
			str[i] = s[start + i];
			i++;
		}
		str[i] = '\0';
	}
	return (str);
}

char		*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	one;
	size_t	two;
	size_t	i;

	if (!s1 || !s2)
		return (0);
	one = ft_strlen(s1);
	two = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (one + two + 1));
	if (!str)
		return (0);
	i = 0;
	while (i++ < one)
		str[i] = s1[i];
	i = 0;
	while (i < two)
		str[one++] = s2[i++];
	str[one] = '\0';
	return (str);
}
