/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikifor <mnikifor@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:51:00 by mnikifor          #+#    #+#             */
/*   Updated: 2018/02/14 14:51:00 by mnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/lemin.h"

char		*fnd_se(t_ants *ants, char *line, t_print_l **f_line)
{
	if (ft_strcmp(line + 2, "start") == 0)
	{
		if (ants->start)
			error();
		*f_line = add_line(*f_line, line);
		free(line);
		check_se(&ants->start, &line, &f_line);
	}
	if (ft_strcmp(line + 2, "end") == 0)
	{
		if ((ants->end))
			error();
		*f_line = add_line(*f_line, line);
		free(line);
		check_se(&ants->end, &line, &f_line);
	}
	return (line);
}

void		top_se(t_tops *top, t_ants *ants, t_find_paths **tops)
{
	t_tops		*tmp;
	int			start;
	int			end;
	int			len;

	tmp = top;
	start = 0;
	end = 0;
	while (tmp->next)
	{
		if (ft_strcmp(tmp->name, ants->start) == 0)
			start = tmp->count;
		if (ft_strcmp(tmp->name, ants->end) == 0)
			end = tmp->count;
		tmp = tmp->next;
	}
	tmp = top;
	len = len_pt(tmp);
	(*tops)->s = start;
	(*tops)->e = end;
	(*tops)->len = len;
}

void		n_nul(t_print_l **tmp_line, t_tops **tmp_p, t_links **tmp_l)
{
	(*tmp_line)->next = NULL;
	(*tmp_p)->next = NULL;
	(*tmp_l)->next = NULL;
}

int			**read_file(t_ants *ants, t_tops **top,
						t_print_l *f_line, t_links *links)
{
	t_tops		*tmp_p;
	t_links		*tmp_l;
	t_print_l	*tmp_line;
	char		*line;

	tmp_line = f_line;
	save_ants(&ants, &tmp_line);
	tmp_p = *top;
	tmp_l = links;
	while (get_next_line(0, &line) > 0)
	{
		if (line[0] == '#' && line[1] == '#')
			line = fnd_se(ants, line, &tmp_line);
		if (line[0] != '#' && line[save_file(&tmp_p, &tmp_l, line)] == '\0')
		{
			free(line);
			break ;
		}
		tmp_line = add_line(tmp_line, line);
		free(line);
	}
	n_nul(&tmp_line, &tmp_p, &tmp_l);
	check_error(*top, links, ants);
	return (to_matr(*top, links, 0, 0));
}

int			main(void)
{
	t_create_var	*var;

	var = (t_create_var *)malloc(sizeof(t_create_var));
	zero_par(&var->ants);
	var->links = (t_links *)malloc(sizeof(t_links));
	var->f_line = (t_print_l *)malloc(sizeof(t_print_l));
	var->top = (t_tops *)malloc(sizeof(t_tops));
	var->tops = (t_find_paths *)malloc(sizeof(t_find_paths));
	var->ways = (t_uniq_path *)malloc(sizeof(t_uniq_path));
	var->tops->arr = read_file(&var->ants, &var->top, var->f_line, var->links);
	top_se(var->top, &var->ants, &var->tops);
	var->ways = find_all_paths(var->tops, var->ways);
	if (var->ways->next == NULL)
		error();
	var->ways = sort_ways(var->ways);
	var->ways = del_not_unique(var->ways);
	print_file(var->f_line);
	print_best_way(var->ways, var->top);
	run_ants(var->ways, var->top, &var->ants);
	return (0);
}
