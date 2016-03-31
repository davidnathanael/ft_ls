/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 15:57:27 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/17 15:57:29 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bool 		(* ft_get_cmp_func(t_opt *options))(t_ent *ent1, t_ent *ent2)
{
	if (options->t)
		return ((options->r) ? ft_sort_util_chronorev : ft_sort_util_chrono);
	else
		return ((options->r) ? ft_sort_util_alpharev : ft_sort_util_alpha);
}

t_bool 		(* ft_get_cmp_func_arg(t_opt *options))(t_ent *ent1, t_ent *ent2)
{
	if (options->t)
		return ((options->r) ? ft_sort_util_chronorev : ft_sort_util_chrono);
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

t_bool		ft_sort_util_chrono(t_ent *ent1, t_ent *ent2)
{
	if (ent1->mtime == ent2->mtime)
		return (ft_sort_util_alpha(ent1, ent2));
	if (!ent2)
		return (TRUE);
	if (ent1->mtime > ent2->mtime)
		return (TRUE);
	return (FALSE);
}

t_bool		ft_sort_util_chronorev(t_ent *ent1, t_ent *ent2)
{
	if (ent1->mtime == ent2->mtime)
		return (ft_sort_util_alpharev(ent1, ent2));
	if (!ent2)
		return (TRUE);
	if (ent1->mtime < ent2->mtime)
		return (TRUE);
	return (FALSE);
}

t_bool		ft_sort_util_alpharev_arg(t_ent *ent1, t_ent *ent2)
{
	if (!ent2 || ent2->is_dir)
		return (TRUE);
	if (ft_strcmp(ent1->name, ent2->name) <= 0)
		return (FALSE);
	return (TRUE);
}
