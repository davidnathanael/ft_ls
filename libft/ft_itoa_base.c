/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adomingu <adomingu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/29 06:36:28 by adomingu          #+#    #+#             */
/*   Updated: 2016/03/11 13:58:03 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa_base(unsigned long long n, char *base)
{
	char				*s;
	unsigned long long	i;
	char				*tmp1;
	char				*tmp2;

	i = ft_strlen(base);
	tmp1 = NULL;
	tmp2 = NULL;
	if (!(s = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	if (n >= i)
	{
		free(s);
		tmp1 = ft_itoa_base(n / i, base);
		tmp2 = ft_itoa_base(n % i, base);
		s = ft_strjoin(tmp1, tmp2);
		free(tmp1);
		free(tmp2);
	}
	else if (n < i)
	{
		s[0] = base[n];
		s[1] = '\0';
	}
	return (s);
}
