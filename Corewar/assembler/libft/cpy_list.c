/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 11:10:02 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/27 11:54:01 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*cpy_list_without_last(t_list *old)
{
	t_list	*tmp;
	t_list	*new;

	tmp = old->next;
	new = NULL;
	while (tmp)
	{
		if (new == NULL)
			new = ft_lstnew(tmp->content, tmp->content_size);
		else
			ft_lstadd(&new, ft_lstnew(tmp->content, tmp->content_size));
		tmp = tmp->next;
	}
	return (reverse_list(new));
}

t_list	*cpy_list(t_list *old)
{
	t_list	*tmp;
	t_list	*res;

	tmp = old;
	res = NULL;
	while (tmp)
	{
		if (res == NULL)
			res = ft_lstnew(tmp->content, tmp->content_size);
		else
			ft_lstadd(&res, ft_lstnew(tmp->content, tmp->content_size));
		tmp = tmp->next;
	}
	reverse_list(res);
	return (res);
}
