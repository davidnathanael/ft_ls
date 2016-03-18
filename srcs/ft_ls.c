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

static void		ft_list_dir(char *dir_name, t_opt *options)		
{
	(void)	options;
	DIR		*d;

    d = opendir (dir_name);
    if (! d)
    {
        fprintf (stderr, "Cannot open directory '%s': %s\n",
                 dir_name, strerror (errno));
        exit (EXIT_FAILURE);
    }
    while (1)
    {
        t_dirent	*entry;
        const char	*d_name;

        entry = readdir (d);
        if (! entry)
            break;
        d_name = entry->d_name;
		printf ("%s/%s\n", dir_name, d_name);
        if (entry->d_type & DT_DIR)
        {
            if (strcmp (d_name, "..") != 0 && strcmp (d_name, ".") != 0)
            {
                int path_length;
                char path[PATH_MAX];
 
                path_length = snprintf (path, PATH_MAX,
                                        "%s/%s", dir_name, d_name);
                printf ("%s\n", path);
                if (path_length >= PATH_MAX) {
                    fprintf (stderr, "Path length has got too long.\n");
                    exit (EXIT_FAILURE);
                }
                ft_list_dir (path, options);
            }
		}
    }
    if (closedir (d)) {
        fprintf (stderr, "Could not close '%s': %s\n",
                 dir_name, strerror (errno));
        exit (EXIT_FAILURE);
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