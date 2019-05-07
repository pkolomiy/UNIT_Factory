/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 18:29:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/04/30 18:29:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	change_dir(t_sh *sh, char *dir)
{
	char	*cur_dir;

	if (access(dir, F_OK) == -1)
		error_msg("cd: no such file or directory: ", dir, "\n", NULL);
	else if (access(dir, X_OK) == -1)
		error_msg("cd: permission denied: ", dir, "\n", NULL);
	else
	{
		cur_dir = (char*)malloc(GETCWD_BUF);
		if (getcwd(cur_dir, GETCWD_BUF) == NULL || chdir(dir) == -1)
		{
			free(cur_dir);
			error_msg("cd: can not change dir to: ", dir, "\n", NULL);
		}
		if (set_to_env(sh, "OLDPWD", cur_dir) == 0)
			set_new_env(sh, ft_strdup("OLDPWD"), cur_dir);
		cur_dir = (char*)malloc(GETCWD_BUF);
		if (getcwd(cur_dir, GETCWD_BUF) == NULL)
		{
			free(cur_dir);
			error_msg("cd: can not set PWD\n", NULL, NULL, NULL);
		}
		else if (set_to_env(sh, "PWD", cur_dir) == 0)
			set_new_env(sh, ft_strdup("PWD"), cur_dir);
	}
}

void		ft_cd(t_sh *sh)
{
	char	*temp;

	temp = NULL;
	if (sh->arg.len == 1)
	{
		if ((temp = get_from_env(sh->env, "HOME")) == NULL)
			error_msg("cd: HOME not set\n", NULL, NULL, NULL);
		else
			change_dir(sh, temp);
	}
	else if (sh->arg.ptr[1][0] != '\0')
	{
		if (str_equal(sh->arg.ptr[1], "-") &&
			(temp = get_from_env(sh->env, "OLDPWD")) == NULL)
			error_msg("cd: OLDPWD not set\n", NULL, NULL, NULL);
		else
			change_dir(sh, temp ? temp : sh->arg.ptr[1]);
	}
}
