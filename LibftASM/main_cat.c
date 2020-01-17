#include "libftasm.h"

int main()
{
	int fd = open("big.txt", O_RDONLY);
	if (fd < 0)
		return 0;
	ft_cat(fd);
	close(fd);
	return 0;
}
