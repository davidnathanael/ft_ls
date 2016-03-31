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

static t_ent	*ft_set_content(char *dir_name, t_dirent *entry,
						t_list_infos *list_holder, t_ls_infos *infos)
{
	t_ent	*content;

	content = (t_ent *)malloc(sizeof(t_ent));
	if (!content)
		return (NULL);
	content->ent = entry;
	content->name = ft_strdup(entry->d_name);
	content->filepath = ft_get_full_path(dir_name, content->name);
	content->is_dir = ft_is_dir(content->filepath);
	content->is_ent = (content->is_dir) ? TRUE : ft_is_ent(dir_name);
	content->mtime = ft_get_mtime(content->filepath);
	list_holder->total += ft_get_blocks(content, infos);
	ft_update_widths(content, list_holder);
	return (content);
}

t_list			*ft_push(t_list_infos *list_holder, t_list *new, t_ent *content,
							t_bool (*cmp_func)(t_ent *ent1, t_ent *ent2))
{
	t_list		*tmp;
	t_ent		*tmp_content;

	tmp = list_holder->list;
	tmp_content = list_holder->list->content;
	if ((*cmp_func)(content, tmp_content))
	{
		new->next = list_holder->list;
		list_holder->list = new;
	}
	else
	{
		while (tmp->next && (tmp_content = tmp->next->content)
				&& (*cmp_func)(content, tmp_content) == FALSE)
			tmp = tmp->next;
		if (!tmp->next)
			tmp->next = new;
		else
		{
			new->next = tmp->next;
			tmp->next = new;
		}
	}
	return (list_holder->list);
}

static t_list	*ft_insert_to_list(t_list_infos *list_holder, t_ls_infos *infos,
										char *dir_name, t_dirent *entry)
{
	t_list		*new;
	t_ent		*content;
	t_ent		*tmp_content;
	t_bool		(*cmp_func)(t_ent *ent1, t_ent *ent2);
	t_bool		is_well_placed;

	content = ft_set_content(dir_name, entry, list_holder, infos);
	tmp_content = (list_holder->list) ? list_holder->list->content : NULL;
	new = ft_lstnew(content, sizeof(*content));
	cmp_func = g_ft_get_cmp_func(infos->options);
	is_well_placed = (list_holder->list)
					? cmp_func(content, tmp_content) : FALSE;
	if (!list_holder->list)
		list_holder->list = new;
	else if (!list_holder->list->next)
	{
		new->next = (is_well_placed) ? list_holder->list : new->next;
		list_holder->list = (is_well_placed) ? new : list_holder->list;
		list_holder->list->next = (is_well_placed)
								? list_holder->list->next : new;
	}
	else
		list_holder->list = ft_push(list_holder, new, content, cmp_func);
	free(content);
	return (list_holder->list);
}

t_list			*ft_get_sorted_list(char *dir_name,
				t_list_infos *list_holder, t_ls_infos *infos)
{
	DIR			*dir;
	t_dirent	*entry;

	list_holder->list = NULL;
	dir = ft_opendir(dir_name);
	if (!dir)
		return (NULL);
	while ((entry = readdir(dir)) != NULL)
	{
		ft_printf("%s\n", entry->d_name);
		if (infos->options->a == FALSE && entry->d_name[0] == '.')
			continue;
		list_holder->list = ft_insert_to_list(list_holder, infos,
											dir_name, entry);
	}
	ft_closedir(dir, dir_name);
	return (list_holder->list);
}
