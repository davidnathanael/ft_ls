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

t_list			*ft_get_sorted_args(char *path, t_list *list, t_opt *options)
{
	t_list		*new;
	t_bool 		(*cmp_func)(t_ent *ent1, t_ent *ent2);

	new = ft_lstnew(path, sizeof(*path * ft_strlen(path) + 1));
	cmp_func = ft_get_cmp_func(options); 
	if (!list)
		list = new;
    return (list);
}