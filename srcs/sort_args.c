/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 17:28:42 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/30 17:28:46 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


static t_list	*ft_push_dir_arg(t_list *list, t_list *new, t_ent *content,
	t_bool (*cmp_func)(t_ent *ent1, t_ent *ent2))
{
	t_ent	*tmp_content;
	t_list	*tmp;

	tmp = list;
	tmp_content = tmp->content;
	while (tmp->next && (tmp_content = tmp->next->content) && !tmp_content->is_dir)
		tmp = tmp->next;
	// if (!tmp->next)
	// {
	// 	tmp->next = new;
	// 	return (list);
	// }
	while (tmp->next && (tmp_content = tmp->next->content)
		&& !(*cmp_func)(content, tmp_content))
		tmp = tmp->next;
	// tmp_content = tmp->content;
	// ft_printf("1. content : %s | tmp : %s\n\n", content->name, tmp_content->name);
	new->next = tmp->next;
	tmp->next = new;	
	return (list);
}

static t_list	*ft_push_ent_arg(t_list *list, t_list *new, t_ent *content,
	t_bool (*cmp_func)(t_ent *ent1, t_ent *ent2))
{
	t_ent	*tmp_content;
	t_list	*tmp;

	tmp = list;
	tmp_content = tmp->content;
	while (tmp->next && (tmp_content = tmp->next->content) && !tmp_content->is_ent)
		tmp = tmp->next;
	while (tmp->next && (tmp_content = tmp->next->content)
		&& !(*cmp_func)(content, tmp_content) && tmp_content->is_ent)
		tmp = tmp->next;
	new->next = tmp->next;
	tmp->next = new;	
	return (list);
}

static t_list	*ft_push_invalid_arg(t_list *list, t_list *new, t_ent *content,
	t_bool (*cmp_func)(t_ent *ent1, t_ent *ent2))
{
	t_ent	*tmp_content;
	t_list	*tmp;

	tmp = list;
	tmp_content = tmp->content;
	(void)cmp_func;
	while (tmp->next && (tmp_content = tmp->next->content)
		&& ft_strcmp(content->name, tmp_content->name) <= 0 && content->is_ent)
		tmp = tmp->next;
	ft_printf("2 %s | %s\n", content->name, tmp_content->name);
	new->next = tmp->next;
	tmp->next = new;	
	return (list);
}

t_ent		*ft_set_arg_content(char* arg)
{
	t_ent	*content;

	content = (t_ent *)malloc(sizeof(t_ent));
	if (!content)
		return (NULL);
	content->name = ft_strdup(arg);
	content->filepath = ft_strdup(arg);
	content->is_ent = ft_is_ent(arg);
	content->is_dir = ft_is_dir(arg);
	content->mtime = (content->is_ent) ? ft_get_mtime(arg) : 0;
	return (content);
}

t_list			*ft_get_sorted_args(char *path, t_list *list, t_opt *options)
{
	t_ent		*content;
	t_list		*new;
	t_bool 		(*cmp_func)(t_ent *ent1, t_ent *ent2);

	content = ft_set_arg_content(path);
	// ft_debug_arg_content(content);
	new = ft_lstnew(content, sizeof(*content));
	cmp_func = ft_get_cmp_func_arg(options); 
	if (!list)
		list = new;
	else if (content->is_dir)
		list = ft_push_dir_arg(list, new, content, cmp_func);
	else if (content->is_ent && !content->is_dir)
		list = ft_push_ent_arg(list, new, content, cmp_func);
	else
		list = ft_push_invalid_arg(list, new, content, cmp_func);
	// free(content);
	return (list);
}