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

t_ent		*ft_set_content(char* dir_name, t_dirent *entry)
{
	t_ent	*content;

	content = (t_ent *)malloc(sizeof(t_ent));
	if (!content)
		return (NULL);
	content->name = ft_strdup(entry->d_name);
	content->filepath = ft_get_full_path(dir_name, content->name);
	content->isdir = ft_is_dir(content->filepath);
	return (content);
}

static t_list		*ft_push(t_list *list, t_opt *options, char *dir_name, t_dirent *entry)
{
	t_ent		*content;
	t_list		*new;
	t_list		*tmp;
	t_ent		*tmp_content;
	t_bool		is_well_placed;	

	content = ft_set_content(dir_name, entry);
	new = ft_lstnew(content, sizeof(*content));
	tmp = list;
	tmp_content = (list) ? list->content : NULL;
	is_well_placed = FALSE;
	(void)options;
	if (!list)
		list = new;
	else if (!tmp->next)
	{
		is_well_placed = ft_sort_util_alpha(content->name, tmp_content->name);
		list = (is_well_placed) ? new : list;
		new->next = (is_well_placed) ? tmp : new->next;
		tmp->next = (is_well_placed) ? tmp->next : new;
	}
	else
	{
		if (ft_sort_util_alpha(content->name, tmp_content->name))
		{
			new->next = list;
			list = new;
			return (list);
		}
		while (tmp)
		{
			tmp_content = tmp->content;
			if (!tmp->next)
			{
				tmp->next = new;	
				break;
			}
			else if (ft_sort_util_alpha(content->name, tmp_content->name))
			{
				new->next = tmp->next;
				tmp->next = new;
				break;
			}
			tmp = tmp->next;	
		}
	}
	free(content);
	return (list);
}

t_list		*ft_get_sorted_list(char *dir_name, t_opt *options)
{
	t_list		*list;
	DIR			*dir;
	t_dirent	*entry ;
	

	(void)options;
	list = NULL;
	dir = ft_opendir(dir_name);
	while ((entry = readdir (dir)) != NULL)
	{
		if (entry->d_name[0] == '.' && options->a == FALSE)
			continue;
		list = ft_push(list, options, dir_name, entry);
	}
	ft_closedir(dir, dir_name);
	return (list);
}