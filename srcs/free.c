/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 14:22:58 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/04/01 14:23:00 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_free_elem(t_list *elem)
{
	ft_free_content(elem->content);
	elem->content = NULL;
	free(elem);
}

void	ft_free_content(t_ent *content)
{
	free(content->name);
	content->name = NULL;
	free(content->filepath);
	content->filepath = NULL;
	free(content);
}
