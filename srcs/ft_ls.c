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
#include <limits.h>

void		ft_proceed_r_upper(char *dir_name, char *d_name, t_opt *options);

t_bool			ft_is_dir(const char *path)
{
	t_stat		statbuf;
	if (stat(path, &statbuf) != 0)
		return (0);
	return S_ISDIR(statbuf.st_mode);
}

t_bool			ft_is_dot(const char *d_name)
{
	if (ft_strcmp (d_name, "..") != 0 && ft_strcmp (d_name, ".") != 0)
		return (FALSE);
	return (TRUE);
}

char			*ft_get_full_path(const char *dir_name, const char *d_name)
{
	char		*ret;
	char		*tmp;

	tmp = ft_strjoin(dir_name, "/");
	ret = ft_strjoin(tmp, d_name);
	free(tmp);
	return (ret);
}

DIR				*ft_opendir(char *dir_name)
{
	DIR			*dir;
	
	dir = opendir (dir_name);
	if (!dir)
	{
		fprintf (stderr, "Cannot open directory '%s': %s\n",
			dir_name, strerror (errno));
		exit (EXIT_FAILURE);
	}
	return (dir);
}

void			ft_closedir(DIR *dir, const char *dir_name)
{
	if (closedir (dir)) {
		fprintf (stderr, "Could not close '%s': %s\n",
			dir_name, strerror (errno));
		exit (EXIT_FAILURE);
	}	
}

static void		ft_list_dir(char *dir_name, t_opt *options)		
{
	DIR			*d;
	t_dirent	*entry;
	const char	*d_name;
	char		*fullpath;

	d = ft_opendir(dir_name);
	while ((entry = readdir (d)) != NULL)
	{
		d_name = entry->d_name;
		fullpath = ft_get_full_path(dir_name, d_name);
		if (!ft_is_dot(d_name))
			printf ("%s/%s\n", dir_name, d_name);
		if (ft_is_dir(fullpath) && options->r_upper)
			ft_proceed_r_upper(dir_name, (char *)d_name, options);
		free(fullpath);
	}
	ft_closedir(d, dir_name);
}

void		ft_proceed_r_upper(char *dir_name, char *d_name, t_opt *options)
{
	int path_length;
	char path[PATH_MAX];

	if (!ft_is_dot(d_name))
	{

		path_length = snprintf (path, PATH_MAX,
			"%s/%s", dir_name, d_name);
		if (path_length >= PATH_MAX) {
			fprintf (stderr, "Path length has got too long.\n");
			exit (EXIT_FAILURE);
		}
		ft_list_dir (path, options);
	}
}

void			ft_ls(int ac, char **av)
{
	t_opt	*options;
	t_ls	*ls;

	options = ft_get_ls_options(av);
	ls = ft_get_ls_args(ac, av, options);
	ft_debug_options(options);
	ft_debug_ls(ls);
	ft_printf("\n\n\n\n");
	if (!ls->has_args)
		ft_list_dir(".", options);
	else
	{
		while (*ls->args)
			ft_list_dir(*ls->args++, options);
	}
}