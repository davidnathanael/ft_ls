/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_user_group_time.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 14:14:28 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/04/01 14:14:29 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_time(t_stat filestat, t_opt *options)
{
	char *mtime;

	if (filestat.st_mtime - time(NULL) > 15778800 ||
		filestat.st_mtime - time(NULL) < -15778800)
	{
		if (options->t_upper)
			mtime = ft_strsub(ctime(&filestat.st_mtime), 4, 20);
		else
			mtime = ft_strsub(ctime(&filestat.st_mtime), 4, 7);
		ft_printf(" %s", mtime);
		if (!options->t_upper)
			ft_printf("%*lld", 5, filestat.st_mtime / 31555952 + 1970);
	}
	else
	{
		if (options->t_upper)
			mtime = ft_strsub(ctime(&filestat.st_mtime), 4, 20);
		else
			mtime = ft_strsub(ctime(&filestat.st_mtime), 4, 12);
		ft_printf(" %s", mtime);
	}
	free(mtime);
}

void		ft_print_user_group(t_stat filestat, t_widths *widths,
									t_opt *options)
{
	char	*user;
	char	*group;

	user = getpwuid(filestat.st_uid)->pw_name;
	group = getgrgid(filestat.st_gid)->gr_name;
	if (!options->g)
	{
		ft_printf(" %-*s", widths->user, user);
		ft_printf("  %-*s", widths->group, group);
	}
	else
		ft_printf(" %-*s", ++widths->group, group);
}
