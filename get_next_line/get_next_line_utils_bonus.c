/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 14:09:43 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/07/27 17:23:46 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_strchr_index(const char *str, int n)
{
	unsigned char	x;
	int				i;

	i = 0;
	if (!str)
		return (-1);
	x = (unsigned char)n;
	while (str[i] != '\0')
	{
		if (str[i] == x)
			return (i);
		i++;
	}
	if (x == '\0')
		return (i);
	return (-1);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	s_len;
	size_t	i;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	i = 0;
	if (len > s_len)
		len = s_len;
	if (start >= s_len)
	{
		str = (char *)malloc(1);
		if (str == NULL)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	str = (char *)malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (i++ < start)
		s++;
	ft_strlcpy(str, s, len + 1);
	return (str);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	unsigned int	i;
	size_t			src_size;

	i = 0;
	if (src == NULL)
		return (0);
	src_size = ft_strlen(src);
	if ((int)size < 0)
		size = src_size + 1;
	if (size >= 2 && src_size != 0)
	{
		while (i < size - 1)
		{
			if (i < src_size)
				dst[i] = src[i];
			else if (i == src_size)
				dst[i] = '\0';
			i++;
		}
	}
	if (size != 0)
		dst[i] = '\0';
	return (src_size);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	dstlen;
	size_t	srclen;

	index = 0;
	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (size < dstlen + 1)
		return (srclen + size);
	while (dstlen + 1 + index < size && src[index] != '\0')
	{
		dst[index + dstlen] = src[index];
		index++;
	}
	dst[dstlen + index] = '\0';
	return (dstlen + srclen);
}
