/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_chrono.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 14:01:31 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/04/01 14:01:33 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

t_bool		ft_sort_util_atime(t_ent *ent1, t_ent *ent2)
{
	t_stat	filestat1;
	t_stat	filestat2;

	if (lstat(ent1->filepath, &filestat1) < 0
		|| lstat(ent2->filepath, &filestat2) < 0)
		ft_printf("stat() failed if g_ft_get_cmp_func\n");
	if (filestat1.st_atime == filestat2.st_atime)
		return (ft_sort_util_alpharev(ent1, ent2));
	if (!ent2)
		return (TRUE);
	if (filestat1.st_atime > filestat2.st_atime)
		return (TRUE);
	return (FALSE);
}

t_bool		ft_sort_util_atimerev(t_ent *ent1, t_ent *ent2)
{
	t_stat	filestat1;
	t_stat	filestat2;

	if (lstat(ent1->filepath, &filestat1) < 0
		|| lstat(ent2->filepath, &filestat2) < 0)
		ft_printf("stat() failed if g_ft_get_cmp_func\n");
	if (filestat1.st_atime == filestat2.st_atime)
		return (ft_sort_util_alpharev(ent1, ent2));
	if (!ent2)
		return (TRUE);
	if (filestat1.st_atime < filestat2.st_atime)
		return (TRUE);
	return (FALSE);
}
