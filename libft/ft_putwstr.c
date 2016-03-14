/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putwstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/19 10:17:03 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/19 18:31:31 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_putwstr(wchar_t *str)
{
	int		result;

	result = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (*str)
		result += ft_putwchar(*str++);
	return (result);
}
