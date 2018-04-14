/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_del.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikifor <mnikifor@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 18:19:00 by mnikifor          #+#    #+#             */
/*   Updated: 2018/03/05 18:19:00 by mnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

t_uniq_path		*get_nth(t_uniq_path *head, t_uniq_path *temp)
{
	int counter;

	counter = 0;
	while (head->next != temp)
	{
		head = head->next;
		counter++;
	}
	return (head);
}

void			delete_nth(t_uniq_path **head, t_uniq_path *temp)
{
	t_uniq_path *prev;
	t_uniq_path *elm;

	if (head == NULL)
		return ;
	else
	{
		prev = get_nth(*head, temp);
		elm = prev->next;
		prev->next = elm->next;
		free(elm->a_way);
		free(elm);
	}
}

void			*del_not_unique(t_uniq_path *ways)
{
	t_uniq_path	*temp;
	t_uniq_path	*a_tmp;
	int			j;

	temp = ways;
	j = 0;
	while (temp)
	{
		a_tmp = temp->next;
		j++;
		while (a_tmp)
		{
			if (find_un_arr(temp, a_tmp))
				delete_nth(&ways, a_tmp);
			a_tmp = a_tmp->next;
			j++;
		}
		temp = temp->next;
	}
	free(temp);
	return (ways);
}

void			sort_list(t_uniq_path **temp, t_uniq_path **out,
						t_uniq_path **current, t_uniq_path **prev)
{
	if (*current == NULL)
	{
		(*temp)->next = *out;
		*out = *temp;
	}
	else
	{
		(*temp)->next = *prev;
		(*current)->next = *temp;
	}
}

t_uniq_path		*sort_ways(t_uniq_path *ways)
{
	t_uniq_path *temp;
	t_uniq_path *out;
	t_uniq_path *prev;
	t_uniq_path *current;

	out = NULL;
	while (ways->next != NULL)
	{
		temp = ways;
		ways = ways->next;
		prev = out;
		current = NULL;
		while (prev && temp->len > prev->len)
		{
			current = prev;
			prev = prev->next;
		}
		sort_list(&temp, &out, &current, &prev);
	}
	free(ways);
	return (out);
}
