/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 15:57:27 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/31 18:49:34 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bool		(*g_ft_get_cmp_func(t_opt *options))(t_ent *ent1, t_ent *ent2)
{
	if (options->t)
		return ((options->r) ? ft_sort_util_chronorev : ft_sort_util_chrono);
	else if (options->u)
		return ((options->r) ? ft_sort_util_atimerev : ft_sort_util_atime);
	else
		return ((options->r) ? ft_sort_util_alpharev : ft_sort_util_alpha);
}

t_bool		ft_sort_util_alpha(t_ent *ent1, t_ent *ent2)
{
	if (!ent2)
		return (TRUE);
	if (ft_strcmp(ent1->name, ent2->name) <= 0)
		return (TRUE);
	return (FALSE);
}

t_bool		ft_sort_util_alpharev(t_ent *ent1, t_ent *ent2)
{
	if (!ent2)
		return (TRUE);
	if (ft_strcmp(ent1->name, ent2->name) <= 0)
		return (FALSE);
	return (TRUE);
}
