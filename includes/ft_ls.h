/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:32:02 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/14 13:32:04 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <errno.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <dirent.h>
# include "printf.h"
# include "libft.h"

# define TRUE			1
# define FALSE			0
# define INVALID_OPTION -1
# define BUFF_SIZE		1024

typedef unsigned char	t_bool;
typedef struct dirent	t_dirent;

typedef struct			s_opt
{
	t_bool				has_options;
	t_bool				l;
	t_bool				r_upper;
	t_bool				a;
	t_bool				r;
	t_bool				t;
	t_bool				one;
}						t_opt;

typedef struct			s_ls
{
	t_bool				has_options;
	t_bool				has_args;
	unsigned int		nb_args;
	char				**args;
}						t_ls;

typedef struct 			s_arg
{
	char				*name;
	char				*filepath;
	t_bool				isdir;
	struct s_arg		*next;
}						t_arg;

void					ft_ls(int ac, char **av);

t_opt					*ft_get_ls_options(char **av);
t_ls					*ft_get_ls_args(int ac, char **av, t_opt *options);
void					ft_free_args(t_ls *ls);

t_bool					ft_sort_util_alpha(char *elem1, char *elem2);
t_bool					ft_sort_util_alpharev(char *elem1, char *elem2);

void					ft_debug_options(t_opt *options);
void					ft_debug_ls(t_ls *ls);
void					ft_debug_list_dir(char *name);

#endif
