/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_mode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 14:12:15 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/04/01 14:12:17 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ft_print_exec(mode_t mode, char c, int type1, int type2)
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

void		ft_print_permissions(mode_t mode)
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

void		ft_print_type(mode_t mode)
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

void		ft_print_by_column(char *name, t_bool c_upper, int i,
								unsigned int max_len)
{
	if (c_upper)
	{
		if (++i % 6 == 0 && i)
			ft_printf("\n");
		if (name)
			ft_printf("%-*s", max_len + 1, name);
	}
}
