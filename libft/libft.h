/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 14:20:21 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/03/20 16:58:36 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# define MAXL 9223372036854775807U
# define MAXUL 18446744073709551615U
# define WS(x) ((x) >= 8 && (x) <= 14) || (x) == 32

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef unsigned char	t_uc;
typedef unsigned int	t_ui;
typedef unsigned long	t_ul;

typedef struct		s_variables
{
	int				a;
	int				b;
	char			c;
	t_list			*lst;
	t_list			*lst2;
	t_list			*lst3;
	t_ui			d;
	t_ul			l;
	size_t			i;
	size_t			j;
	char			*str;
	char			*tmp;
	char			*tmp2;
	char			**str2;
}					t_var;

t_var				ft_var(void);
t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t				ft_strlen(const char *str);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_bzero(void *ptr, size_t i);
void				ft_memdel(void **ap);
void				ft_strdel(char **as);
void				ft_strclr(char *str);
void				ft_putchar(char c);
void				ft_putnchar(char c, int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putnbr(int n);
void				ft_putsnbr(long n);
void				ft_putunbr(t_ul n);
void				ft_putnbr_fd(int n, int fd);
void				ft_putstr(char const *str);
void				ft_putnstr(char const *str, int n);
void				ft_putstr_fd(char const *str, int fd);
void				ft_putendl(char const *str);
void				ft_putendl_fd(char const *str, int fd);
void				ft_striter(char *str, void (*f)(char *));
void				ft_striteri(char *str, void (*f)(unsigned int, char *));
void				*ft_memalloc(size_t size);
void				*ft_memchr(const void *src, int c, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memset(void *dst, int a, size_t len);
char				*ft_itoa(int n);
char				*ft_itoa_base(unsigned long n, char base, char size);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strdup(const char *str);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strmap(char const *str, char (*f)(char));
char				*ft_strmapi(char const *src, char (*f)(unsigned int, char));
char				*ft_strstr(const char *big, const char *little);
char				*ft_strnstr(const char *big, const char *littl, size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strnew(size_t size);
char				*ft_strrev(const char *str);
char				**ft_strsplit(char const *str, char c);
char				*ft_strtrim(char const *str);
char				*ft_wchar(unsigned w);
int					ft_atoi(const char *str);
long				ft_atoi_base(const char *str, char base);
int					ft_base_converter(char c);
int					ft_nbrlen(t_ul n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_isalpha(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isdigit(int c);
int					ft_isprint(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);

#endif
