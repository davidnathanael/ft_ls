/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:32:16 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/14 13:32:17 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
	
#include <stdlib.h>
#include "ft_ls.h"
#include "printf.h"
#include "libft.h"

void			ft_handle_invalid_option(unsigned char option, t_opt *options)
{
	ft_printf("ls: illegal option -- %c\n", option);
	ft_printf("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]\n");
	free(options);
	exit(INVALID_OPTION);
}

static t_opt	*ft_parse_options(t_opt *options, char **av, int i)
{
	while (av[1][i])
	{
		if (av[1][i] == 'l')
			options->l = TRUE;
		else if (av[1][i] == 'R')
			options->r_upper = TRUE;
		else if (av[1][i] == 'a')
			options->a = TRUE;
		else if (av[1][i] == 'r')
			options->r = TRUE;
		else if (av[1][i] == 't')
			options->t = TRUE;
		else if (av[1][i] == '1')
			options->one = TRUE;
		else
			ft_handle_invalid_option(av[1][i], options);
		i++;
	}
	if (options->l || options->r_upper || options->a || options->r || options->t
					|| options->one)
		options->has_options = TRUE;
	return (options);
}

static t_opt	*ft_init_options()
{
	t_opt	*options;

	options = malloc(sizeof(t_opt *));
	if (!options)
		return (NULL);
	options->has_options = FALSE;
	options->l = FALSE;
	options->r_upper = FALSE;
	options->a = FALSE;
	options->r = FALSE;
	options->t = FALSE;
	options->one = FALSE;
	return (options);
}

t_opt	*ft_get_options(int ac, char **av)
{
	t_opt	*options;
	int		len;
	int		index;

	options = ft_init_options();
	len = ft_strlen(av[1]);
	index = 1;
	if (ac > 1 && av[1][0] == '-' && len > 1) 
	{
		if (av[1][1] == '-' && len == 2)
			return (options);
		else
			index = 2;
		options = ft_parse_options(options, av, index);
	}
	return (options);
}
