/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:33:01 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/31 18:51:14 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

unsigned int	ft_get_blocks(t_ent *ent, t_ls_infos *infos)
{
	t_stat	filestat;

	if (lstat(ent->filepath, &filestat) < 0)
	{
		ft_printf("stat() failed if ft_get_blocks : stat(%s)\n", ent->filepath);
		return (0);
	}
	if (!ft_check_option_a(ent->name, infos->options))
		return (0);
	return (filestat.st_blocks);
}

t_bool			ft_check_option_a(char *name, t_opt *options)
{
	if (options->a_upper && ft_is_dot(name))
	{
		if (options->a)
			return (TRUE);
		return (FALSE);
	}
	else if (options->a == FALSE && name[0] == '.')
	{
		if (options->a_upper)
			return (TRUE);
		return (FALSE);
	}
	return (TRUE);
}
