/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:45:02 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/11/08 22:48:12 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*ft_sharp(t_type f)
{
	if (f.specifier == 'X')
		return ("0X");
	return ("0x");
}

static int	ft_recursive_hex(t_type f, size_t n, size_t iter)
{
	int		count;
	int		remainder;
	char	ch;

	count = 0;
	if (n > 0 || (!iter && (f.specifier != 'p' || !f.dot)))
	{
		remainder = n % 16;
		if (f.specifier != 'X')
			ch = HEXLOW[remainder];
		else
			ch = HEXUPP[remainder];
		n /= 16;
		iter = 1;
		count += ft_recursive_hex(f, n, iter);
		count += ft_putchar_fd(ch, 1);
	}
	return (count);
}

int	ft_print_x(t_type f, va_list *ap)
{
	unsigned int	n;
	int				count;
	int				len;

	count = 0;
	n = va_arg(*ap, unsigned int);
	len = ft_nbrlen(n, 16);
	if (!n && !f.precision && f.dot)
		len = 0;
	if (f.precision < 0 || f.precision < len || !f.dot)
		f.precision = len;
	if (f.sharp && n)
		f.width -= 2;
	count += ft_putstr_n_fd(ft_sharp(f), 1, 2 * (f.sharp && f.f_zero && n));
	if (!f.f_minus && f.width > f.precision && (!f.dot || f.neg) && f.f_zero)
		count += ft_putchar_n_fd('0', 1, (f.width - f.precision));
	else if (!f.f_minus && f.width > f.precision)
		count += ft_putchar_n_fd(' ', 1, (f.width - f.precision));
	count += ft_putstr_n_fd(ft_sharp(f), 1, 2 * (f.sharp && !f.f_zero && n));
	count += ft_putchar_n_fd('0', 1, (f.precision - len));
	if (len)
		count += ft_recursive_hex(f, n, n);
	if (f.f_minus && f.width > f.precision)
		count += ft_putchar_n_fd(' ', 1, f.width - f.precision);
	return (count);
}

int	ft_print_p(t_type f, va_list *ap)
{
	long long	n;
	int			count;
	int			len;

	count = 0;
	n = va_arg(*ap, long long);
	len = ft_nbrlen(n, 16);
	len *= !(!n && !f.precision && f.dot);
	if (f.precision < len || !f.dot)
		f.precision = len;
	count += write(1, "0x", 2 * f.f_zero);
	f.width -= 2;
	if (!f.f_minus && f.width > f.precision && !f.dot && f.f_zero)
		count += ft_putchar_n_fd('0', 1, (f.width - f.precision));
	else if (!f.f_minus && f.width > f.precision)
		count += ft_putchar_n_fd(' ', 1, (f.width - f.precision));
	count += write(1, "0x", 2 * !f.f_zero);
	count += ft_putchar_n_fd('0', 1, (f.precision - len) * (n != 0));
	count += ft_putchar_n_fd('0', 1, f.precision * (f.dot && !n));
	if (len)
		count += ft_recursive_hex(f, n, n);
	if (f.f_minus && f.width > f.precision)
		count += ft_putchar_n_fd(' ', 1, f.width - f.precision);
	return (count);
}
