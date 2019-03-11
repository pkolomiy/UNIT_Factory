/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_flag.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 21:07:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/03/10 21:07:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_permissions(char type, mode_t st_mode)
{
	t_file_mode	fm;
	t_rwx		rwx_owner;
	t_rwx		rwx_group;
	t_rwx		rwx_other;

	fm.st_mode = st_mode;
	rwx_owner.all = fm.file.owner;
	rwx_group.all = fm.file.group;
	rwx_other.all = fm.file.other;
	ft_printf("%c%c%c%c%c%c%c%c%c%c",
			type,
			"-r"[rwx_owner.bit.r], "-w"[rwx_owner.bit.w],
			(fm.file.mode_owner ? "Ss" : "-x")[rwx_owner.bit.x],
			"-r"[rwx_group.bit.r], "-w"[rwx_group.bit.w],
			(fm.file.mode_group ? "Ss" : "-x")[rwx_group.bit.x],
			"-r"[rwx_other.bit.r], "-w"[rwx_other.bit.w],
			(fm.file.mode_other ? "Tt" : "-x")[rwx_other.bit.x]);
}

char	*get_date(time_t tv_sec)
{
	time_t	now;
	char	*date;

	now = time(NULL);
	date = ctime(&tv_sec);
	date += 4;
	if (now - HALF_YEAR > tv_sec || now + HALF_YEAR < tv_sec)
		ft_memcpy(date + 7, date + 15, 5);
	date[12] = '\0';
	return (date);
}
