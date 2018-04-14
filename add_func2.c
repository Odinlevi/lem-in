/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikifor <mnikifor@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 15:22:00 by mnikifor          #+#    #+#             */
/*   Updated: 2018/03/12 15:22:00 by mnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void		zero_par(t_ants *ants)
{
	ants->start = NULL;
	ants->end = NULL;
	ants->count_ants = 0;
}

void		check_error(t_tops *top, t_links *links, t_ants *ants)
{
	if (links->next == NULL || top->next == NULL)
		error();
	if (check_rooms(top) == 0)
		error();
	if (check_links(links, top) == 0)
		error();
	if (ants->start == NULL || ants->end == NULL)
		error();
}

t_print_l	*add_line(t_print_l *f_line, char *line)
{
	t_print_l	*temp;

	temp = f_line;
	temp->line = ft_strdup(line);
	if (!(temp->next = (t_print_l *)malloc(sizeof(t_print_l))))
		return (NULL);
	return (temp->next);
}

int			len_pt(void *temp)
{
	t_tops	*tmp;
	int		len;

	len = 0;
	tmp = temp;
	if (tmp)
	{
		while (tmp->next)
		{
			len++;
			tmp = tmp->next;
		}
	}
	return (len);
}

int			find_un_arr(t_uniq_path *a, t_uniq_path *b)
{
	int i;
	int j;

	i = 1;
	while (i < ft_fnd_min(a->len, b->len) - 1)
	{
		j = 1;
		while (j < ft_fnd_max(a->len, b->len) - 1)
		{
			if (a->a_way[i] == b->a_way[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
