/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 18:19:44 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/11/30 16:04:26 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int		len1;
	int		len2;

	if (!*s2)
		return ((char *)s1);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	while (*s1 && len1 >= len2)
	{
		if (ft_strncmp(s1, s2, len2) == 0)
		{
			return ((char *)s1);
		}
		s1++;
		len1--;
	}
	return (NULL);
}
