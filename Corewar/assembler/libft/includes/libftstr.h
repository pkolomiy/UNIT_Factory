/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftstr.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:45:27 by dmulish           #+#    #+#             */
/*   Updated: 2018/02/22 19:27:34 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFTSTR_H
# define _LIBFTSTR_H
# define BUFF_SIZE 32

typedef struct		s_line
{
	struct s_line	*next;
	char			*buf;
	int				fd;
}					t_line;

int					get_next_line(const int fd, char **line);
int					ft_strequ(char const *s1, char const *s2);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
int					ft_strncmp(const char *s1, const char *s2, size_t n);

char				*ft_revstr(char *str);
char				*ft_strnew(size_t size);
char				*ft_strdup(const char *s1);
char				*ft_strtrim(char const *s);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strndup(const char *s1, int n);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strtrim_any(char const *s, char c);
char				*ft_skip_whitespace(char *line, int flag);
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
char				*ft_strstr(const char *big, const char *little);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char				*ft_strnstr(const char *big, const char *lit, size_t len);
char				*ft_strsub(char const *s, unsigned int start, size_t len);

char				**ft_strsplit(char const *s, char c);
char				**ft_split_whitespace(char const *s);

void				ft_strclr(char *s);
void				ft_free_arr(char **arr);
void				ft_strdel(char **as);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));

size_t				wordnum(char *s);
size_t				ft_wcharlen(wchar_t s);
size_t				ft_wstrlen(wchar_t *s);
size_t				ft_strlen(const char *s);
size_t				ft_wordnum(char *s, char c);
size_t				ft_charnum(char *str, char c);
size_t				ft_strlcat(char *dst, const char *src, size_t size);

#endif
