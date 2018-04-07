/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_modif.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmulish <dmulish@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 18:04:11 by dmulish           #+#    #+#             */
/*   Updated: 2018/02/27 18:43:23 by dmulish          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	init_mod(t_mod *mod)
{
	mod->prec = 0;
	mod->size = 0;
	mod->type = 0;
	mod->width = 0;
	mod->flags = (char*)ft_memalloc(5);
	mod->modifs = ft_strdup("-+ #.0123456789hljz");
}

void	fill_struct_size(char *tmp, t_mod *mod)
{
	if (ft_strchr(tmp, 'h'))
		mod->size = (*(ft_strchr(tmp, 'h') + 1) == 'h') ? 'H' : 'h';
	if (ft_strchr(tmp, 'l'))
		mod->size = (*(ft_strchr(tmp, 'l') + 1) == 'l') ? 'L' : 'l';
	(ft_strchr(tmp, 'z')) ? mod->size = 'z' : 0;
	(ft_strchr(tmp, 'j')) ? mod->size = 'j' : 0;
}

void	fill_struct_digits(char *tmp, t_mod *mod)
{
	int	i;

	i = -1;
	while (tmp[++i])
	{
		if (!mod->width && ft_isdigit(tmp[i]) && (i == 0 || tmp[i - 1] != '.'))
			mod->width = ft_atoi(tmp + i);
		while (ft_isdigit(tmp[i]))
			i++;
		if (!mod->prec && tmp[i] == '.')
		{
			i++;
			mod->prec = ft_atoi(tmp + i);
		}
		while (ft_isdigit(tmp[i]))
			i++;
	}
}

void	fill_struct(char *tmp, t_mod *mod)
{
	int	i;

	i = 0;
	if (ft_strchr(tmp, '#'))
		mod->flags[i++] = '#';
	if (ft_strchr(tmp, '+'))
		mod->flags[i++] = '+';
	else if (ft_strchr(tmp, ' '))
		mod->flags[i++] = ' ';
	if (ft_strchr(tmp, '-'))
		mod->flags[i++] = '-';
	else if (ft_strchr(tmp, '0') && (tmp[0] == 0 ||
			!ft_isdigit(*(ft_strchr(tmp, '0') - 1))))
		mod->flags[i++] = '0';
	if (ft_strchr(tmp, '.'))
		mod->flags[i++] = '.';
	fill_struct_digits(tmp, mod);
	fill_struct_size(tmp, mod);
}

void	handle_modif(char *str, int *i, t_s *s)
{
	int		j;
	char	*tmp;
	t_mod	mod;

	j = 0;
	init_mod(&mod);
	while (ft_strchr(mod.modifs, str[*i + j]))
		j++;
	mod.type = str[*i + j];
	if ((mod.type == 's' || mod.type == 'c') && (str[*i + j - 1] == 'l'))
		mod.type = (mod.type == 's') ? 'S' : 'C';
	tmp = ft_strsub(str, (unsigned int)*i, j);
	fill_struct(tmp, &mod);
	print_flags(&mod, s);
	(*i) += j + 1;
	free(tmp);
	free(mod.flags);
	free(mod.modifs);
}
