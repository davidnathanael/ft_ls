/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 16:04:49 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/18 17:15:07 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_setword(char const *s, char c)
{
	int		len;
	int		i;
	char	*str;

	i = 0;
	len = 0;
	while (s[len] != c && s[len])
		len++;
	str = (char *)malloc(sizeof(str) * len + 1);
	if (!str)
		return (NULL);
	while (s[i] != c && s[i])
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

int		ft_countwords(char const *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[0] != c && *str)
		count++;
	while (str[i])
	{
		if (i > 0)
		{
			if (str[i] != c && str[i - 1] == c)
				count++;
		}
		i++;
	}
	return (count);
}

char	**ft_strsplit(char const *s, char c)
{
	int		i;
	int		nbwords;
	char	**tab;

	if (!s)
		return (NULL);
	i = 0;
	nbwords = ft_countwords(s, c);
	tab = (char **)malloc(sizeof(char *) * nbwords + 1);
	if (!tab)
		return (NULL);
	while (i < nbwords)
	{
		while (*s == c && *s)
			s++;
		tab[i] = ft_setword(s, c);
		while (*s != c && *s)
			s++;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
