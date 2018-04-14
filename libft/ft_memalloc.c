/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikifor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 14:31:14 by mnikifor          #+#    #+#             */
/*   Updated: 2017/10/27 14:31:15 by mnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char *fresh;

	fresh = (char *)malloc(sizeof(char) * size);
	if (fresh)
	{
		ft_bzero(fresh, size);
		return (fresh);
	}
	return (0);
}
