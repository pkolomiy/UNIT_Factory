/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/20 17:58:08 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/05/21 16:57:22 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "alum1.h"

t_lst	*std2(char *str, t_lst *lst, t_lst *lst1)
{
	lst->i = 0;
	while (str[0] != 10)
		read(0, str, 1);
	return (lst1);
}

t_lst	*std(char *str, t_lst *lst, t_lst *lst1)
{
	read(0, str, 1);
	if (str[0] == 48)
		return (std2(str, lst, lst1));
	while (1)
	{
		if (str[0] == 10)
		{
			read(0, str, 1);
			if (str[0] == 10 || str[0] == 48)
				return (str[0] == 10 ? lst1 : std2(str, lst, lst1));
			lst->next = (t_lst*)malloc(sizeof(t_lst));
			lst = lst->next;
			lst->i = 0;
			lst->next = 0;
		}
		(str[0] >= 48 && str[0] <= 57) ?
			(lst->i = (lst->i * 10) + str[0] - 48) : 0;
		(str[0] >= 48 && str[0] <= 57) ? read(0, str, 1) : 0;
		if (!(str[0] >= 48 && str[0] <= 57) && str[0] != 10)
			return (std2(str, lst, lst1));
	}
	return (lst1);
}

t_lst	*file2(t_lst *lst, t_lst *lst1, char *str, int i)
{
	while (str[++i] && ((str[i] >= 48 && str[i] <= 57) || str[i] == 10))
	{
		if (str[i] == 10 && str[i + 1])
		{
			lst->next = (t_lst*)malloc(sizeof(t_lst));
			lst = lst->next;
			lst->i = 0;
			lst->next = 0;
		}
		if (str[i] >= 48 && str[i] <= 57)
			lst->i = (lst->i * 10) + str[i] - 48;
	}
	lst->i = !str[i] ? lst->i : 0;
	free(str);
	return (lst1);
}

t_lst	*file(t_lst *lst, char *str, char *str1)
{
	t_lst	*lst1;
	int		i;
	int		j;

	i = 0;
	j = -1;
	lst1 = lst;
	str1 = (char*)malloc(1000001);
	i = read(3, str1, 1000000) + 1;
	str = (char*)malloc(i);
	while (++j >= 0 && --i)
		str[j] = str1[j];
	str[j] = 0;
	free(str1);
	return (file2(lst, lst1, str, -1));
}

int		new_map(int fd, t_alum *var)
{
	t_lst	*lst;
	t_lst	*lst1;
	char	str[2];
	char	*str1;
	char	*str2;

	str[0] = 0;
	str[1] = 0;
	str1 = 0;
	str2 = 0;
	if (fd == -1)
		return (0);
	lst = (t_lst*)malloc(sizeof(t_lst));
	lst->i = 0;
	lst->next = 0;
	lst1 = lst;
	lst = fd == 1 ? std(str, lst, lst1) : file(lst, str1, str2);
	if (fd >= 3)
		close(fd);
	return (map(var, &lst));
}
