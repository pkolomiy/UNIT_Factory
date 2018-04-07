/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 19:39:16 by dmulish           #+#    #+#             */
/*   Updated: 2018/03/29 20:31:41 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm_parser.h"

static int	check_error(char *error)
{
	if (error)
	{
		ft_printf("%s\n", error);
		ft_memdel((void**)&error);
		return (1);
	}
	return (0);
}

int			check_file_extens(char *file)
{
	int	len;

	len = (int)ft_strlen(file);
	if (len < 3 || (file[len - 2] != '.' && file[len - 1] != 's'))
	{
		ft_printf("Incorrect file name, must be 'your_file_name.s'\n");
		return (0);
	}
	return (1);
}

int			main(int argc, char **argv)
{
	int				num;
	char			*file;
	char			*error;
	unsigned char	*pars;

	num = 100;
	error = NULL;
	if (argc < 2)
	{
		ft_printf("Usage: ./asm <sourcefile.s>\n");
		return (-1);
	}
	if (!check_file_extens(argv[1]))
		return (-1);
	if (!(file = asm_reader(argv[1])))
	{
		ft_printf("Can't read source file %s\n", argv[1]);
		return (-1);
	}
	if (asm_validator(file, &error))
		pars = asm_parser(&error, &num, argv, NULL);
	if (!check_error(error))
		creat_file(argv[1], num, pars);
	ft_memdel((void**)&file);
	return (0);
}
