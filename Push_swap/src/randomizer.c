/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomizer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkolomiy <pkolomiy@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 15:25:00 by pkolomiy          #+#    #+#             */
/*   Updated: 2018/01/07 20:47:52 by pkolomiy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include <stdlib.h>
#include <unistd.h>

static _Bool	valid_int(const char *str, int *result)
{
	_Bool			minus;
	unsigned char	i;
	unsigned		size;
	long			nbr;

	nbr = 0;
	i = 0;
	size = 0;
	while (str[size])
		size++;
	if ((minus = str[0] == '-'))
		i++;
	while (size <= 11 && str[i] && str[i] >= '0' && str[i] <= '9')
	{
		if (((!minus && !i && size != 1) || (minus && i == 1)) &&
		str[i] == '0')
			return (0);
		nbr = (nbr * 10) + (str[i] - 48);
		i++;
	}
	nbr = minus ? -nbr : nbr;
	if ((minus && size == 1) || str[i] || nbr < -1073741823 || nbr > 1073741823)
		return (0);
	*result = (int)nbr;
	return (1);
}

static void		nbr(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 11);
	else if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		nbr(n / 10);
	if (n >= 10)
		nbr(n % 10);
	if (n < 10 && n > -1)
	{
		n += 48;
		write(1, &n, 1);
	}
}

static int		random_nbr(const int *arr, int i, int first, int second)
{
	int	j;
	int	nbr;

	nbr = (first > second) ?
	first - (rand() % abs(first - second)) :
	second - (rand() % abs(first - second));
	j = 0;
	while (j < i)
	{
		if (arr[j] == nbr)
		{
			nbr = (first > second) ?
			first - (rand() % abs(first - second)) :
			second - (rand() % abs(first - second));
			j = 0;
		}
		else
			j++;
	}
	return (nbr);
}

static void		show_array(int amount, int first, int second)
{
	int	i;
	int	*arr;

	i = 0;
	arr = (int*)malloc(sizeof(int) * amount);
	srand((unsigned)time(NULL));
	while (i < amount)
	{
		arr[i] = random_nbr(arr, i, first, second);
		i++;
	}
	i = 0;
	while (i < amount)
	{
		nbr(arr[i]);
		i++;
		write(1, (i < amount) ? " " : "\n", 1);
	}
}

int				main(int argc, char **argv)
{
	int	amount;
	int	first;
	int	second;

	if (argc == 4)
	{
		if (valid_int(argv[1], &amount) && valid_int(argv[2], &first) &&
		valid_int(argv[3], &second) && amount > 1 &&
		abs(first - second) >= amount)
			show_array(amount, first, second);
		else
			write(2, "Error\n", 6);
	}
	else
		write(1, "usage:  ./randomizer [\e[31;1mnumber1\e[0m] "
		"[\e[32;1mnumber2\e[0m] [\e[34;1mnumber3\e[0m]\n\t"
		"[\e[31;1mnumber1\e[0m] >= \e[1m2\e[0m and [\e[31;1mnumber1\e[0m] "
		"<= \e[1mamount\e[0m between [\e[32;1mnumber2\e[0m] and "
		"[\e[34;1mnumber3\e[0m]\t\n\t[\e[32;1mnumber2\e[0m] or "
		"[\e[34;1mnumber3\e[0m] must be between \e[1m-1073741823\e[0m and "
		"\e[1m1073741823\e[0m\n", 323);
	return (0);
}
