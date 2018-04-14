/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikifor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 15:16:36 by mnikifor          #+#    #+#             */
/*   Updated: 2017/10/28 15:16:37 by mnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char const *s, int fd)
{
	int		i;
	char	*str;

	i = 0;
	if (s && fd)
	{
		str = (char *)s;
		while (str[i])
		{
			ft_putchar_fd(str[i], fd);
			i++;
		}
	}
}
