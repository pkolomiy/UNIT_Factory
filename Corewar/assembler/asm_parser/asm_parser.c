/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dchirkin <dchirkin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 12:48:42 by dchirkin          #+#    #+#             */
/*   Updated: 2018/03/29 21:24:14 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parser.h"

t_file				*creat_firse_ret_norm(t_file *cop, unsigned char *ret,
																	int *f)
{
	if (ret[1] == 0xea)
	{
		while (ft_strstr(cop->line, COMMENT_CMD_STRING) == NULL
										|| the_comm(cop->line, 0) == 1)
			cop = cop->next;
		cop = ft_search_comment(cop, ret);
	}
	else
	{
		while (ft_strstr(cop->line, NAME_CMD_STRING) == NULL ||
										the_comm(cop->line, 0) == 1)
			cop = cop->next;
		cop = name_comment(cop, ret, *f);
	}
	return (cop);
}

t_file				*creat_firse_ret(t_file *cop, unsigned char *ret)
{
	int				f;

	ft_memset(ret, '\0', COM_NAME);
	while ((ft_strstr(cop->line, NAME_CMD_STRING) == NULL
			&& ft_strstr(cop->line, COMMENT_CMD_STRING) == NULL) ||
							the_comm(cop->line, 0) == 1)
		cop = cop->next;
	f = 0;
	if (ft_strstr(cop->line, COMMENT_CMD_STRING) != NULL)
		cop = ft_search_comment(cop, ret);
	else
		cop = name_comment(cop, ret, f);
	cop = cop->next;
	while (ft_strstr(cop->line, NAME_CMD_STRING) == NULL &&
		ft_strstr(cop->line, COMMENT_CMD_STRING) == NULL)
		cop = cop->next;
	cop = creat_firse_ret_norm(cop, ret, &f);
	cop = cop->next;
	while (ft_cheak_label(cop->line) == 0 && cop)
		cop = cop->next;
	return (cop);
}

unsigned char		*ft_error(char **error, t_block *b1,
											unsigned char *ret, t_file *file)
{
	*error = malloc(65);
	ft_write(*error, "Invalid parameter ", "type indirect for instruction ");
	ft_free(file, b1);
	free(ret);
	return (NULL);
}

unsigned char		*ft_error_2(char **error, t_block *b1,
								unsigned char *ret_end, t_file *file)
{
	*error = malloc(100);
	ft_write_lable_error(*error);
	ft_free(file, b1);
	free(ret_end);
	return (NULL);
}

unsigned char		*asm_parser(char **error, int *size,
											char **argv, t_file *file)
{
	t_file			*cop;
	t_block			*b1;
	t_block			*b2;
	unsigned char	*ret;
	unsigned char	*ret_end;

	file = reader(argv[1], 0);
	b2 = NULL;
	cop = file;
	ret = malloc(COM_NAME);
	cop = creat_firse_ret(cop, ret);
	if ((b1 = first_block(cop, b2, 0, 0)) == NULL)
		return (ft_error(error, b1, ret, file));
	while (ft_cheak_label(cop->line) == 0 && cop)
		cop = cop->next;
	b2 = b1;
	if (cre_struct_data_labels_proc(cop, b2, 0, 0) == -1)
		return (ft_error(error, b1, ret, file));
	*size = ft_la_size(b1);
	ret_end = create_line(ret, size);
	if (bit_write_to_string(b1, ret_end, 0) < 0)
		return (ft_error_2(error, b1, ret_end, file));
	ft_free(file, b1);
	return (ret_end);
}
