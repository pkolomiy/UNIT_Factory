/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 19:44:30 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/03/16 19:42:57 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_var	v;

	if (!lst)
		return (0);
	v.lst = f(lst);
	v.lst2 = v.lst;
	v.lst3 = v.lst;
	while (lst->next)
	{
		lst = lst->next;
		v.lst = f(lst);
		v.lst3->next = v.lst;
		v.lst3 = v.lst;
	}
	return (v.lst2);
}
