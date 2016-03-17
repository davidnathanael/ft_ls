/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 15:15:37 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/17 15:15:39 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void					ft_ls(int ac, char **av)
{
	t_opt	*options;
	t_ls	*ls;

	options = ft_get_ls_options(ac, av);
	ls = ft_get_ls_args(ac, av, options);
}
