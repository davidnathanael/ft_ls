/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 15:58:17 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/22 15:58:20 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

t_bool			ft_is_dir(const char *path)
{
	t_stat		statbuf;
	if (stat(path, &statbuf) != 0)
		return (0);
	return S_ISDIR(statbuf.st_mode);
}
