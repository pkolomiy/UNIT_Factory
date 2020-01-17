#include "libftasm.h"

void ft_puts_test()
{
	ft_puts("");
	ft_puts(NULL);
	ft_puts("test string");
}

void ft_putchar_test()
{
	char *str = "putchar test\n";
	for (int i = 0; str[i]; i++)
		ft_putchar(str[i]);
}

void ft_putnbr_test()
{
	ft_putnbr(-2147483648);
	ft_putnbr(-1);
	ft_putnbr(0);
	ft_putnbr(1);
	ft_putnbr(100);
	ft_putnbr(-45);
	ft_putnbr(2147483647);
}

int main()
{
	ft_putchar_test();
	ft_putnbr_test();
	ft_puts_test();
	return 0;
}
