/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_args.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/12 18:30:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/03/12 18:30:34 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static _Bool	valid_unsigned_int(const char *str, unsigned int *result)
{
	unsigned char	i;
	unsigned		size;
	long			nbr;

	nbr = 0;
	i = 0;
	size = 0;
	if (!str)
		return (0);
	while (str[size])
		size++;
	if (size > 1 && str[0] == '0')
		return (0);
	while (size <= 10 && str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nbr = (nbr * 10) + (str[i] - 48);
		i++;
	}
	if (str[i] || nbr > 4294967295)
		return (0);
	*result = (unsigned int)nbr;
	return (1);
}

static char		*check_valid_player(t_reading *var, t_player **players)
{
	char		*error;
	t_player	*player;

	if (!(player = (t_player*)malloc(sizeof(t_player))))
		exit(malloc_error("check_valid_player : player"));
	if (!(player->file = vm_reader(var->argv[var->i], &error)))
		return (error);
	if (var->players_pos > MAX_PLAYERS)
		return ("Too many players\n");
	player->nbr = var->n_flag ? var->n_num : var->players_num;
	player->pos = var->players_pos;
	player->current_lives = 0;
	player->last_live = 0;
	player->next = *players;
	*players = player;
	var->players_pos++;
	if (!var->n_flag)
		var->players_num--;
	var->n_flag = 0;
	return (NULL);
}

static char		*more_validation(t_reading *var, t_player **players)
{
	if (cmp(var->argv[var->i], "-n"))
	{
		if (!(valid_unsigned_int(var->argv[++var->i], &var->n_num)))
			return ("Invalid number after \"-n\" flag.\n");
		var->n_flag = 1;
		++var->i;
	}
	return (check_valid_player(var, players));
}

static char		*arg_validation(t_reading *var, t_player **players,
																t_flags *flags)
{
	if (cmp(var->argv[var->i], "-l"))
	{
		if (flags->live)
			return ("Flag \"-l\" repeat\n");
		flags->live = 1;
	}
	else if (cmp(var->argv[var->i], "-v"))
	{
		if (flags->visual)
			return ("Flag \"-v\" repeat\n");
		flags->visual = 1;
	}
	else if (cmp(var->argv[var->i], "-dump"))
	{
		if (flags->dump)
			return ("Flag \"-dump\" repeat\n");
		flags->dump = 1;
		if (!(valid_unsigned_int(var->argv[++var->i], &flags->nbr)))
			return ("Invalid nbr_cycles number after \"-dump\" flag.\n");
	}
	else
		return (more_validation(var, players));
	return (NULL);
}

_Bool			vm_args(char **argv, t_player **players, t_flags *flags,
																char **error)
{
	t_reading	var;

	var.i = 1;
	var.players_num = 0xffffffff;
	var.players_pos = 1;
	var.argv = argv;
	var.n_flag = 0;
	flags->live = 0;
	flags->visual = 0;
	flags->dump = 0;
	flags->nbr = 0;
	while (argv[var.i])
	{
		if ((*error = arg_validation(&var, players, flags)))
			return (0);
		var.i++;
	}
	if (!*players)
	{
		*error = "No players\n";
		return (0);
	}
	return (1);
}
