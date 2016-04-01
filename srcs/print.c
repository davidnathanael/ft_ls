/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/29 14:33:26 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/31 18:40:40 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_print_name(t_stat filestat, char *d_name, char *path,
		t_opt *options)
{
	char	buf[1024];
	int		len;

	len = readlink(path, buf, sizeof(buf));
	buf[len] = 0;
	ft_putstr(" ");
	ft_putstr(d_name);
	if (S_ISLNK(filestat.st_mode) && options->l)
	{
		ft_putstr(" -> ");
		ft_putstr(buf);
	}
	ft_putchar('\n');
}

static void		ft_print_size_maj_min(t_stat filestat, t_widths *widths,
		t_bool has_maj_min)
{
	if (S_ISBLK(filestat.st_mode) || S_ISCHR(filestat.st_mode))
	{
		ft_printf("%*lld,", widths->maj, major(filestat.st_rdev));
		ft_printf("%*lld", widths->min, minor(filestat.st_rdev));
	}
	else
		ft_printf("%*lld", (has_maj_min)
				? widths->size + widths->maj + widths->min
				: widths->size, filestat.st_size);
}

static void		ft_print_xattr_nb_links(char *filepath, t_stat filestat,
		t_widths *widths)
{
	int			xattr;
	acl_t		acl;

	xattr = listxattr(filepath, NULL, 0, XATTR_NOFOLLOW);
	acl = acl_get_file(filepath, ACL_TYPE_EXTENDED);
	if (xattr > 0)
		ft_putchar('@');
	else if (acl)
		ft_putchar('+');
	else
		ft_putchar(' ');
	acl_free((void *)acl);
	ft_printf("%*d", widths->nb_links, filestat.st_nlink);
}

static void		ft_proceed_long_display(char *name, char *filepath,
		t_list_infos *list_holder, t_ls_infos *infos)
{
	t_stat	filestat;

	if (lstat(filepath, &filestat) < 0)
	{
		ft_printf("stat() failed : stat(%s)\n", filepath);
		return ;
	}
	ft_print_type(filestat.st_mode);
	ft_print_permissions(filestat.st_mode);
	ft_print_xattr_nb_links(filepath, filestat, list_holder->widths);
	ft_print_user_group(filestat, list_holder->widths, infos->options);
	ft_print_size_maj_min(filestat, list_holder->widths,
						list_holder->has_maj_min);
	ft_print_time(filestat, infos->options);
	ft_print_name(filestat, name, filepath, infos->options);
}

void			ft_proceed_printing(t_list_infos *list_holder,
									t_ls_infos *infos, t_bool is_dir)
{
	t_list		*tmp;
	t_ent		*ent;
	int			i;

	tmp = list_holder->list;
	ent = tmp->content;
	i = -1;
	if ((infos->options->l && is_dir) || infos->options->g)
		ft_printf("total %u\n", list_holder->total);
	while (tmp && (ent = tmp->content))
	{
		if (infos->options->l || infos->options->g)
			ft_proceed_long_display(ent->name, ent->filepath,
					list_holder, infos);
		else if (infos->options->one || !infos->options->c_upper)
			ft_printf("%s\n", ent->name);
		ft_print_by_column(ent->name, infos->options->c_upper, i,
							list_holder->max_len);
		if (!infos->options->r_upper)
			ft_free_elem(tmp);
		tmp = tmp->next;
	}
}
