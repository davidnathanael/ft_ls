/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 15:57:38 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/31 18:50:33 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

long	ft_get_time(char *filepath, t_time time)
{
	t_stat	filestat;

	if (lstat(filepath, &filestat) < 0)
		ft_printf("stat() failed if ft_get_mtime : stat(%s)\n", filepath);
	if (time == MTIME)
		return (filestat.st_mtime);
	else if (time == ATIME)
		return (filestat.st_atime);
	else
		return (filestat.st_ctime);
}
