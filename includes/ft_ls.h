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
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include "printf.h"
# include "libft.h"


# define TRUE				1
# define FALSE				0
# define INVALID_OPTION 	-1
# define BUFF_SIZE			1024

# define NB_LINKS_MINWIDTH	2
# define USER_MINWIDTH		0
# define GROUP_MINWIDTH		0
# define SIZE_MINWIDTH		2

typedef unsigned char	t_bool;
typedef struct dirent	t_dirent;
typedef struct stat		t_stat;


typedef struct 			s_widths
{
	unsigned int		nb_links;
	unsigned int		user;
	unsigned int		group;
	unsigned int		size;
}						t_widths;

typedef struct			s_opt
{
	t_bool				has_options;
	t_bool				l;
	t_bool				r_upper;
	t_bool				 a;
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

typedef struct 			s_ls_infos
{
	t_ls				*ls;
	t_opt				*options;
	t_widths			*widths;
}						t_ls_infos;

typedef struct 			s_ent
{
	t_dirent			*ent;
	char				*name;
	char				*filepath;
	t_bool				isdir;
}						t_ent;

void					ft_ls(int ac, char **av);

DIR						*ft_opendir(char *dir_name);
void					ft_closedir(DIR *dir, const char *dir_name);
t_bool					ft_is_dir(const char *path);
char					*ft_get_full_path(const char *dir_name, const char *d_name);

t_opt					*ft_get_ls_options(char **av);
t_ls					*ft_get_ls_args(char **av, t_opt *options);

t_widths				*ft_init_ls_widths();
void					ft_update_widths(t_ent* ent, t_widths *widths);

t_list					*ft_get_sorted_list(char *dir_name, t_ls_infos *infos);
t_bool					ft_sort_util_alpha(char *elem1, char *elem2);
t_bool					ft_sort_util_alpharev(char *elem1, char *elem2);

void            		ft_proceed_printing(t_list *list, t_ls_infos *infos);

void					ft_debug_options(t_opt *options);
void					ft_debug_ls(t_ls *ls);
void					ft_debug_list_dir(char *name);
void 					ft_debug_list(t_list *list);
void					ft_debug_widths(t_widths *widths);

#endif
