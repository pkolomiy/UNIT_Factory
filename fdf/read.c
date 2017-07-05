/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 23:42:23 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/02/27 23:42:26 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "h.h"

char	*fd_to_str(int fd)
{
	char	*arr;
	char	*str;
	int		a;
	int		b;

	arr = (char*)malloc(100000001);
	b = read(fd, arr, 100000000);
	str = (char*)malloc(b + 1);
	a = 0;
	while (b)
	{
		str[a] = arr[a];
		a++;
		b--;
	}
	close(fd);
	free(arr);
	str[a] = '\0';
	return (str);
}

int		skip(t_v *v, int b)
{
	if (b)
	{
		v->a++;
		while ((v->str[v->a] >= 48 && v->str[v->a] <= 57) ||
			(v->str[v->a] >= 65 && v->str[v->a] <= 70) ||
			(v->str[v->a] >= 97 && v->str[v->a] <= 102) || v->str[v->a] == 120)
			v->a++;
	}
	else
	{
		if (!(v->str[v->a] >= 48 && v->str[v->a] <= 57) &&
			v->str[v->a] != 45 && v->str[v->a] && v->str[v->a] != 32)
		{
			write(1, "File invalid. Exiting.\n", 23);
			v->a = 0;
			return (1);
		}
	}
	return (0);
}

int		line_number(t_v *v)
{
	!v->c ? v->c = v->b : 0;
	if (v->b != v->c)
	{
		write(1, "Found wrong line length. Exiting.\n", 34);
		v->a = 0;
		return (1);
	}
	v->b = 0;
	v->a++;
	return (0);
}

void	begin(int fd, char *z)
{
	t_v		v;

	v.a = 0;
	v.b = 0;
	v.c = 0;
	v.name = z;
	v.str = fd_to_str(fd);
	while (v.str[v.a])
	{
		((v.str[v.a] >= 48 && v.str[v.a] <= 57) || v.str[v.a] == 45) ?
			v.b++ : 0;
		v.str[v.a] == 45 ? v.a++ : 0;
		while (v.str[v.a] >= 48 && v.str[v.a] <= 57)
			v.a++;
		v.str[v.a] == 44 ? skip(&v, 1) : 0;
		while (v.str[v.a] == 32)
			v.a++;
		if (v.str[v.a] == 10)
			if (line_number(&v))
				break ;
		if (skip(&v, 0))
			break ;
	}
	v.c == 1 ? write(1, "File has only one number.\n", 26) : 0;
	v.a && v.c != 1 ? save_map(v) : 0;
}

int		main(int x, char **z)
{
	int		fd;

	fd = open(z[1], O_RDONLY);
	if (fd < 0)
	{
		z[1] && x == 2 ? write(1, "No file ", 8) : 0;
		z[1] && x == 2 ? write(1, &(*z[1]), 1) : 0;
		if (z[1] && x == 2)
			while (*z[1]++)
				write(1, &(*z[1]), 1);
		z[1] && x == 2 ? write(1, "\n", 1) : 0;
		!z[1] || x > 2 ? write(1, "Usage : ./fdf <filename>\n", 25) : 0;
	}
	(x == 2 && fd >= 3) ? begin(fd, z[1]) : 0;
	close(fd);
	return (0);
}
