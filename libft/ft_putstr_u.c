/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikifor <mnikifor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 15:33:14 by mnikifor          #+#    #+#             */
/*   Updated: 2018/01/11 15:56:00 by mnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putchar_u(unsigned char c)
{
	write(1, &c, 1);
	return (1);
}

int		ft_putstr_u(unsigned char *s)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (s[i])
	{
		count += ft_putchar_u(s[i]);
		i++;
	}
	return (count);
}
