/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 14:33:26 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/29 14:33:28 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_print_permissions_links(t_ent *ent)
{
	t_stat fileStat;
    if(stat(ent->filepath,&fileStat) < 0)    
    {
    	ft_printf("stat() failed : stat(%s)\n", ent->filepath);
        return ;
    }

    // ft_printf("Information for %s\n",ent->filepath);
    // ft_printf("---------------------------\n");
    // ft_printf("File Size: \t\t%d bytes\n",fileStat.st_size);
    // ft_printf("File inode: \t\t%d\n",fileStat.st_ino);

    // ft_printf("File Permissions: \t");
    ft_printf((S_ISDIR(fileStat.st_mode)) ? "d" : "-");
    ft_printf((fileStat.st_mode & S_IRUSR) ? "r" : "-");
    ft_printf((fileStat.st_mode & S_IWUSR) ? "w" : "-");
    ft_printf((fileStat.st_mode & S_IXUSR) ? "x" : "-");
    ft_printf((fileStat.st_mode & S_IRGRP) ? "r" : "-");
    ft_printf((fileStat.st_mode & S_IWGRP) ? "w" : "-");
    ft_printf((fileStat.st_mode & S_IXGRP) ? "x" : "-");
    ft_printf((fileStat.st_mode & S_IROTH) ? "r" : "-");
    ft_printf((fileStat.st_mode & S_IWOTH) ? "w" : "-");
    ft_printf((fileStat.st_mode & S_IXOTH) ? "x" : "-");
    ft_printf("  ");
    ft_printf("%d ",fileStat.st_nlink);
}

static void		ft_proceed_long_display(t_ent *ent)
{
	ft_print_permissions_links(ent);
	ft_printf("xxx xxx xxx %s\n", ent->name);
}

void			ft_proceed_printing(t_ent *ent, t_opt *options)
{
	if (options->l)
		ft_proceed_long_display(ent);
	else
		ft_printf("%s\n", ent->name);
}