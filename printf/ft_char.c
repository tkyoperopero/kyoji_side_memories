/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:45:02 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/11/08 22:48:37 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_c_per(t_type f, va_list *ap)
{
	char	ch;
	int		cnt;

	cnt = 0;
	if (f.specifier == 'c')
		ch = va_arg(*ap, int);
	else
		ch = '%';
	f.precision = 1;
	if (!f.f_minus && f.f_zero)
		cnt += ft_putchar_n_fd('0', 1, f.width - f.precision);
	else if (!f.f_minus && f.width > f.precision)
		cnt += ft_putchar_n_fd(' ', 1, f.width - f.precision);
	cnt += ft_putchar_fd(ch, 1);
	if (f.f_minus && f.width - f.precision > 0)
		cnt += ft_putchar_n_fd(' ', 1, f.width - f.precision);
	return (cnt);
}

int	ft_print_s(t_type f, va_list *ap)
{
	char	*str;
	int		cnt;

	cnt = 0;
	str = va_arg(*ap, char *);
	if (!str)
		str = "(null)";
	if (!f.dot || f.precision > (int)ft_strlen(str) || f.precision < 0)
		f.precision = ft_strlen(str);
	if (!f.f_minus && f.width > f.precision && f.f_zero && (!f.dot || f.neg))
		cnt += ft_putchar_n_fd('0', 1, f.width - f.precision);
	else if (!f.f_minus && f.width - f.precision > 0)
		cnt += ft_putchar_n_fd(' ', 1, f.width - f.precision);
	cnt += ft_putstr_n_fd(str, 1, f.precision);
	if (f.f_minus && f.width - f.precision > 0)
		cnt += ft_putchar_n_fd(' ', 1, f.width - f.precision);
	return (cnt);
}
