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

static void		ft_print_time(t_stat filestat, t_opt *options)
{
	char *mtime;

	if (filestat.st_mtime - time(NULL) > 15778800 ||
		filestat.st_mtime - time(NULL) < -15778800)
	{
		if (options->t_upper)
			mtime = ft_strsub(ctime(&filestat.st_mtime), 4, 20);
		else
			mtime = ft_strsub(ctime(&filestat.st_mtime), 4, 7);
		ft_printf(" %s", mtime);
		if (!options->t_upper)
			ft_printf("%*lld", 5, filestat.st_mtime / 31555952 + 1970);
	}
	else
	{
		if (options->t_upper)
			mtime = ft_strsub(ctime(&filestat.st_mtime), 4, 20);
		else
			mtime = ft_strsub(ctime(&filestat.st_mtime), 4, 12);
		ft_printf(" %s", mtime);
	}
	free(mtime);
}

static void		ft_print_user_group(t_stat filestat, t_widths *widths)
{
	char	*user;
	char	*group;

	user = getpwuid(filestat.st_uid)->pw_name;
	group = getgrgid(filestat.st_gid)->gr_name;
	ft_printf(" %-*s", widths->user, user);
	ft_printf("  %-*s", widths->group, group);
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

void			ft_print_exec(mode_t mode, char c, int type1, int type2)
{
	if (mode & type2)
	{
		if (mode & type1)
			ft_putchar(c);
		else
			ft_putchar('x');
	}
	else
	{
		if (mode & type1)
			ft_putchar(c - 'a' + 'A');
		else
			ft_putchar('-');
	}
}

static void		ft_print_permissions(mode_t mode)
{
	ft_putchar((mode & S_IRUSR) ? 'r' : '-');
	ft_putchar((mode & S_IWUSR) ? 'w' : '-');
	ft_print_exec(mode, 's', S_ISUID, S_IXUSR);
	ft_putchar((mode & S_IRGRP) ? 'r' : '-');
	ft_putchar((mode & S_IWGRP) ? 'w' : '-');
	ft_print_exec(mode, 's', S_ISGID, S_IXGRP);
	ft_putchar((mode & S_IROTH) ? 'r' : '-');
	ft_putchar((mode & S_IWOTH) ? 'w' : '-');
	ft_print_exec(mode, 't', S_ISTXT, S_IXOTH);
}

static void		ft_print_type(mode_t mode)
{
	if (S_ISLNK(mode))
		ft_putchar('l');
	else if (S_ISBLK(mode))
		ft_putchar('b');
	else if (S_ISCHR(mode))
		ft_putchar('c');
	else if (S_ISDIR(mode))
		ft_putchar('d');
	else if (S_ISFIFO(mode))
		ft_putchar('p');
	else if (S_ISSOCK(mode))
		ft_putchar('s');
	else if (S_ISREG(mode))
		ft_putchar('-');
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
	ft_print_user_group(filestat, list_holder->widths);
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

	tmp = list_holder->list;
	ent = tmp->content;
	if (infos->options->l && is_dir)
		ft_printf("total %u\n", list_holder->total);
	while (tmp && (ent = tmp->content))
	{
		if (infos->options->l)
			ft_proceed_long_display(ent->name, ent->filepath,
					list_holder, infos);
		else
			ft_printf("%s\n", ent->name);
		tmp = tmp->next;
	}
}
