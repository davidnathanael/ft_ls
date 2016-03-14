/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:24:40 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/18 17:14:54 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;
	int		i;

	str = ft_strnew(len);
	if (!str)
		return (NULL);
	i = 0;
	while (len && s)
	{
		str[i] = s[start + i];
		len--;
		i++;
	}
	return (str);
}
