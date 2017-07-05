/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/04 13:10:21 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/03/16 19:26:14 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_var	v;

	v.lst = *alst;
	while (v.lst)
	{
		v.lst2 = v.lst->next;
		del(v.lst->content, v.lst->content_size);
		free(v.lst);
		v.lst = v.lst2;
	}
	*alst = 0;
}
