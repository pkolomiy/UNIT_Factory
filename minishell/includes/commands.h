/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 17:45:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/04/30 17:45:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMMANDS_H
# define COMMANDS_H
# include "minishell.h"

typedef struct s_command	t_command;

struct		s_command
{
	char			*name;
	unsigned int	min_args;
	unsigned int	max_args;
	void			(*execute)(t_sh *sh);
	char			*usage;
};

void		ft_env(t_sh *sh);
void		ft_setenv(t_sh *sh);
void		ft_unsetenv(t_sh *sh);
void		ft_echo(t_sh *sh);
void		ft_cd(t_sh *sh);
void		ft_exit(t_sh *sh);
void		ft_bin(t_sh *sh);

#endif
