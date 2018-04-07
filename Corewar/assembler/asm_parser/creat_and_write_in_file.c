/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_and_write_in_file.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <dchirkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/01 11:49:50 by dchirkin          #+#    #+#             */
/*   Updated: 2018/03/29 20:31:41 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parser.h"

void		creat_file(char *argv, int num, unsigned char *ret)
{
	int		new_fd;
	int		u;
	char	*z;
	int		l;

	l = -1;
	u = ft_strlen(argv);
	z = malloc(u + 3);
	z = ft_strncpy(z, argv, (u - 2));
	z[u - 2] = '.';
	z[u - 1] = 'c';
	z[u] = 'o';
	z[u + 1] = 'r';
	z[u + 2] = '\0';
	if ((new_fd = open(z, O_RDWR | O_CREAT | O_TRUNC, 0644)) == -1)
		return ;
	while (++l < COM_NAME + num)
		write(new_fd, &ret[l], 1);
	write(1, "Writing output program to ", 26);
	ft_putstr(z);
	write(1, "\n", 1);
	free(z);
	free(ret);
}
