/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prints_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikifor <mnikifor@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:23:00 by mnikifor          #+#    #+#             */
/*   Updated: 2018/03/12 18:23:00 by mnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void		print_best_way(t_uniq_path *ways, t_tops *top)
{
	t_uniq_path *temp;
	int			i;

	temp = ways;
	ft_printf("\e[1;31m  BEST WAYS\e[0m\n\n");
	while (temp)
	{
		i = 0;
		while (i < temp->len)
		{
			if (i != temp->len - 1)
				ft_printf("\e[1m%s\e[0m %S ",
					n_t(top, temp->a_way[i]), L"➠");
			else
				ft_printf("\e[1m%s\e[0m", n_t(top, temp->a_way[i]));
			i++;
		}
		ft_printf("\n");
		temp = temp->next;
	}
	ft_printf("\n\n");
}

void		print_file(t_print_l *f_line)
{
	t_print_l *temp;

	temp = f_line;
	while (temp->next)
	{
		ft_printf("%s\n", temp->line);
		temp = temp->next;
	}
	ft_printf("\n");
}

void		error(void)
{
	ft_printf("\e[1;31m ERROR !\e[0m\n");
	exit(0);
}
