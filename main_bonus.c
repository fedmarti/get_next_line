#include "get_next_line_bonus.h"
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
		int i = 2;
		int initial_i;
		int fd[2] = {open(c[1], 'r'), open(c[2], 'r')};
		char *str;
		if (n > 3)
			i = atoi(c[3]);
		initial_i = i;
		while (i--)
		{
			str = get_next_line(fd[(i < initial_i / 2) ? 1 : 0]);
			change_color(i);
			printf("%s", str);
			free(str);
		}	
	}
}		
