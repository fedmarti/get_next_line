#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

static void	change_color(int i)
{
	if (i % 4 == 0)
		printf("\033[1;31m");
	else if (i % 4 == 1)
		printf("\033[0;34m");
	else if (i % 4 == 2)
		printf("\033[1;33m");
	else
		printf("\033[1;32m");
}

int	main(int n, char **c)
{
	if (n >= 2)
	{
		int i = 1;
		int fd = open(c[1], 'r');
		char *str;
		if (n > 2)
			i = atoi(c[2]);
		while (i--)
		{
			str = get_next_line(fd);
			change_color(i);
			printf("%s", str);
			free(str);
		}	
	}
}		
