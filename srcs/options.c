/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:32:16 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/31 18:46:23 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_handle_invalid_ls_option(unsigned char option,
											t_opt *options)
{
	ft_printf("ls: illegal option -- %c\n", option);
	ft_printf("usage: ls [-ABCFGHLOPRSTUWabcdefghiklmnopqrstuwx1] [file ...]");
	ft_putchar('\n');
	free(options);
	exit(INVALID_OPTION);
}

static t_opt	*ft_handle_other_options(t_opt *options, char arg)
{
	if (arg == 'T')
		options->t_upper = TRUE;
	else
		ft_handle_invalid_ls_option(arg, options);
	return (options);
}

static t_opt	*ft_parse_ls_options(t_opt *options, char *arg)
{
	int		i;

	i = 1;
	while (arg[i])
	{
		if (arg[i] == 'l')
			options->l = TRUE;
		else if (arg[i] == 'R')
			options->r_upper = TRUE;
		else if (arg[i] == 'a')
			options->a = TRUE;
		else if (arg[i] == 'r')
			options->r = TRUE;
		else if (arg[i] == 't')
			options->t = TRUE;
		else if (arg[i] == '1')
			options->one = TRUE;
		else
			options = ft_handle_other_options(options, arg[i]);
		i++;
	}
	if (options->l || options->r_upper || options->a || options->r || options->t
					|| options->one)
		options->has_options = TRUE;
	return (options);
}

static t_opt	*ft_init_ls_options(void)
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
	options->t_upper = FALSE;
	options->one = FALSE;
	return (options);
}

t_opt			*ft_get_ls_options(char **av)
{
	int		len;
	int		i;
	t_opt	*options;

	len = 0;
	i = 1;
	options = ft_init_ls_options();
	if (!options)
		return (NULL);
	while (av[i] && av[i][0] == '-')
	{
		len = ft_strlen(av[i]);
		if ((av[i][1] == '-' && len == 2) || len <= 1)
		{
			return (options);
		}
		else
			options = ft_parse_ls_options(options, av[i]);
		i++;
	}
	return (options);
}
