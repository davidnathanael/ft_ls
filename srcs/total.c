/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   total.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 11:33:01 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/30 11:33:15 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

unsigned int	ft_get_blocks(t_ent *ent, t_ls_infos *infos)
{
	t_stat fileStat;
    if(stat(ent->filepath ,&fileStat) < 0)    
    {
    	ft_printf("stat() failed if ft_get_blocks : stat(%s)\n", ent->filepath);
        return (0);
    }
    if (infos->options->a == FALSE && ent->name[0] == '.')
    	return (0);
    return (fileStat.st_blocks);
}
