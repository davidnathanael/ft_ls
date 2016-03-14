/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:58:42 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/11/30 16:04:51 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp;
	const char	*tmp2;

	tmp = dst;
	tmp2 = src;
	if (tmp2 <= tmp)
	{
		tmp = tmp + len - 1;
		tmp2 = tmp2 + len - 1;
		while (len--)
			*tmp-- = *tmp2--;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
