/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 14:37:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2019/12/12 14:37:00 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	*su1;
	unsigned char	*su2;

	if (!s1 || !s2)
		return (0);
	su1 = (unsigned char*)s1;
	su2 = (unsigned char*)s2;
	while (*su1 == *su2 && (*su1 || *su2))
	{
		su1++;
		su2++;
	}
	return (*su1 - *su2);
}
