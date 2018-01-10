/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:19:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/01/07 23:27:29 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static inline _Bool	swap(int *arr, int i, int len)
{
	int		j;

	j = i;
	while (++j < len)
	{
		if (arr[i] > arr[j])
		{
			arr[i] ^= arr[j];
			arr[j] ^= arr[i];
			arr[i] ^= arr[j];
		}
		if (arr[i] == arr[j])
			return (1);
	}
	return (0);
}

static void			check_repetitions(t_stack *a, int len)
{
	int		i;
	int		*arr;

	arr = (int*)malloc(sizeof(int) * len);
	i = -1;
	while (++i < len)
	{
		arr[i] = a->nbr;
		a = a->next;
	}
	i = -1;
	while (++i < len)
	{
		if (swap(arr, i, len))
		{
			free(arr);
			write(2, "Error\n", 6);
			exit(1);
		}
	}
	free(arr);
}

static _Bool		valid_int(const char *str, int *result)
{
	_Bool			minus;
	unsigned char	i;
	unsigned		size;
	long			nbr;

	nbr = 0;
	i = 0;
	size = 0;
	while (str[size])
		size++;
	if ((minus = str[0] == '-'))
		i++;
	while (size <= 11 && str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (((!minus && !i && size != 1) || (minus && i == 1)) &&
		str[i] == '0')
			return (0);
		nbr = (nbr * 10) + (str[i] - 48);
		i++;
	}
	nbr = minus ? -nbr : nbr;
	if ((minus && size == 1) || str[i] || nbr < -2147483648 || nbr > 2147483647)
		return (0);
	*result = (int)nbr;
	return (1);
}

static void			add_to_a(t_main *m, int nbr)
{
	t_stack	*cur;
	t_stack	*prev;

	cur = m->a;
	prev = NULL;
	while (cur)
	{
		prev = cur;
		cur = cur->next;
	}
	cur = (t_stack*)malloc(sizeof(t_stack));
	cur->nbr = nbr;
	cur->next = NULL;
	if (!prev)
		m->a = cur;
	else
		prev->next = cur;
}

void				validate_arguments(char **argv, t_main *m)
{
	unsigned	i;
	int			result;

	i = 1;
	while (argv[i])
	{
		if (valid_int(argv[i], &result))
		{
			add_to_a(m, result);
			m->a_len++;
		}
		else
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
	check_repetitions(m->a, m->a_len);
}
