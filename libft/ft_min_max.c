/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min_max.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikifor <mnikifor@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:07:00 by mnikifor          #+#    #+#             */
/*   Updated: 2018/03/05 15:07:00 by mnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_fnd_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int		ft_fnd_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
