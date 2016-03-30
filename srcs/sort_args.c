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

t_ent		*ft_set_arg_content(char* arg)
{
	t_ent	*content;

	content = (t_ent *)malloc(sizeof(t_ent));
	if (!content)
		return (NULL);
	content->name = arg;
	content->filepath = arg;
	content->is_ent = ft_is_ent(arg);
	content->is_dir = ft_is_dir(arg);
	content->mtime = ft_get_mtime(arg);
	return (content);
}

t_list			*ft_get_sorted_args(char *path, t_list *list, t_opt *options)
{
	t_ent		*new_content;
	t_list		*new;
	t_bool 		(*cmp_func)(t_ent *ent1, t_ent *ent2);

	new_content = ft_set_arg_content(path);
	new = ft_lstnew(new_content, sizeof(*new_content));
	cmp_func = ft_get_cmp_func(options); 
	if (!list)
		list = new;
	free(new_content);
    return (list);
}