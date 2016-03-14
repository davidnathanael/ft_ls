/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/19 11:43:21 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/19 18:56:41 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

int		ft_putwchar(wint_t x)
{
	size_t	j;
	char	c[4];
	wint_t	tmp;

	j = 1;
	if (x <= 0x7F)
		return (write(1, &x, 1));
	if (x > 0x1FFFFF)
		return (-1);
	while (1)
	{
		tmp = 63u & x;
		if (!(x >>= 6))
			break ;
		c[4 - j++] = 128u | tmp;
	}
	c[4 - j] = (-128 >> (j - 1)) | tmp;
	return (write(1, &(c[4 - j]), j));
}
