/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/28 22:14:20 by pkolomiy          #+#    #+#             */
/*   Updated: 2017/10/04 23:14:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

static inline void	usage(void)
{
	char	*str;

	VAR_INT(len, 0);
	str = "\e[37;1mUsage: \e[0m\e[36;1m./wolf3d <map_file>\e[0m\n\n\e[32;1m"
	"Map example:\e[0m\n\e[43;30m1   1   1   1   1   1   1   1   1   1\e[0m\n\e"
	"[43;30m1\e[0m\e[46;30m   0   0   0   0   0   0   0   0   \e[0m\e[43;30m1\e"
	"[0m\n\e[43;30m1\e[0m\e[46;30m   0   \e[0m\e[45;32;1ms\e[0m\e[46;30m   0   "
	"\e[0m\e[0m\e[44;37;1mp\e[0m\e[46;30m   0   0   \e[0m\e[45;32;1mc\e[0m\e[46"
	";30m   0   \e[0m\e[43;30m1\e[0m\n\e[41;30m2\e[0m\e[46;30m   0   0   \e[0m"
	"\e[45;32;1md\e[0m\e[46;30m   0   0   0   0   0   \e[0m\e[41;30m2\e[0m\n\e"
	"[41;30m2\e[0m\e[46m  \e[0m\e[45;32;1mb,l\e[0m\e[46;30m  0   0   0   0  \e"
	"[0m\e[45;32;1md,l\e[0m\e[46m \e[0m\e[43;30m 1   1   1\e[0m\n\e[41;30m2   2"
	"   2   2\e[0m\e[46;30m   0   \e[0m\e[41;30m2   2  \e[0m\e[46;30m 0   0   "
	"\e[0m\e[43;30m1\e[0m\n\e[41;30m2\e[0m\e[46m   \e[0m\e[45;32;1mf\e[0m\e[46;"
	"30m   0   0   0   0   0   0   0   \e[0m\e[43;30m1\e[0m\n\e[41;30m2   2   2"
	"   2   2   2   2   2   2   2\e[0m\n\n\e[37;1mWhere:\e[0m\n\e[46;30m 0 \e[0"
	"m - free space.\n\e[43;30m 1 \e[0m - wood wall.\n\e[41;30m 2 \e[0m - brick"
	" wall.\n\e[45;32;1m b \e[0m - barrel.\n\e[45;32;1m c \e[0m - cat.\n\e[45;"
	"32;1m d \e[0m - dog.\n\e[45;32;1m f \e[0m - florin.\n\e[45;32;1m l \e[0m -"
	" lamp.\n\e[45;32;1m s \e[0m - sprite.\n\e[44;37;1m p \e[0m - player.\n";
	while (str[len])
		len++;
	write(1, str, len);
	exit(1);
}

int					main(int argc, char **argv)
{
	if (argc != 2)
		usage();
	else
		read_file(argv[1]);
	return (0);
}
