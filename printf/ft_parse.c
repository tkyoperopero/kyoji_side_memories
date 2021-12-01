/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:45:02 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/10/04 20:33:14 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_type	ft_reset(void)
{
	t_type	new;

	new.f_minus = 0;
	new.f_zero = 0;
	new.width = 0;
	new.precision = 0;
	new.neg = 0;
	new.specifier = 0;
	new.dot = 0;
	new.plus = 0;
	new.space = 0;
	new.sharp = 0;
	new.sign = 0;
	return (new);
}

static	t_type	ft_parse_bonus(char *str, t_type f)
{
	while (*str != '.' && !ft_strchr(SPECIFIERS, *str))
	{
		if (*str == '+')
			f.plus = 1;
		if (*str == ' ')
			f.space = 1;
		if (*str == '#')
			f.sharp = 1;
		str++;
	}
	return (f);
}

static t_type	ft_parse_width(char *str, t_type f)
{
	int	sp;

	sp = 0;
	while (*str != '.' && !ft_strchr(SPECIFIERS, *str))
	{
		if (*str == '-')
			f.f_minus = 1;
		if (*str == '0' && !ft_isdigit(*(str - 1)))
			f.f_zero = 1;
		else if ((*str > '0' && *str <= '9') && !sp)
		{
			f.width = ft_atoi(str);
			sp = 1;
		}
		str++;
	}
	return (f);
}

static t_type	ft_parse_precision(char *str, t_type f)
{
	int	sp;

	sp = 0;
	while (!ft_strchr(SPECIFIERS, *str))
	{
		if (ft_isdigit(*str) && !sp)
		{
			f.precision = ft_atoi(str);
			sp = 1;
		}
		str++;
	}
	return (f);
}

int	ft_parse(char *str, va_list *ap)
{
	t_type	new;

	new = ft_parse_width(str, ft_reset());
	new = ft_parse_bonus(str, new);
	while (!ft_strchr(SPECIFIERS, *str) && *str != '.')
		str++;
	if (*str == '.' && !new.specifier)
	{
		new.dot = 1;
		new = ft_parse_precision(str + 1, new);
		while (!ft_strchr(SPECIFIERS, *str))
			str++;
	}
	if (new.width < 0)
	{
		new.f_minus = 1;
		new.width *= -1;
	}
	new.specifier = *str;
	new.neg = new.precision < 0;
	return (ft_print_format(new, ap));
}
