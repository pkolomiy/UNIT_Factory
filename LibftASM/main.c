#include "libftasm.h"

void ft_bzero_test()
{
	int flag = 0;
	int sizes[3] = {10, 1234567, 0};
	for (int j = 0; j < 3; j++)
	{
		char *ptr = malloc(sizes[j]);
		size_t i;
		for (i = 0; i < sizes[j]; i++)
			ptr[i] = 1;
		ft_bzero(ptr, sizes[j]);
		for (i = 0; i < sizes[j]; i++)
			if (ptr[i] != 0 && flag == 0)
				flag = 1;
		free(ptr);
	}
	printf("\e[37;1m%s\e[0m ", __func__);
	printf("%s\n", flag == 0 ? OK : KO);
}

void ft_strlen_test()
{
	printf("\e[37;1m%s\e[0m ", __func__);
	printf("%s\n",
	ft_strlen("12345") == 5 &&
	ft_strlen("") == 0 &&
	ft_strlen(" ") == 1 &&
	ft_strlen("1234567890123456789012345678901234567890") == 40
	 ? OK : KO);
}

void ft_memcpy_test()
{
	char test1[10] = "123456789";
	char test2[10] = "123456789";
	char test3[10] = "123456789";
	char *res1 = ft_memcpy(test1, test1 + 3, 4);
	char *res2 = ft_memcpy(test2 + 3, test2, 4);
	char *res3 = ft_memcpy(test3, test3, 0);
	printf("\e[37;1m%s\e[0m ", __func__);
	printf("%s\n",
	!strcmp(res1, "456756789") &&
	!strcmp(res2 - 3, "123123489") &&
	!strcmp(res3, "123456789")
	? OK : KO);
}

void ft_strdup_test()
{
	char *ptr1 = ft_strdup("1234567");
	char *ptr2 = ft_strdup("");
	char *ptr3 = ft_strdup("1");
	ptr1[3] = 'a';
	printf("\e[37;1m%s\e[0m ", __func__);
	printf("%s\n",
	!strcmp(ptr1, "123a567") &&
	!strcmp(ptr2, "") &&
	!strcmp(ptr3, "1")
	 ? OK : KO);
	free(ptr1);
	free(ptr2);
	free(ptr3);
}

void ft_memset_test()
{
	char s1[10] = "   222   ";
	char s2[10] = "   aaa   ";
	char s3[10] = "    c    ";
	char *r1 = ft_memset(s1, '1', 3);
	r1 = ft_memset(r1 + 6, '3', 2);
	ft_memset(s2, 'b', 0);
	ft_memset(s3 + 1, 'a', 1);
	ft_memset(s3 + 7, 'a', 1);
	printf("\e[37;1m%s\e[0m ", __func__);
	printf("%s\n",
	 !strcmp(s1, "11122233 ") &&
	 !strcmp(r1 - 6, "11122233 ") &&
	 !strcmp(s2, "   aaa   ") &&
	 !strcmp(s3, " a  c  a ")
	 ? OK : KO);
}

void ft_strcat_test()
{
	char s1[20] = "12345 abcdefghij   ";
	s1[5] = '\0';
	char *s2 = "67890123";
	char *r1 = ft_strcat(s1, s2);
	printf("\e[37;1m%s\e[0m ", __func__);
	printf("%s\n",
	 !strcmp(s1, "1234567890123") &&
	 !strcmp(r1, "1234567890123")
	 ? OK : KO);
}

