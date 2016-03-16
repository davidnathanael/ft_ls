/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 13:01:20 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/16 13:01:21 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_free_args(t_command *command)
{
	unsigned int	nb_args;

	nb_args = command->nb_args;
	while (--nb_args <= 0)
		free(command->args[nb_args]);
	free(command);
}

static t_command	*ft_set_args(int ac, char **av, t_command *command)
{
	unsigned int		i;

	i = 0;
	if (command->has_options)
		command->has_args = (ac > 2) ? TRUE : FALSE;
	else
		command->has_args = (ac > 1) ? TRUE : FALSE;
	command->nb_args = (command->has_options) ? ac - 2 : ac - 1;
	command->args = (char **)malloc(sizeof(char *) * command->nb_args + 1);
	if (!command->args)
		return (NULL);
	while (i < command->nb_args)	
	{
		command->args[i] = ft_strdup(av[1 + command->has_options + i]);
		i++;
	}
	command->args[i] = NULL;
	return (command);
}

static t_command	*ft_init_args(t_opt *options)
{
	t_command	*command;

	command = (t_command *)malloc(sizeof(t_command));
	if (!command)
		return (NULL);
	command->has_options = (options->has_options) ? TRUE : FALSE;
	command->has_args = FALSE;
	command->nb_args = 0;
	command->args = NULL;
	return (command);
}

t_command			*ft_get_args(int ac, char **av, t_opt *options)
{
	t_command	*command;

	command = ft_init_args(options);
	command = ft_set_args(ac, av, command);
	return (command);
}
