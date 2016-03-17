/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:28:06 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/14 14:28:08 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_debug_options(t_opt *options)
{
	ft_printf("has_options -> {red}%d{eoc}\n", options->has_options);
	ft_printf("l -> {red}%d{eoc}\n", options->l);
	ft_printf("R -> {red}%d{eoc}\n", options->r_upper);
	ft_printf("a -> {red}%d{eoc}\n", options->a);
	ft_printf("r -> {red}%d{eoc}\n", options->r);
	ft_printf("t -> {red}%d{eoc}\n", options->t);
	ft_printf("1 -> {red}%d{eoc}\n", options->one);
}

void	ft_debug_ls(t_ls *ls)
{
	ft_printf("has_options -> {red}%d{eoc}\n", ls->has_options);
	ft_printf("has_args -> {red}%d{eoc}\n", ls->has_args);
	ft_printf("nb_args -> {red}%d{eoc}\n", (int)ls->nb_args);
}

void	ft_debug_list_dir(char *name)
{
	DIR			*dirp;
	t_dirent	*dp;

	dirp = opendir(name);
	if (dirp == NULL)
		exit(-1);
	while ((dp = readdir(dirp)) != NULL)
		ft_printf("%s\n", dp->d_name);
	(void)closedir(dirp);
}

