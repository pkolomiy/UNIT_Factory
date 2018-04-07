/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 16:10:38 by dmulish           #+#    #+#             */
/*   Updated: 2018/03/29 20:31:41 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
**	flag == 'l' - lexical error
**	flag == 'i' - invalid instruction
**	flag == 'p' - invalid parameter
**	flag == 'n' - invalid num of params
**	flag == 'm' - no mandatory parts (name/comment)
**	flag == 'h' - incorrect champ's name
**	flag == 'b' - no instructions
**	flag == 's' - invalid label
*/

char	*name_comment_error(int a, char *str)
{
	char	*num;
	char	*tmp;
	char	*error;

	num = ft_itoa(a + 1);
	tmp = ft_strjoin(str, " occurs second time at line ");
	error = ft_strjoin(tmp, num);
	ft_memdel((void**)&num);
	ft_memdel((void**)&tmp);
	return (error);
}

char	*error_message(int a, int flag)
{
	char	*tmp;
	char	*error;

	error = NULL;
	tmp = ft_itoa(a + 1);
	if (flag == 'l')
		error = ft_strjoin("Lexical error at str ", tmp);
	else if (flag == 'i')
		error = ft_strjoin("Invalid instruction at line ", tmp);
	else if (flag == 'p')
		error = ft_strjoin("Invalid parameter at line ", tmp);
	else if (flag == 'n')
		error = ft_strjoin("Invalid number of parameters at line ", tmp);
	else if (flag == 'm')
		error = ft_strdup("Please, specify .name and .comment at \
first two lines (except #comments)");
	else if (flag == 'h')
		error = ft_strjoin("Please, check .instruction at line ", tmp);
	else if (flag == 'b')
		error = ft_strdup("There are no instructions to be found!");
	else if (flag == 's')
		error = ft_strjoin("Invalid label at line ", tmp);
	ft_memdel((void**)&tmp);
	return (error);
}
