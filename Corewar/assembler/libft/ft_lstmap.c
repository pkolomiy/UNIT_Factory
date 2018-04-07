/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/12 19:06:57 by dmulish           #+#    #+#             */
/*   Updated: 2016/12/15 19:30:32 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*tmp;
	t_list	*fresh;
	t_list	*fr_iter;

	if (!lst || !f)
		return (NULL);
	tmp = lst;
	fresh = f(tmp);
	if (fresh == NULL)
		return (NULL);
	fr_iter = fresh;
	while (tmp->next)
	{
		tmp = tmp->next;
		fr_iter->next = f(tmp);
		if (fr_iter->next == NULL)
			return (NULL);
		fr_iter = fr_iter->next;
	}
	return (fresh);
}
