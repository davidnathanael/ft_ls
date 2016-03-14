/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/26 12:08:51 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/27 14:41:00 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strreplace(char *str, char *to_replace, char *replace)
{
	char	*s1;
	char	*s2;
	char	*tmp;
	int		i;

	i = ft_strstr(str, to_replace) - str;
	s1 = ft_strsub(str, 0, i);
	s2 = ft_strsub(str, i + ft_strlen(to_replace), \
			ft_strlen(str) - (i + ft_strlen(to_replace)));
	tmp = ft_strjoin(s1, replace);
	free(s1);
	s1 = ft_strjoin(tmp, s2);
	free(tmp);
	free(s2);
	return (s1);
}
