/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 10:02:42 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/28 08:41:05 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

wchar_t	*ft_wstrdup(wchar_t const *s1)
{
	int		x;
	wchar_t	*s2;

	x = 0;
	if (!s1)
		return (NULL);
	while (s1[x])
		x++;
	s2 = (wchar_t *)ft_memalloc((sizeof(wchar_t) * (x + 1)));
	if (!s2)
		return (0);
	ft_memcpy(s2, s1, sizeof(wchar_t) * x);
	return (s2);
}
