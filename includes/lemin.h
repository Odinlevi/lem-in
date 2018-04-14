/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnikifor <mnikifor@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:52:00 by mnikifor          #+#    #+#             */
/*   Updated: 2018/02/14 14:52:00 by mnikifor         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEMIN_H
# define LEMIN_H
# include "../libft/libft.h"

typedef struct			s_ants
{
	int					count_ants;
	int					number_a;
	char				*start;
	char				*end;
}						t_ants;

typedef struct			s_tops
{
	int					x;
	int					y;
	int					count;
	char				*name;
	struct s_tops		*next;
}						t_tops;

typedef struct			s_links
{
	char				*fr;
	char				*to;
	struct s_links		*next;
}						t_links;

typedef struct			s_uniq_path
{
	int					*a_way;
	int					len;
	struct s_uniq_path	*next;
}						t_uniq_path;

typedef struct			s_find_paths
{
	int					*visited;
	int					*path;
	int					path_index;
	int					s;
	int					e;
	int					len;
	int					**arr;
}						t_find_paths;

typedef struct			s_print_l
{
	char				*line;
	struct s_print_l	*next;
}						t_print_l;

typedef struct			s_create_var
{
	t_ants			ants;
	t_tops			*top;
	t_uniq_path		*ways;
	t_find_paths	*tops;
	t_links			*links;
	t_print_l		*f_line;
}						t_create_var;

typedef struct			s_temp_var
{
	t_tops				*temp_p;
	t_tops				*temp_j;
	t_links				*temp_l;
}						t_temp_var;

int						len_pt(void *temp);
int						**to_matr(t_tops *top, t_links *links, int i, int j);
void					*find_all_paths(t_find_paths *tops, t_uniq_path *ways);
t_uniq_path				*sort_ways(t_uniq_path *ph);
void					check_se(char **ants, char **line, t_print_l ***f_line);
void					*del_not_unique(t_uniq_path *ways);
void					run_ants(t_uniq_path *ways, t_tops *top, t_ants *ants);
void					error();
int						check_rooms(t_tops *tops);
void					zero_par(t_ants *ants);
int						check_links(t_links *links, t_tops *top);
t_print_l				*add_line(t_print_l *f_line, char *line);
void					save_coord(t_tops **temp, char *line, int i);
t_tops					*save_path(t_tops *top, char *line);
t_links					*save_links(t_links *links, char *line, int i, int j);
int						save_file(t_tops **tmp_p, t_links **tmp_l, char *line);
void					save_ants(t_ants **ants, t_print_l **tmp_line);
void					check_error(t_tops *top, t_links *links, t_ants *ants);
void					print_file(t_print_l *f_line);
void					print_best_way(t_uniq_path *ways, t_tops *top);
char					*n_t(t_tops *top, int name);
int						find_un_arr(t_uniq_path *a, t_uniq_path *b);

#endif
