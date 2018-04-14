/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikifor <mnikifor@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 13:35:00 by mnikifor          #+#    #+#             */
/*   Updated: 2018/04/12 14:31:08 by user00           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

int		new_f(int j, char *line, int y)
{
	if (ft_isdigit(line[j]))
		return (ft_atoi(line + j));
	else
		return (y);
}

void	check_coord(int x, int y, char *line, int i)
{
	int j;

	i++;
	j = i;
	while (line[i] && line[i] != ' ')
	{
		if (ft_isdigit(line[i]) == 0)
			error();
		i++;
	}
	if (line[i] == '\0')
		error();
	i++;
	if (ft_isdigit(line[j]))
		x = ft_atoi(line + j);
	j = i;
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 0)
			error();
		i++;
	}
	y = new_f(j, line, y);
	if (x < 0 || y < 0)
		error();
}

void	check_se(char **ants, char **line, t_print_l ***f_line)
{
	int			i;
	t_print_l	**temp;

	temp = *f_line;
	get_next_line(0, &(*line));
	while (*line[0] == '#')
	{
		*temp = add_line(*temp, *line);
		free(*line);
		get_next_line(0, &(*line));
	}
	i = 0;
	while ((*line)[i] && (*line)[i] != ' ')
		i++;
	*ants = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while ((*line)[i] && (*line)[i] != ' ')
	{
		(*ants)[i] = (*line)[i];
		i++;
	}
	(*ants)[i] = '\0';
	check_coord(-42, -42, *line, i);
}

int		check_rooms(t_tops *tops)
{
	t_tops	*tmp_t;
	t_tops	*temp;

	tmp_t = tops;
	while (tmp_t->next)
	{
		temp = tmp_t->next;
		while (temp->next)
		{
			if (ft_strcmp(tmp_t->name, temp->name) == 0)
				return (0);
			if (tmp_t->x == temp->x && tmp_t->y == temp->y)
				return (0);
			temp = temp->next;
		}
		tmp_t = tmp_t->next;
	}
	return (1);
}

int		check_links(t_links *links, t_tops *top)
{
	t_links *tmp_l;
	t_tops	*temp;

	tmp_l = links;
	while (tmp_l->next)
	{
		temp = top;
		while (temp->next)
		{
			if (ft_strcmp(temp->name, tmp_l->to) == 0)
				break ;
			temp = temp->next;
		}
		if (temp->next == NULL)
			return (0);
		tmp_l = tmp_l->next;
	}
	return (1);
}
