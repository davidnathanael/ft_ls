/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 18:57:30 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/31 18:59:13 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_list_ent(t_ent *ent, t_ls_infos *infos)
{
	t_list_infos	*list_holder;

	list_holder = (t_list_infos *)malloc(sizeof(*list_holder));
	list_holder->list = NULL;
	list_holder->widths = ft_init_widths();
	list_holder->total = 0;
	list_holder->has_maj_min = FALSE;
	list_holder->list = ft_lstnew(ent, sizeof(*ent));
	list_holder->total += ft_get_blocks(ent, infos);
	ft_update_widths(ent, list_holder);
	ft_proceed_printing(list_holder, infos, FALSE);
}

static void		ft_list_dir(char *dir_name, t_ls_infos *infos, t_bool is_last)
{
	t_list_infos	*list_holder;

	list_holder = (t_list_infos *)malloc(sizeof(*list_holder));
	list_holder->widths = ft_init_widths();
	list_holder->total = 0;
	list_holder->max_len = 0;
	list_holder->has_maj_min = FALSE;
	list_holder->list = ft_get_sorted_list(dir_name, list_holder, infos);
	if (infos->ls->nb_args > 1)
		ft_printf("%s:\n", dir_name);
	if (list_holder->list)
		ft_proceed_printing(list_holder, infos, TRUE);
	if (infos->options->r_upper && list_holder->list)
		ft_proceed_r_upper(dir_name, infos, list_holder,
							list_holder->list->content);
	if (!is_last && !infos->options->r_upper)
		ft_putchar('\n');
}

void			ft_proceed_r_upper(char *dir_name, t_ls_infos *infos,
							t_list_infos *list_holder, t_ent *ent)
{
	int			path_length;
	char		*path;
	t_list		*tmp;

	path_length = 0;
	path = NULL;
	tmp = list_holder->list;
	while (tmp)
	{
		ent = tmp->content;
		if (!ft_is_dot(ent->name) && ent->is_dir)
		{
			ft_printf("\n%s:\n", ent->filepath);
			path = ft_get_full_path(dir_name, ent->name);
			path_length = ft_strlen(path);
			if (path_length >= PATH_MAX)
			{
				free(path);
				exit(EXIT_FAILURE);
			}
			ft_list_dir(path, infos, (!tmp->next) ? TRUE : FALSE);
			free(path);
		}
		tmp = tmp->next;
	}
}

void			ft_ls(char **av)
{
	t_ls_infos	*infos;
	t_ent		*content;

	infos = (t_ls_infos *)malloc(sizeof(*infos));
	infos->options = ft_get_ls_options(av);
	infos->ls = ft_get_ls_args(av, infos->options);
	content = (infos->ls->has_args) ? infos->ls->sorted_args->content : NULL;
	if (!infos->ls->has_args)
		ft_list_dir(".", infos, TRUE);
	else
	{
		while (infos->ls->sorted_args)
		{
			content = infos->ls->sorted_args->content;
			if (!content->is_ent)
				ft_printf("ls: %s: No such file or directory\n", content->name);
			else if (!content->is_dir)
				ft_list_ent(content, infos);
			else
				ft_list_dir(content->name, infos,
						(!infos->ls->sorted_args->next) ? TRUE : FALSE);
			infos->ls->sorted_args = infos->ls->sorted_args->next;
		}
	}
}