void ft_isalpha_test()
{
	printf("\e[37;1m%s\e[0m ", __func__);
	int flag = 1;
	for (int i = 0; i < 255; i++)
	{
		if ((i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z'))
			flag = ft_isalpha(i);
		else if (ft_isalpha(i))
			flag = 0;
		if (!flag)
			break ;
	}
	printf("%s\n", flag ? OK : KO);
}

void ft_isdigit_test()
{
	printf("\e[37;1m%s\e[0m ", __func__);
	int flag = 1;
	for (int i = 0; i < 255; i++)
	{
		if (i >= '0' && i <= '9')
			flag = ft_isdigit(i);
		else if (ft_isdigit(i))
			flag = 0;
		if (!flag)
			break ;
	}
	printf("%s\n", flag ? OK : KO);
}

void ft_isalnum_test()
{
	printf("\e[37;1m%s\e[0m ", __func__);
	int flag = 1;
	for (int i = 0; i < 255; i++)
	{
		if ((i >= '0' && i <= '9') || (i >= 'A' && i <= 'Z') || (i >= 'a' && i <= 'z'))
			flag = ft_isalnum(i);
		else if (ft_isalnum(i))
			flag = 0;
		if (!flag)
			break ;
	}
	printf("%s\n", flag ? OK : KO);
}

void ft_isprint_test()
{
	printf("\e[37;1m%s\e[0m ", __func__);
	int flag = 1;
	for (int i = 0; i < 255; i++)
	{
		if (i >= ' ' && i <= '~')
			flag = ft_isprint(i);
		else if (ft_isprint(i))
			flag = 0;
		if (!flag)
			break ;
	}
	printf("%s\n", flag ? OK : KO);
}

void ft_isascii_test()
{
	printf("\e[37;1m%s\e[0m ", __func__);
	int flag = 1;
	for (int i = -127; i < 255; i++)
	{
		if (i >= 0 && i <= 127)
			flag = ft_isascii(i);
		else if (ft_isascii(i))
			flag = 0;
		if (!flag)
			break ;
	}
	printf("%s\n", flag ? OK : KO);
}

void ft_tolower_test()
{
	printf("\e[37;1m%s\e[0m ", __func__);
	int flag = 1;
	for (int i = 0; i < 255; i++)
	{
		if (i >= 'A' && i <= 'Z')
			flag = (ft_tolower(i) - 32 == i);
		else if (ft_tolower(i) != i)
			flag = 0;
		if (!flag)
			break ;
	}
	printf("%s\n", flag ? OK : KO);
}

void ft_toupper_test()
{
	printf("\e[37;1m%s\e[0m ", __func__);
	int flag = 1;
	for (int i = 0; i < 255; i++)
	{
		if (i >= 'a' && i <= 'z')
			flag = (ft_toupper(i) + 32 == i);
		else if (ft_toupper(i) != i)
			flag = 0;
		if (!flag)
			break ;
	}
	printf("%s\n", flag ? OK : KO);
}

void ft_memalloc_test()
{
	char *str = ft_memalloc(100);
	printf("\e[37;1m%s\e[0m ", __func__);
	printf("%s\n", str[0] == 0 && str[50] == 0 && str[99] == 0 ? OK : KO);
	free(str);
}

void ft_strcmp_test()
{
	printf("\e[37;1m%s\e[0m ", __func__);
	char *s1 = "12345";
	char *s2 = "123456789";
	char *s3 = "12345";
	printf("%s\n",
	strcmp(s1, s2) == ft_strcmp(s1, s2) &&
	strcmp(s2, s1) == ft_strcmp(s2, s1) &&
	strcmp(s1, s3) == ft_strcmp(s1, s3)
	? OK : KO);
}

void ft_strjoin_test()
{
	printf("\e[37;1m%s\e[0m ", __func__);
	char *s1 = "12345";
	char *s2 = "6789";
	char *s3 = ft_strjoin(s1, s2);
	printf("%s\n",
	!strcmp("123456789", s3) && s3[9] == 0
	? OK : KO);
	free(s3);
}

int main()
{
	ft_bzero_test();
	ft_memcpy_test();
	ft_memset_test();
	ft_strlen_test();
	ft_strdup_test();
	ft_strcat_test();
	ft_isalpha_test();
	ft_isdigit_test();
	ft_isalnum_test();
	ft_isprint_test();
	ft_isascii_test();
	ft_tolower_test();
	ft_toupper_test();
	ft_strjoin_test();
	ft_memalloc_test();
	ft_strcmp_test();
	return 0;
}
