/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 14:09:34 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/05/21 16:57:46 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

int		lst_free(t_lst **lst)
{
	t_lst *lst1;
	t_lst *lst2;

	lst1 = *lst;
	while (lst1)
	{
		lst2 = lst1->next;
		free(lst1);
		lst1 = lst2;
	}
	*lst = 0;
	return (0);
}

int		map(t_alum *var, t_lst **lst)
{
	t_lst *lst1;

	lst1 = *lst;
	while (lst1)
	{
		if (!lst1->i || lst1->i > 10000)
			return (lst_free(lst));
		lst1 = lst1->next;
		var->len++;
	}
	var->board = (int*)malloc(sizeof(int) * var->len);
	lst1 = *lst;
	while (lst1)
	{
		var->board[var->index] = lst1->i;
		lst1 = lst1->next;
		var->index++;
	}
	lst_free(lst);
	return (1);
}

int		main(int argc, char **argv)
{
	t_alum	var;

	var.len = 0;
	var.index = 0;
	if ((argc == 2 && new_map(open(argv[1], O_RDONLY), &var)) ||
		(argc == 1 && new_map(1, &var)))
		game(&var);
	else
		write(1, "\e[1;31mERROR\e[0m\n", 17);
	return (0);
}
