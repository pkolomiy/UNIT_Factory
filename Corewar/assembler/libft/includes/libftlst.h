/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftlst.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:45:27 by dmulish           #+#    #+#             */
/*   Updated: 2018/02/17 18:17:33 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFTLST_H
# define _LIBFTLST_H

typedef struct		s_list
{
	struct s_list	*next;
	void			*content;
	size_t			content_size;
}					t_list;

void				print_list(t_list *lst);
void				print_rev_list(t_list *lst);
void				ft_lstadd(t_list **alst, t_list *new);
void				delete_tlist_node(void *data, size_t data_size);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));

t_list				*cpy_list(t_list *old);
t_list				*reverse_list(t_list *lst);
t_list				*cpy_list_without_last(t_list *old);
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
t_list				*ft_lstnew(void const *content, size_t content_size);

#endif
