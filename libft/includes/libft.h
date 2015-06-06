/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabadie <jabadie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:28:01 by jabadie           #+#    #+#             */
/*   Updated: 2015/06/04 03:54:58 by jabadie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <inttypes.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 1024

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_chlst
{
	char			*str;
	struct s_chlst	*next;
}					t_chlst;

typedef struct		s_btree
{
	void			*item;
	struct s_btree	*right;
	struct s_btree	*left;
}					t_btree;

void				replace_comment(char *str, char c);

int					get_next_line(int const fd, char **line);

void				ft_tabtospace(char *str);

void				add_last(t_chlst *lst, char *str);
int					destroy_last(t_chlst *lst);

char				*ft_chlst_to_ch(t_chlst *first);
void				ft_lstdelall(t_chlst *lst);
char				*ft_chch_to_ch(char **str);
void				ft_error(char *str, char *str2);

int					ft_ptrlen(char **str);
char				**ft_ptrstrnew(int size);

long int			ft_atoi(char *str);
char				*ft_itoa(intmax_t n);
char				*ft_unsigned_itoa(uintmax_t nb);

void				ft_bzero(void *s, size_t n);
void				*ft_memalloc(size_t size);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				ft_memdel(void **ap);
void				*ft_memset(void *b, int c, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);

char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);

int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t n);

int					ft_strequ(const char *s1, const char *s2);
int					ft_strnequ(const char *s1, const char *s2, size_t n);

void				ft_striter(char *s, void (*f)(char*));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char				*ft_strstr(const char *s1, const char *s2);
char				*ft_strnstr(const char *s1, const char *s2, size_t n);

char				*ft_strjoin(char const *s1, char const *s2);
int					ft_strlen(const char *s);
int					ft_wstrlen(wchar_t *s);
int					ft_wchlen(wchar_t c);

void				ft_strdel(char **as);
char				*ft_strdup(const char *s1);
char				*ft_strndup(char *str, int n);
char				*ft_strnew(size_t size);

wchar_t				*ft_wstrnew(int	size);
void				ft_strclr(char *s);
char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				**ft_strsplit(char const *s, char c);
char				*ft_strtrim(char const *s);
char				*ft_strmore(char *s1, char *s2);

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl(char const *s);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr(long int n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putfloat(long double nb);
int					ft_putstr(char const *s);
void				ft_putstr_fd(char const *s, int fd);
int					ft_putwchar(wchar_t c);
int					ft_putwstr(wchar_t *s);

int					ft_isupper(char c);
int					ft_isalnum(int c);
int					ft_isalpha(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);

int					ft_tolower(int c);
int					ft_toupper(int c);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_chlst				*ft_chlstnew(char *str);
t_chlst				*ft_ch_to_chlst(char **str);
t_chlst				*ft_strsplit_lst(char *str, char c);
void				add_before_last(t_chlst *lst, char *str);

void				ft_btreeapply(t_btree *root, void (*applyf)(void *));
void				ft_btreeinsert(t_btree **root, void *item,
												int (*cmpf)(void *, void *));
t_btree				*ft_btreenew(void *item);
void				*ft_btreesearch(t_btree *root, void *data_ref,
												int (*cmpf)(void *, void *));

void				ft_tabint_sort(int *tab, int size);
long int			ft_pow(int nb, int power);
long double			ft_sqrt(long double nb);

char				*dec_to_bin(uintmax_t nb);
uintmax_t			ft_bin_to_dec(char *str);

char				**ft_strsplit_ctab(char const *s, char *c);
t_chlst				*ft_strsplit_nbr(char *str, int i);
t_chlst				*new_chlst(void);
char				**ft_chlst_to_chch(t_chlst *lst);

int					ft_nblen(long int nb);
int					ft_lstlen(t_chlst *lst);

long int			*float_to_int(long double real, int prec);
void				free_chch(char **str);
#endif
