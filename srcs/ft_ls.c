/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 15:15:37 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/17 15:15:39 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <limits.h>

void		ft_proceed_r_upper(char *dir_name, t_opt *options, t_list *list, t_ent *ent);


t_bool			ft_is_dot(const char *d_name)
{
	if (ft_strcmp (d_name, "..") != 0 && ft_strcmp (d_name, ".") != 0)
		return (FALSE);
	return (TRUE);
}

char			*ft_get_full_path(const char *dir_name, const char *d_name)
{
	char		*ret;
	char		*tmp;

	tmp = ft_strjoin(dir_name, "/");
	ret = ft_strjoin(tmp, d_name);
	free(tmp);
	return (ret);
}

static void		ft_list_dir(char *dir_name, t_opt *options)		
{
	t_list		*list;
	t_list		*tmp;
	t_ent		*ent;

	list = ft_get_sorted_list(dir_name, options);
	// ft_debug_list(list);
	tmp = list;
	while (tmp && (ent = tmp->content))
	{
		printf("%s\n", ent->name); //printing part.
		tmp = tmp->next;
	}
	if (options->r_upper)
		ft_proceed_r_upper(dir_name, options, list, list->content);
}

void		ft_proceed_r_upper(char *dir_name, t_opt *options, t_list *list, t_ent *ent)
{
	int			path_length;
	char		path[PATH_MAX];
	t_list		*tmp;

	tmp = list;
	while (tmp)
	{
		ent = tmp->content;
		if (!ft_is_dot(ent->name) && ent->isdir)
		{
			ft_printf("\n%s/%s:\n", dir_name, ent->name);
			path_length = snprintf (path, PATH_MAX,
				"%s/%s", dir_name, ent->name);
			if (path_length >= PATH_MAX) {
				fprintf (stderr, "Path length has got too long.\n");
				exit (EXIT_FAILURE);
			}
			ft_list_dir (path, options);
		}
		tmp = tmp->next;
	}
}

void			ft_ls(int ac, char **av)
{
	t_opt	*options;
	t_ls	*ls;

	options = ft_get_ls_options(av);
	ls = ft_get_ls_args(ac, av, options);
	// ft_debug_options(options);
	// ft_debug_ls(ls);
	// ft_printf("\n\n\n\n");
	if (!ls->has_args)
		ft_list_dir(".", options);
	else
	{
		while (*ls->args)
			ft_list_dir(*ls->args++, options);
	}
}