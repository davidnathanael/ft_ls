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

static void    ft_print_xattr_nb_links(char *filepath, t_stat fileStat,
                                        t_ls_infos *infos)
{
    int             xattr;
    acl_t           acl;

    xattr = listxattr(filepath, NULL, 0, XATTR_NOFOLLOW);
    acl = acl_get_file(filepath, ACL_TYPE_EXTENDED);
    if (xattr > 0)
        ft_putchar('@');
    else if (acl)
        ft_putchar('+');
    else
        ft_putchar(' ');
    acl_free((void *)acl);
    ft_printf("%*d",infos->widths->nb_links ,fileStat.st_nlink);
}

static void     ft_print_permissions(t_stat fileStat)
{
    ft_putchar((S_ISDIR(fileStat.st_mode)) ? 'd' : '-');
    ft_putchar((fileStat.st_mode & S_IRUSR) ? 'r' : '-');
    ft_putchar((fileStat.st_mode & S_IWUSR) ? 'w' : '-');
    ft_putchar((fileStat.st_mode & S_IXUSR) ? 'x' : '-');
    ft_putchar((fileStat.st_mode & S_IRGRP) ? 'r' : '-');
    ft_putchar((fileStat.st_mode & S_IWGRP) ? 'w' : '-');
    ft_putchar((fileStat.st_mode & S_IXGRP) ? 'x' : '-');
    ft_putchar((fileStat.st_mode & S_IROTH) ? 'r' : '-');
    ft_putchar((fileStat.st_mode & S_IWOTH) ? 'w' : '-');
    ft_putchar((fileStat.st_mode & S_IXOTH) ? 'x' : '-');
}

static void     ft_proceed_long_display(char *name, char *filepath,
                                        t_ls_infos *infos)
{
    t_stat fileStat;

    if(stat(filepath,&fileStat) < 0)    
    {
        ft_printf("stat() failed : stat(%s)\n", filepath);
        return ;
    }
    ft_print_permissions(fileStat);
    ft_print_xattr_nb_links(filepath, fileStat, infos);
    ft_print_user_group(fileStat, infos);
    ft_print_time(fileStat, infos);
    ft_printf(" %s\n", name);
}

void            ft_proceed_printing(t_list *list, t_ls_infos *infos)
{
    t_list      *tmp;
    t_ent       *ent;

    tmp = list;
    if (infos->options->l)
        ft_printf("total %u\n", infos->total);
    while (tmp && (ent = tmp->content))
    {
        if (infos->options->l)
            ft_proceed_long_display(ent->name, ent->filepath, infos);
        else
          ft_printf("%s\n", ent->name);
      tmp = tmp->next;
  }
}