/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikifor <mnikifor@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 17:30:44 by mnikifor          #+#    #+#             */
/*   Updated: 2018/01/11 15:56:10 by mnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(int n)
{
	int len;

	len = 0;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int		ft_intlen_u(unsigned long long n)
{
	int len;

	len = 0;
	if (n == 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}
