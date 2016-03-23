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

t_bool		ft_sort_util_alpha(char *elem1, char *elem2)
{
	if (!elem2)
		return (TRUE);
	if (ft_strcmp(elem1, elem2) <= 0)
		return (TRUE);
	return (FALSE);
}

t_bool		ft_sort_util_alpharev(char *elem1, char *elem2)
{
	if (!elem2)
		return (TRUE);
	if (ft_strcmp(elem1, elem2) <= 0)
		return (FALSE);
	return (TRUE);
}
