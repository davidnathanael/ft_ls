/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/30 15:57:38 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/30 15:57:45 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

long	ft_get_mtime(char *filepath)
{
	t_stat fileStat;
    if(stat(filepath ,&fileStat) < 0)    
    {
    	ft_printf("stat() failed if ft_get_mtime : stat(%s)\n", filepath);
        exit(-1);
    }
    return (fileStat.st_mtime);
}
