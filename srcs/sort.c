/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:06:58 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/22 16:07:01 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ent		*ft_set_content(char* dir_name, t_dirent *entry, t_ls_infos *infos)
{
	t_ent	*content;

	content = (t_ent *)malloc(sizeof(t_ent));
	if (!content)
		return (NULL);
	content->name = ft_strdup(entry->d_name);
	content->filepath = ft_get_full_path(dir_name, content->name);
	content->isdir = ft_is_dir(content->filepath);
	ft_update_widths(content, infos->widths);
	return (content);
}

t_bool (* ft_get_cmp_func(t_opt *options))(char *,char *)
{
	if (options->r)
		return (ft_sort_util_alpharev);
	return (ft_sort_util_alpha);
}

t_list				*ft_push(t_list *list, t_list *new, t_ent *content,
							t_bool (*cmp_func)(char *, char *))
{
	t_list		*tmp;
	t_ent		*tmp_content;

	tmp = list;
	tmp_content = list->content;
	if ((*cmp_func)(content->name, tmp_content->name))
	{
		new->next = list;
		list = new;
	}
	else
	{
		while (tmp->next && (tmp_content = tmp->next->content)
					&& (*cmp_func)(content->name, tmp_content->name) == FALSE)
			tmp = tmp->next;	
		if (!tmp->next)
			tmp->next = new;	
		else
		{
			new->next = tmp->next;
			tmp->next = new;
		}
	}
	return (list);
}

static t_list		*ft_insert_to_list(t_list *list, t_ls_infos *infos,
										char *dir_name, t_dirent *entry)
{
	t_ent		*content;
	t_ent		*tmp_content;
	t_list		*new;
	t_bool 		(*cmp_func)(char *, char *);
	t_bool		is_well_placed;	

	content = ft_set_content(dir_name, entry, infos);
	tmp_content = (list) ? list->content : NULL;
	new = ft_lstnew(content, sizeof(*content));
	cmp_func = ft_get_cmp_func(infos->options); 
	is_well_placed = (list) ? cmp_func(content->name, tmp_content->name) :FALSE;
	if (!list)
		list = new;
	else if (!list->next)
	{
		new->next = (is_well_placed) ? list : new->next;
		list = (is_well_placed) ? new : list;
		list->next = (is_well_placed) ? list->next : new;
	}
	else
		list = ft_push(list, new, content, cmp_func);
	free(content);
	return (list);
}

t_list		*ft_get_sorted_list(char *dir_name, t_ls_infos *infos)
{
	t_list		*list;
	DIR			*dir;
	t_dirent	*entry ;
	

	list = NULL;
	dir = ft_opendir(dir_name);
	if (!dir)
		return (NULL);
	while ((entry = readdir (dir)) != NULL)
		list = ft_insert_to_list(list, infos, dir_name, entry);
	ft_closedir(dir, dir_name);
	return (list);
}
