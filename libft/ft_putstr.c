/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:48:02 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/19 09:46:51 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

size_t		ft_putstr(char const *s)
{
	int		nbr;

	if (s)
	{
		nbr = ft_strlen(s);
		write(1, s, nbr);
		return (nbr);
	}
	else
		return (ft_putstr("(null)"));
}
