/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 10:01:48 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/25 10:04:37 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrsub(wchar_t *str, unsigned int start, unsigned int len)
{
	size_t			i;
	wchar_t			*new;
	unsigned int	this;

	this = 0;
	new = ft_memalloc(sizeof(wchar_t) * (len + 1));
	if (new)
	{
		i = 0;
		while (this + ft_wcharlen(str[i + start]) <= len)
		{
			new[i] = str[i + start];
			this += ft_wcharlen(new[i]);
			i++;
		}
		new[i] = '\0';
	}
	return (new);
}
