/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/22 16:06:58 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/22 16:07:01 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

t_list		*ft_get_sorted_list(char *dir_name, t_opt options)
{
	t_list		*list;
	t_list		*elem;
	DIR			*dir;
	t_dirent	*entry ;
	

	list = NULL;
	dir = ft_opendir(dir_name);
	while ((entry = readdir (dir)) != NULL)
	{
		list = ft_push(list, options, entry)
	}
	ft_closedir(dir, dir_name);
	return (list)
}