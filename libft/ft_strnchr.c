/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/07 22:15:19 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/08 13:31:33 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnchr(const char *s, int c, int n)
{
	int		count;
	char	*str;

	count = 0;
	str = (char *)s;
	while (count < n)
	{
		str = ft_strchr(str, c);
		count++;
		if (count != n)
			str++;
		if (!*str)
			return (NULL);
	}
	return (str);
}
