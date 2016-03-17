/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:02:12 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/11/30 16:04:57 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*crt;

	crt = (*f)(lst);
	if (crt == NULL)
		return (NULL);
	new = crt;
	lst = lst->next;
	while (lst)
	{
		crt->next = (*f)(lst);
		if (crt->next == NULL)
			return (NULL);
		crt = crt->next;
		lst = lst->next;
	}
	return (new);
}
