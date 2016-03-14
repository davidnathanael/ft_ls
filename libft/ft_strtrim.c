/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 15:37:46 by ddela-cr          #+#    #+#             */
/*   Updated: 2015/12/18 17:14:36 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		len;
	int		start;
	int		end;

	start = 0;
	end = ft_strlen(s);
	while (s[start] && (ft_is_space(s[start]) != 0))
		start++;
	while (end > start && (ft_is_space(s[end]) != 0 || s[end] == 0))
		end--;
	if (start >= end)
		end = start - 1;
	len = end - start + 1;
	str = ft_strsub(s, start, len);
	return (str);
}
