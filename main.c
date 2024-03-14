#include <fcntl.h>
#include <stdio.h>

int main()
{
	int fd = open("./test", O_RDWR);
	printf("%d\n", fd);
}