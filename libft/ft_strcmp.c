/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:48:25 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/11/30 16:04:42 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int		ft_strcmp(const char *s1, const char *s2)
{
	if (s1 != NULL && s2 != NULL)
	{
		while (*s1 && *s2 && (unsigned char)*s1 == (unsigned char)*s2)
		{
			s1++;
			s2++;
		}
		return ((unsigned char)*s1 - (unsigned char)*s2);
	}
	return (0);
}
