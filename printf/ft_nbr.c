/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:45:02 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/11/08 22:49:11 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	sign(t_type f)
{
	if (f.sign == 1)
		return ('+');
	else if (f.sign == -1)
		return ('-');
	return (' ');
}

static int	ft_print_nbr(t_type f, char *nbr, int len, int neg)
{
	int	i;

	i = 0;
	f.width -= (f.space && !neg && !f.plus && f.width);
	if (f.sign != 0 && (neg || f.plus))
		i += ft_putchar_n_fd(sign(f), 1, f.f_zero && (!f.dot || f.neg));
	else if (f.space)
		i += ft_putchar_n_fd(' ', 1, f.f_zero && !f.dot);
	if (!f.f_minus && f.width > f.precision && (!f.dot || f.neg) && f.f_zero)
		i += ft_putchar_n_fd('0', 1, f.width - f.precision - neg - f.plus);
	else if (!f.f_minus && f.width > f.precision)
		i += ft_putchar_n_fd(' ', 1, f.width - f.precision - neg - f.plus);
	if (f.sign != 0 && (neg || f.plus))
		i += ft_putchar_n_fd(sign(f), 1, !f.f_zero || (f.dot && !f.neg));
	else if (f.space)
		i += ft_putchar_n_fd(' ', 1, !f.f_zero || f.dot);
	i += ft_putchar_n_fd('0', 1, f.precision - len);
	i += write(1, nbr, len);
	if (f.f_minus && f.width > f.precision)
		i += ft_putchar_n_fd(' ', 1, f.width - f.precision - neg - f.plus);
	return (i);
}

int	ft_print_d_i_u(t_type f, va_list *ap)
{
	char	*nbr;
	int		n;
	int		c;
	int		len;
	int		neg;

	c = 0;
	n = va_arg(*ap, int);
	if (n != 0 && n > 0)
		f.sign = 1;
	else if (n != 0 && n < 0)
		f.sign = -1;
	neg = (n < 0 && n != INT_MIN && f.specifier != 'u');
	if (neg)
		f.plus = 0;
	if (n < 0 && f.specifier != 'u')
		n *= -1;
	if (n < 0 && f.specifier == 'u')
		nbr = ft_uitoa((unsigned)n);
	else
		nbr = ft_itoa(n);
	len = ft_strlen(nbr);
	if (*nbr == '0' && !f.precision && f.dot)
		len = 0;
	if (f.precision < len || !f.dot)
		f.precision = len;
	c += ft_print_nbr(f, nbr, len, neg);
	free(nbr);
	return (c);
}
