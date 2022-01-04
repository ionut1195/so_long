# include <fcntl.h>
#include <stdio.h>
#include "libft.h"

int main(void)//int argc, char *argv[])
{
	int fd;
	char **ptr;
	int itr;
	//printf("%d\n%s\n", argc, argv[1]);
	//fd = open(argv[1],O_RDONLY);
	fd = open("./1.ber",O_RDONLY);
	itr = 0;
	printf("\nfd ==  %d\n",fd);
	while (ft_gnl(fd, &ptr[itr]))
	{
		printf("%s",ptr[itr]);
		itr++;
	}
	printf("%s",ptr[itr]);
}