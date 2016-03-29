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

static void     ft_print_time(t_stat fileStat, t_ls_infos *infos)
{
    (void)infos;
    ft_printf(" %s", ft_strsub(ctime(&fileStat.st_mtime), 4, 12));
}

static void     ft_print_user_group(t_stat fileStat, t_ls_infos *infos)
{
    char    *user;
    char    *group;

    user = getpwuid(fileStat.st_uid)->pw_name;
    group = getgrgid(fileStat.st_gid)->gr_name;
    ft_printf(" %-*s", infos->widths->user, user);
    ft_printf("  %-*s", infos->widths->group, group);
    ft_printf("%*lld", infos->widths->size, fileStat.st_size);
}

static void		ft_print_permissions_links(t_stat fileStat, t_ls_infos *infos)
{
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
    ft_printf("%*d",infos->widths->nb_links ,fileStat.st_nlink);
}

static void		ft_proceed_long_display(t_ent *ent, t_ls_infos *infos)
{
    t_stat fileStat;

    if(stat(ent->filepath,&fileStat) < 0)    
    {
        ft_printf("stat() failed : stat(%s)\n", ent->filepath);
        return ;
    }
    ft_print_permissions_links(fileStat, infos);
    ft_print_user_group(fileStat, infos);
    ft_print_time(fileStat, infos);
    ft_printf(" %s\n", ent->name);
}

void            ft_proceed_printing(t_list *list, t_ls_infos *infos)
{
    t_list      *tmp;
    t_ent       *ent;

    tmp = list;
    if (infos->options->l)
        ft_printf("total\n");
    while (tmp && (ent = tmp->content))
    {
    	if (infos->options->l)
    		ft_proceed_long_display(ent, infos);
    	else
    		ft_printf("%s\n", ent->name);
        tmp = tmp->next;
    }
}