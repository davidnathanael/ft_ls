/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 16:06:30 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/01/08 16:07:48 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchrstr(char *to_search, char *map)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	while (i < (int)ft_strlen(to_search))
	{
		if ((ret = ft_strchr(map, to_search[i])) != NULL)
			return (ret);
		i++;
	}
	return (ret);
}
