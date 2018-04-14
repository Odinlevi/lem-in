/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikifor <mnikifor@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 17:43:00 by mnikifor          #+#    #+#             */
/*   Updated: 2018/03/12 17:43:00 by mnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

void		save_coord(t_tops **temp, char *line, int i)
{
	int	j;

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
		(*temp)->x = ft_atoi(line + j);
	j = i;
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 0)
			error();
		i++;
	}
	if (ft_isdigit(line[j]))
		(*temp)->y = ft_atoi(line + j);
}

t_tops		*save_path(t_tops *top, char *line)
{
	int			i;
	static int	count = 0;
	t_tops		*temp;

	i = 0;
	temp = top;
	temp->x = -42;
	temp->y = -42;
	while (line[i] && line[i] != ' ')
		i++;
	temp->name = (char *)malloc(sizeof(char) * i + 1);
	i = 0;
	while (line[i] && line[i] != ' ')
	{
		temp->name[i] = line[i];
		i++;
	}
	temp->name[i] = '\0';
	temp->count = count++;
	save_coord(&temp, line, i);
	if (temp->x < 0 || temp->y < 0)
		error();
	if (!(temp->next = (t_tops *)malloc(sizeof(t_tops))))
		return (NULL);
	return (temp->next);
}

t_links		*save_links(t_links *links, char *line, int i, int j)
{
	t_links	*temp;

	temp = links;
	while (line[i] && line[i] != '-')
		i++;
	temp->fr = (char *)malloc(sizeof(char *) * i + 1);
	i++;
	while (line[i++])
		j++;
	temp->to = (char *)malloc(sizeof(char) * j + 1);
	i = 0;
	j = 0;
	while (line[i] && line[i] != '-')
	{
		temp->fr[i] = line[i];
		i++;
	}
	temp->fr[i] = '\0';
	i++;
	while (line[i])
		temp->to[j++] = line[i++];
	temp->to[j] = '\0';
	temp->next = (t_links *)malloc(sizeof(t_links));
	return (temp->next);
}

int			save_file(t_tops **tmp_p, t_links **tmp_l, char *line)
{
	int i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ')
		{
			*tmp_p = save_path(*tmp_p, line);
			break ;
		}
		if (line[i] == '-')
		{
			*tmp_l = save_links(*tmp_l, line, 0, 0);
			break ;
		}
		if (line[i] == 'L')
			error();
		i++;
	}
	return (i);
}

void		save_ants(t_ants **ants, t_print_l **tmp_line)
{
	int		i;
	char	*line;

	i = 0;
	if (get_next_line(0, &line) < 0 || line[0] == '\0')
		error();
	while (line[0] == '#')
	{
		*tmp_line = add_line(*tmp_line, line);
		free(line);
		get_next_line(0, &line);
	}
	while (line[i])
	{
		if (ft_isdigit(line[i]) == 0 || line[0] == '0')
			error();
		i++;
	}
	(*ants)->count_ants = ft_atoi(line);
	*tmp_line = add_line(*tmp_line, line);
	ft_strdel(&line);
}
