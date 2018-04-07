/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 11:27:13 by dmulish           #+#    #+#             */
/*   Updated: 2017/10/24 20:07:17 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*reverse_list(t_list *lst)
{
	t_list	*prev;
	t_list	*curr;
	t_list	*next;

	curr = lst;
	prev = NULL;
	while (curr)
	{
		next = prev;
		prev = curr;
		curr = curr->next;
		prev->next = next;
	}
	lst = prev;
	return (lst);
}
