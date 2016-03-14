/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:03:15 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/11/30 16:04:37 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char		*strdst;
	const char	*source;
	size_t		n;
	size_t		len;

	strdst = dst;
	source = src;
	n = size;
	while (n-- != 0 && *strdst != '\0')
		strdst++;
	len = strdst - dst;
	n = size - len;
	if (n == 0)
		return (len + ft_strlen(source));
	while (*source != '\0')
	{
		if (n != 1)
		{
			*strdst++ = *source;
			n--;
		}
		source++;
	}
	*strdst = '\0';
	return (len + (source - src));
}
