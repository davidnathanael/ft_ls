/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 19:10:01 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/11/30 16:04:28 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int		passe;
	int		i;
	int		j;

	if (!*s2)
		return ((char *)s1);
	i = 0;
	while (s1[i] && n > 0)
	{
		j = 0;
		if (n < ft_strlen(s2))
			return (NULL);
		passe = i;
		while (s1[passe] == s2[j] && s2[j] && s1[passe])
		{
			j++;
			passe++;
		}
		if (s2[j] == '\0')
			return ((char *)s1 + i);
		n--;
		i++;
	}
	return (NULL);
}
