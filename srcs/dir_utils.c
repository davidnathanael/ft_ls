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

DIR				*ft_opendir(char *dir_name)
{
	DIR			*dir;

	dir = opendir(dir_name);
	if (!dir)
	{
		fprintf(stderr, "Cannot open directory '%s': %s\n",
			dir_name, strerror(errno));
	}
	return (dir);
}

void			ft_closedir(DIR *dir, const char *dir_name)
{
	if (closedir(dir))
	{
		fprintf(stderr, "Could not close '%s': %s\n",
			dir_name, strerror(errno));
		exit(EXIT_FAILURE);
	}
}

t_bool			ft_is_dir(const char *path)
{
	t_stat		filestat;

	if (stat(path, &filestat) != 0)
		return (0);
	return (S_ISDIR(filestat.st_mode));
}

t_bool			ft_is_ent(const char *path)
{
	t_stat		filestat;

	if (stat(path, &filestat) != 0)
		return (FALSE);
	return (TRUE);
}

t_bool			ft_is_dot(const char *d_name)
{
	if (ft_strcmp(d_name, "..") != 0 && ft_strcmp(d_name, ".") != 0)
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
