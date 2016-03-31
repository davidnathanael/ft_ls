/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddela-cr <ddela-cr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 13:32:02 by ddela-cr          #+#    #+#             */
/*   Updated: 2016/03/31 13:22:19 by ddela-cr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <errno.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/acl.h>
# include <sys/stat.h>
# include <sys/xattr.h>
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>
# include <limits.h>
# include "printf.h"
# include "libft.h"

# define TRUE				1
# define FALSE				0
# define INVALID_OPTION 	-1
# define BUFF_SIZE			1024

# define NB_LINKS_MINWIDTH	1
# define USER_MINWIDTH		0
# define GROUP_MINWIDTH		1
# define SIZE_MINWIDTH		1
# define MAJ_MINWIDTH		2
# define MIN_MINWIDTH		1

# define MTIME				0
# define ATIME				1
# define CTIME				2

typedef unsigned char	t_bool;
typedef unsigned char	t_time;
typedef struct dirent	t_dirent;
typedef struct stat		t_stat;

typedef struct			s_widths
{
	unsigned int		nb_links;
	unsigned int		user;
	unsigned int		group;
	unsigned int		size;
	unsigned int		maj;
	unsigned int		min;
}						t_widths;

typedef struct			s_opt
{
	t_bool				has_options;
	t_bool				l;
	t_bool				r_upper;
	t_bool				a;
	t_bool				r;
	t_bool				t;
	t_bool				t_upper;
	t_bool				one;
	t_bool				u;
}						t_opt;

typedef struct			s_ls
{
	t_bool				has_options;
	t_bool				has_args;
	unsigned int		nb_args;
	t_list				*sorted_args;
}						t_ls;

typedef struct			s_ls_infos
{
	t_ls				*ls;
	t_opt				*options;
}						t_ls_infos;

typedef struct			s_list_infos
{
	t_list				*list;
	t_widths			*widths;
	unsigned int		total;
	t_bool				has_maj_min;
}						t_list_infos;

typedef struct			s_ent
{
	t_dirent			*ent;
	char				*name;
	char				*filepath;
	long				mtime;
	t_bool				is_ent;
	t_bool				is_dir;
}						t_ent;

void					ft_ls(char **av);


void					ft_proceed_r_upper(char *dir_name, t_ls_infos *infos,
							t_list_infos *list_holder, t_ent *ent);
DIR						*ft_opendir(char *dir_name);
void					ft_closedir(DIR *dir, const char *dir_name);
t_bool					ft_is_dir(const char *path);
t_bool					ft_is_ent(const char *path);
char					*ft_get_full_path(const char *dir_name,
						const char *d_name);

t_opt					*ft_get_ls_options(char **av);
t_ls					*ft_get_ls_args(char **av, t_opt *options);
t_list					*ft_get_sorted_args(char *path, t_list *list,
						t_opt *options);

t_widths				*ft_init_widths(void);
void					ft_update_widths(t_ent *ent, t_list_infos *list_holder);

unsigned int			ft_get_blocks(t_ent *ent, t_ls_infos *infos);
long					ft_get_time(char *filepath, t_time time);

t_list					*ft_get_sorted_list(char *dir_name,
						t_list_infos *list_holder, t_ls_infos *infos);
t_bool					(*g_ft_get_cmp_func(t_opt *options))(t_ent *ent1,
						t_ent *ent2);
t_bool					ft_sort_util_alpha(t_ent *ent1, t_ent *ent2);
t_bool					ft_sort_util_alpharev(t_ent *ent1, t_ent *ent2);
t_bool					ft_sort_util_alpharev_arg(t_ent *ent1, t_ent *ent2);
t_bool					ft_sort_util_chrono(t_ent *ent1, t_ent *ent2);
t_bool					ft_sort_util_chronorev(t_ent *ent1, t_ent *ent2);
t_bool					ft_sort_util_atime(t_ent *ent1, t_ent *ent2);
t_bool					ft_sort_util_atimerev(t_ent *ent1, t_ent *ent2);

void					ft_proceed_printing(t_list_infos *list_holder,
						t_ls_infos *infos);

void					ft_debug_options(t_opt *options);
void					ft_debug_ls(t_ls *ls);
void					ft_debug_list_dir(char *name);
void					ft_debug_list(t_list *list);
void					ft_debug_list_args(t_list *list);
void					ft_debug_widths(t_widths *widths);
void					ft_debug_arg_content(t_ent *content);

#endif
