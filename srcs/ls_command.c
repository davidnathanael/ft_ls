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

void			ft_free_ls_args(t_ls *ls)
{
	unsigned int	nb_args;

	nb_args = ls->nb_args;
	while (--nb_args <= 0)
		free(ls->args[nb_args]);
	free(ls);
}

static t_bool	ft_has_ls_args(t_ls *ls, char **av)
{
	unsigned int		i;
	size_t				len;
	t_bool				no_more_options;

	i = 0;
	len = 0;
	no_more_options = FALSE;
	while (av[++i])
	{
		len = ft_strlen(av[i]);
		if (av[i][0] != '-' || len == 1 || (len == 2 && av[i][1] == '-'))
			no_more_options = TRUE;
		if (no_more_options)
			ls->nb_args++;
	}
	return ((ls->nb_args > 0) ? TRUE : FALSE);
}

static t_ls		*ft_set_ls_args(int ac, char **av, t_ls *ls)
{
	unsigned int		i;

	i = 0;
	(void)ac;
	ls->has_args = ft_has_ls_args(ls, av);
	ls->args = (char **)malloc(sizeof(char *) * ls->nb_args + 1);
	if (!ls->args)
		return (NULL);
	i = 0;
	while (i < ls->nb_args)
	{
		ls->args[i] = ft_strdup(av[1 + ls->has_options + i]);
		i++;
	}
	ls->args[i] = NULL;
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
