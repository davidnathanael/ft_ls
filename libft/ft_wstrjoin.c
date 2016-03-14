/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstrjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 12:14:12 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/27 14:40:59 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

wchar_t	*ft_wstrjoin(wchar_t *s1, wchar_t *s2)
{
	int		i;
	int		j;
	wchar_t	*str;

	i = ft_wstrlen(s1);
	i += ft_wstrlen(s2);
	j = 0;
	str = (wchar_t *)malloc(sizeof(wchar_t) * (i + 1));
	if (!str)
		return (NULL);
	while (*s1)
		str[j++] = *s1++;
	while (*s2)
		str[j++] = *s2++;
	str[j] = '\0';
	return (str);
}
