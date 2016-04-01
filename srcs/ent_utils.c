/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ent_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 13:55:18 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/04/01 13:55:19 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bool		ft_is_ent(const char *path)
{
	t_stat		filestat;

	if (stat(path, &filestat) != 0)
		return (FALSE);
	return (TRUE);
}

t_bool		ft_is_dot(const char *d_name)
{
	if (ft_strcmp(d_name, "..") != 0 && ft_strcmp(d_name, ".") != 0)
		return (FALSE);
	return (TRUE);
}
