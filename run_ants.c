/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_ants.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikifor <mnikifor@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:17:00 by mnikifor          #+#    #+#             */
/*   Updated: 2018/02/21 16:17:00 by mnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

char	*n_t(t_tops *top, int name)
{
	t_tops		*top_tmp;

	top_tmp = top;
	while (top_tmp)
	{
		if (top_tmp->count == name)
			return (top_tmp->name);
		top_tmp = top_tmp->next;
	}
	return (NULL);
}

int		fnd_j(t_uniq_path **ways, int n)
{
	int i;
	int j;

	i = 0;
	while (*ways)
	{
		j = 0;
		while (j < (*ways)->len)
		{
			if ((*ways)->a_way[j] == n)
				return (i);
			i++;
			j++;
		}
		i = 0;
		*ways = (*ways)->next;
	}
	return (i);
}

int		free_way(int n, int *arr, t_ants *ants, int end)
{
	int i;

	i = 1;
	if (n == end)
		return (1);
	while (i <= ants->count_ants)
	{
		if (arr[i] == n)
			return (0);
		i++;
	}
	return (1);
}

void	move(t_uniq_path *ways, t_tops *tops, int *arr, t_ants *ants)
{
	t_uniq_path	*w_temp;
	int			j;
	int			k;

	w_temp = ways;
	while (ants->number_a <= ants->count_ants)
	{
		k = ants->number_a++;
		while (k <= ants->count_ants)
		{
			if (w_temp == NULL)
				w_temp = ways;
			if ((j = fnd_j(&w_temp, arr[k]) + 1) >= w_temp->len)
				break ;
			if (free_way(w_temp->a_way[j], arr, ants,
						w_temp->a_way[w_temp->len - 1]))
			{
				ft_printf("L%d-%s ", k, n_t(tops, (arr[k] = w_temp->a_way[j])));
				if (w_temp != NULL)
					break ;
			}
			k++;
		}
		w_temp = w_temp->next;
	}
}

void	run_ants(t_uniq_path *ways, t_tops *top, t_ants *ants)
{
	int i;
	int *arr;
	int end;

	i = 0;
	end = ways->a_way[ways->len - 1];
	arr = (int *)malloc(sizeof(int) * (ants->count_ants + 1));
	while (i <= ants->count_ants)
		arr[i++] = ways->a_way[0];
	ants->number_a = 1;
	while (ants->number_a <= ants->count_ants)
	{
		if (arr[ants->number_a] == end)
			ants->number_a++;
		else
		{
			move(ways, top, arr, ants);
			ants->number_a = 1;
			ft_printf("\n");
		}
	}
	free(arr);
}
