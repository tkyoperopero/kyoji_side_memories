/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiyoulee <jiyoulee@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 11:47:53 by jiyoulee          #+#    #+#             */
/*   Updated: 2021/05/21 22:40:03 by jiyoulee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int a)
{
	if (a >= 'A' && a <= 'Z')
		return (a + 32);
	return (a);
}
