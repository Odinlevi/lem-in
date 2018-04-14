/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikifor <mnikifor@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 15:47:00 by mnikifor          #+#    #+#             */
/*   Updated: 2018/02/19 15:47:00 by mnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void		to_arr(t_temp_var *temp, int **arr, int i, int j)
{
	while (temp->temp_l->next)
	{
		if (((ft_strcmp(temp->temp_p->name, temp->temp_l->fr) == 0) &&
			(ft_strcmp(temp->temp_j->name, temp->temp_l->to) == 0)) ||
			((ft_strcmp(temp->temp_p->name, temp->temp_l->to) == 0) &&
			(ft_strcmp(temp->temp_j->name, temp->temp_l->fr) == 0)))
		{
			arr[i][j] = 1;
			break ;
		}
		else
			arr[i][j] = 0;
		temp->temp_l = temp->temp_l->next;
	}
}

int			**to_matr(t_tops *top, t_links *links, int i, int j)
{
	int			**arr;
	int			len;
	t_temp_var	temp;

	len = len_pt(top);
	arr = (int **)malloc(sizeof(int *) * len);
	i = 0;
	temp.temp_p = top;
	while (i < len && temp.temp_p->next)
	{
		j = 0;
		temp.temp_j = top;
		arr[i] = (int *)malloc(sizeof(int) * len);
		while (j < len && temp.temp_j->next)
		{
			temp.temp_l = links;
			to_arr(&temp, arr, i, j);
			j++;
			temp.temp_j = temp.temp_j->next;
		}
		i++;
		temp.temp_p = temp.temp_p->next;
	}
	return (arr);
}

t_uniq_path	*save_way(t_uniq_path *way, int i, int len, t_find_paths *tops)
{
	t_uniq_path *tmp;

	tmp = way;
	tmp->a_way = (int *)malloc(sizeof(int) * (len));
	tmp->len = len;
	while (i < len)
	{
		tmp->a_way[i] = tops->path[i];
		i++;
	}
	tmp->next = (t_uniq_path *)malloc(sizeof(t_uniq_path));
	return (tmp->next);
}

void		*dfs(int s, t_find_paths *tops, int *path_index, t_uniq_path **mas)
{
	int			i;
	t_uniq_path	*tmp;

	tops->visited[s] = 1;
	tops->path[*path_index] = s;
	*path_index = *path_index + 1;
	tmp = *mas;
	i = 0;
	if (s == tops->e)
		tmp = save_way(tmp, i, *path_index, tops);
	else
		while (i < tops->len)
		{
			if (tops->arr[s][i] && !tops->visited[i])
				tmp = dfs(i, tops, path_index, &tmp);
			i++;
		}
	*path_index = *path_index - 1;
	tops->visited[s] = 0;
	return (tmp);
}

void		*find_all_paths(t_find_paths *tops, t_uniq_path *ways)
{
	t_uniq_path		*temp;
	int				i;

	tops->visited = (int *)malloc(sizeof(int) * tops->len);
	tops->path = (int *)malloc(sizeof(int) * tops->len);
	tops->path_index = 0;
	i = 0;
	temp = ways;
	while (i < tops->len)
		tops->visited[i++] = 0;
	temp = dfs(tops->s, tops, &tops->path_index, &temp);
	temp->next = NULL;
	return (ways);
}
