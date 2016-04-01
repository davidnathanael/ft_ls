/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:58:17 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/31 18:43:42 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_opendir_error(char *dir, int errno_save)
{
	int		len;
	char	*to_print;

	len = ft_strlen(dir);
	to_print = NULL;
	while (len && dir[len] != '/')
		len--;
	len = (dir[len] == '/') ? len + 1 : len;
	to_print = ft_strsub(dir, len, ft_strlen(dir) - len);
	ft_putstr_fd("ls: ", 2);
	ft_putstr_fd(to_print, 2);
	ft_putstr_fd(": ", 2);
	ft_putstr_fd(strerror(errno_save), 2);
	ft_putchar_fd('\n', 2);
	free(to_print);
}

DIR			*ft_opendir(char *dir_name)
{
	DIR			*dir;
	int			errno_save;

	dir = opendir(dir_name);
	if (!dir)
	{
		errno_save = errno;
		ft_print_opendir_error(dir_name, errno_save);
	}
	return (dir);
}

void		ft_closedir(DIR *dir, const char *dir_name)
{
	if (closedir(dir))
	{
		ft_printf("Could not close '%s': %s\n",
			dir_name, strerror(errno));
		exit(EXIT_FAILURE);
	}
}

t_bool		ft_is_dir(const char *path)
{
	t_stat		filestat;

	if (stat(path, &filestat) != 0)
		return (0);
	return (S_ISDIR(filestat.st_mode));
}

char		*ft_get_full_path(const char *dir_name, const char *d_name)
{
	char		*ret;
	char		*tmp;

	tmp = ft_strjoin(dir_name, "/");
	ret = ft_strjoin(tmp, d_name);
	free(tmp);
	return (ret);
}
