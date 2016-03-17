/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_command.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:01:20 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/16 13:01:21 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bool			ft_is_ent(char *name, char *path)
{
	DIR			*dirp;
	t_dirent	*dp;

	dirp = opendir(path);
	if (dirp == NULL)
	{
		ft_printf("opendir() failed.\n");
		return FALSE;
	}
	while ((dp = readdir(dirp)) != NULL)
	{
		if (ft_strcmp(dp->d_name, name) == 0)
		{
			(void)closedir(dirp);
			return (TRUE);
		}
	}
	(void)closedir(dirp);
	return (FALSE);
}

static void		ft_sort_av(t_ls *ls, char **av)
{
	unsigned int		i;
	unsigned int		j;
	char				tmp[BUFF_SIZE];

	i = 1 + ls->has_options + 1; // argv[0] + options + 1 for sort
	j = 1 + ls->has_options + 1;
	while (i <= ls->nb_args + ls->has_options + 1)	
	{
		while (j <= ls->nb_args + ls->has_options + 1)	
		{
			ft_printf("i : %d | j : %d\n", i , j);
			if (ft_strcmp(av[j - 1], av[j]) > 0) {
	for (unsigned int k = 0; k < ls->has_options + 1 + ls->nb_args; k++)
	{
		ft_printf("%s ", av[k]);
	}
				printf("\ntmp : %s | av[%d] : %s | av[%d] : %s \n", tmp, j - 1, av[j - 1], j, av[j]);
				ft_strcpy(tmp, av[j - 1]);
				ft_strcpy(av[j - 1], av[j]);
				ft_strcpy(av[j], tmp);
				printf("tmp : %s | av[%d] : %s | av[%d] : %s \n", tmp, j - 1, av[j - 1], j, av[j]);
			}
			j++;
		}
		j = 1 + ls->has_options + 1;
		i++;
	}
}

static t_list	*ft_parse_ls_args(t_ls *ls, char **av)
{
	unsigned int		i;

	i = (ls->has_options) ? 2 : 1;
	ft_printf("BEFORE\n\n");
	for (unsigned int k = 0; k < ls->has_options + 1 + ls->nb_args; k++)
	{
		ft_printf("av[%d] : %s\n", (int)k, av[k]);
	}
	ft_sort_av(ls, av);
	ft_printf("AFTER\n\n");
	for (unsigned int k = 0; k < ls->has_options + 1 + ls->nb_args; k++)
	{
		ft_printf("av[%d] : %s\n", (int)k, av[k]);
	}
	while (av[i])	
	{
		if (ft_is_ent(av[i], "."))
			;
		else
			ft_printf("ls: %s: No such file or directory\n", av[i]);
		i++;
	}
	return (NULL);
}

static t_ls		*ft_set_ls_args(int ac, char **av, t_ls *ls)
{
	unsigned int		i;

	i = 0;
	if (ls->has_options)
		ls->has_args = (ac > 2) ? TRUE : FALSE;
	else
		ls->has_args = (ac > 1) ? TRUE : FALSE;
	ls->nb_args = (ls->has_options) ? ac - 2 : ac - 1;
	if (ls->has_args)
		ls->args = ft_parse_ls_args(ls, av);
	return (ls);
}

static t_ls		*ft_init_ls_args(t_opt *options)
{
	t_ls	*ls;

	ls = (t_ls *)malloc(sizeof(t_ls));
	if (!ls)
		return (NULL);
	ls->has_options = (options->has_options) ? TRUE : FALSE;
	ls->has_args = FALSE;
	ls->nb_args = 0;
	ls->args = NULL;
	return (ls);
}

t_ls			*ft_get_ls_args(int ac, char **av, t_opt *options)
{
	t_ls	*ls;

	ls = ft_init_ls_args(options);
	ls = ft_set_ls_args(ac, av, ls);
	return (ls);
}
