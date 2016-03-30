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
	ft_printf("{red}------OPTIONS------{eoc}\n");
	ft_printf("l -> {green}%d{eoc}\n", options->l);
	ft_printf("R -> {green}%d{eoc}\n", options->r_upper);
	ft_printf("a -> {green}%d{eoc}\n", options->a);
	ft_printf("r -> {green}%d{eoc}\n", options->r);
	ft_printf("t -> {green}%d{eoc}\n", options->t);
	ft_printf("1 -> {green}%d{eoc}\n", options->one);
}

void	ft_debug_ls(t_ls *ls)
{
	int		nb_args = ls->nb_args;
	int		i = 0;

	ft_printf("{red}------LS INFOS------{eoc}\n");
	ft_printf("has_options -> {green}%d{eoc}\n", ls->has_options);
	ft_printf("has_args -> {green}%d{eoc}\n", ls->has_args);
	ft_printf("nb_args -> {green}%d{eoc}\n", (int)ls->nb_args);
	while (i < nb_args)
	{
		ft_printf("args[%d] -> {blue}%s{eoc}\n", i, ls->args[i]);
		i++;
	}
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


void ft_debug_list(t_list *list)
{
	t_list	*tmp;
	t_ent	*content;

	tmp = list;
	content = NULL;
	ft_printf("{red}------LIST INFOS------{eoc}\n");
	while (tmp)
	{
		content = tmp->content;
		ft_printf("name : %s\n", content->name);
		ft_printf("filepath : %s\n", content->filepath);
		ft_printf("isdir : %s\n\n", (content->isdir) ? "TRUE" : "FALSE");
		tmp = tmp->next;
	}
}

void ft_debug_list_args(t_list *list)
{
	t_list	*tmp;

	tmp = list;
	ft_printf("{red}------LIST ARGS------{eoc}\n");
	while (tmp)
	{
		ft_printf("arg : %s\n", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("{red}---------------------{eoc}\n");
}

void ft_debug_widths(t_widths *widths)
{
	ft_printf("{red}------WIDTHS------{eoc}\n\n");
	ft_printf("nb_links_width -> {green}%d{eoc}\n", widths->nb_links);
	ft_printf("user -> {green}%d{eoc}\n", widths->user);
	ft_printf("group-> {green}%d{eoc}\n", widths->group);
	ft_printf("{red}------------------{eoc}\n\n");
}