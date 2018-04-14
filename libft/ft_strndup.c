/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikifor <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:44:29 by mnikifor          #+#    #+#             */
/*   Updated: 2017/11/13 13:44:31 by mnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t n)
{
	char *dst;
	char *str;

	if (s1)
	{
		if (!(dst = (char*)malloc(sizeof(char) * n + 1)))
			return (NULL);
		str = (char *)s1;
		dst = ft_strncpy(dst, str, n);
		dst[n] = '\0';
		return (dst);
	}
	return (NULL);
}
