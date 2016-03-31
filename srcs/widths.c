/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   widths.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 16:02:12 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/31 18:53:34 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_update_widths(t_ent *ent, t_list_infos *list_holder)
{
	t_widths	*widths;
	t_stat		filestat;

	widths = list_holder->widths;
	if (lstat(ent->filepath, &filestat) < 0)
	{
		ft_printf("stat() failed if ft_update_widths : stat(%s)\n",
					ent->filepath);
		return ;
	}
	if (ft_nbrlen(filestat.st_nlink) + NB_LINKS_MINWIDTH > widths->nb_links)
		widths->nb_links = ft_nbrlen(filestat.st_nlink) + NB_LINKS_MINWIDTH;
	if (ft_strlen(getpwuid(filestat.st_uid)->pw_name) + USER_MINWIDTH > widths->user)
		widths->user = ft_strlen(getpwuid(filestat.st_uid)->pw_name) + USER_MINWIDTH;
	if (ft_strlen(getgrgid(filestat.st_gid)->gr_name) + GROUP_MINWIDTH > widths->group)
		widths->group = ft_strlen(getgrgid(filestat.st_gid)->gr_name) + GROUP_MINWIDTH;
	if (ft_nbrlen(filestat.st_size) + SIZE_MINWIDTH > widths->size)
		widths->size = ft_nbrlen(filestat.st_size) + SIZE_MINWIDTH;
	if (ft_nbrlen(major(filestat.st_rdev)) + MAJ_MINWIDTH > widths->maj)
		widths->maj = ft_nbrlen(major(filestat.st_rdev)) + MAJ_MINWIDTH;
	if (ft_nbrlen(minor(filestat.st_rdev)) + MIN_MINWIDTH > widths->min)
		widths->min = ft_nbrlen(minor(filestat.st_rdev)) + MIN_MINWIDTH;
	if (S_ISBLK(filestat.st_mode) || S_ISCHR(filestat.st_mode))
		list_holder->has_maj_min = TRUE;
}

t_widths	*ft_init_widths(void)
{
	t_widths	*widths;

	widths = (t_widths *)malloc(sizeof(*widths));
	if (!widths)
		return (NULL);
	widths->nb_links = NB_LINKS_MINWIDTH;
	widths->user = USER_MINWIDTH;
	widths->group = GROUP_MINWIDTH;
	widths->size = SIZE_MINWIDTH;
	widths->maj = MAJ_MINWIDTH;
	widths->min = MIN_MINWIDTH;
	return (widths);
}
