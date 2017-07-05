/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 15:22:09 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/03/16 19:22:23 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list;

	if (!(list = (t_list*)malloc(sizeof(t_list))))
		return (0);
	content ? (list->content =
			ft_memcpy(ft_memalloc(content_size), content, content_size)) : 0;
	content ? (list->content_size = content_size) : 0;
	!content ? (list->content = 0) : 0;
	!content ? (list->content_size = 0) : 0;
	list->next = 0;
	return (list);
}
