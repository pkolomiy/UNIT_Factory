/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bin.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 20:12:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/04/30 20:12:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_strarr	environ_from_env(t_env *env, size_t env_len)
{
	t_strarr	environ;
	size_t		i;

	i = 0;
	if (env_len == 0)
		return ((t_strarr){NULL, 0});
	environ.ptr = (char**)malloc(sizeof(char*) * (env_len + 1));
	environ.len = env_len;
	while (i < env_len)
	{
		environ.ptr[i] = join_with_char(env->key, env->val, '=');
		env = env->prev;
		i++;
	}
	environ.ptr[i] = NULL;
	return (environ);
}

static int		execute(char *command, t_sh *sh, t_stat buf)
{
	t_strarr	environ;
	pid_t		child;

	if (access(command, F_OK) == -1)
		return (NOT_FOUND);
	if (access(command, X_OK) == -1 || S_ISDIR(buf.st_mode))
		return (PERMISSION_DENIED);
	environ = environ_from_env(sh->env_end, sh->env_len);
	if ((child = fork()) == -1)
	{
		error_msg("fork error\n", NULL, NULL, NULL);
		exit(1);
	}
	signal(SIGINT, ft_signal2);
	if (child == 0 && execve(command, sh->arg.ptr, environ.ptr) == -1)
	{
		error_msg("can not execute: ", command, "\n", NULL);
		exit(1);
	}
	else
		waitpid(child, NULL, 0);
	free_strarr(&environ);
	return (ALL_OK);
}

static int		search_in_path(t_sh *sh, int exec, t_stat buf)
{
	char		*path;
	t_strarr	paths;
	size_t		i;

	i = 0;
	paths = ft_strsplit(get_from_env(sh->env, "PATH"), ':');
	while (i < paths.len)
	{
		path = join_with_char(paths.ptr[i], sh->arg.ptr[0], '/');
		lstat(path, &buf);
		exec = execute(path, sh, buf);
		ft_memdel((void **)&path);
		if (exec == ALL_OK)
			break ;
		i++;
	}
	free_strarr(&paths);
	return (exec);
}

void			ft_bin(t_sh *sh)
{
	int		exec;
	_Bool	dont_search;
	t_stat	buf;

	dont_search = 0;
	if (sh->arg.ptr[0][0] == '.' || sh->arg.ptr[0][0] == '/')
		dont_search = 1;
	lstat(sh->arg.ptr[0], &buf);
	exec = execute(sh->arg.ptr[0], sh, buf);
	if (exec == NOT_FOUND && dont_search == 0)
		exec = search_in_path(sh, exec, buf);
	if (exec == PERMISSION_DENIED)
		error_msg("permission denied: ", sh->arg.ptr[0], "\n", NULL);
	else if (exec == NOT_FOUND)
		error_msg(dont_search ? "no such file or directory: " :
				"command not found: ", sh->arg.ptr[0], "\n", NULL);
}
