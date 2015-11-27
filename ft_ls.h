/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: frcugy <frcugy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 18:54:48 by frcugy            #+#    #+#             */
/*   Updated: 2015/01/02 11:31:05 by frcugy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <grp.h>
# include <sys/types.h>
# include <pwd.h>
# include <time.h>
# include <errno.h>
# include <sys/xattr.h>
# include <stdio.h>
# include <time.h>
# include <sys/acl.h>
# include <fcntl.h>

typedef struct			s_bol
{
	int					l;
	int					r;
	int					a;
	int					re;
	int					t;
	int					multi;
	int					hidprint;
	int					tmp;
}						t_bol;

typedef struct			s_info
{
	char				*file_name;
	struct stat			time;
	struct s_info		*next;
	struct s_info		*prev;
}						t_info;

typedef struct stat		t_stat;
typedef struct dirent	t_dir;

t_bol					ft_init_struct(void);
t_bol					ft_fetch_option(char **tab);
void					ft_first_check(char **tab);
char					**ft_sort_time(char **tab, char *dir, t_bol bol);
char					**ft_sort_ascii(char **tab, int r);
int						ft_len_tab(char **tab);
int						ft_sort_dir_files(char *str, t_bol bol);
char					**ft_realloc_tab(char **tab, char *str);
void					ft_free_tab(char **tab, int tmp);
int						ft_len_tab(char **tab);
void					ft_tab_split(char **tab, t_bol bol);
t_bol					ft_print_files(char **files, t_bol bol);
t_stat					ft_get_stat(char *dir, char *str);
int						*ft_init_int(void);
int						ft_name_size(char *name, int size);
int						ft_get_nb_size(int size, int size2);
int						ft_name_size(char *name, int size);
int						*ft_get_spaces_size(int *s, char **t, char *d, t_bol b);
void					ft_write_right(mode_t mode);
void					ft_write_types(mode_t mode);
void					ft_print_files_l(char **tab);
void					ft_write_nb(int size, int nb);
int						ft_check_atx(char **tab);
void					ft_write_atx(char *str);
void					ft_write_str(char *str, int size);
void					ft_write_time(time_t *time);
void					ft_write_maj_min(int *size, int maj, int min);
void					ft_write_link(char *str, char *path);
void					ft_sort_tab(char **files, char **dir, t_bol bol);
void					ft_write_l(char *tab, int *size, char *path);
int						ft_count_files(char *dir);
char					**ft_fetch_files(char *dir, char **files);
void					ft_hub_dir(char *dir, t_bol bol);
void					ft_print_dir(char **dir, t_bol bol, char *path);
void					ft_print_dir_l(char *path, char **files, t_bol bol);
void					ft_recursive(char **dir, t_bol bol, char *path);
char					**ft_mini_sort(char **tab, t_bol bol);
int						ft_get_hide(char **files);
void					ft_write_nb_gid(int size, int nb);
#endif
