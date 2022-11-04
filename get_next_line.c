/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 21:05:52 by fedmarti          #+#    #+#             */
/*   Updated: 2022/11/04 18:59:49 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*get_leftover(char *leftover, char *str, size_t len)
{
	size_t	lo_size;
	size_t	i;

	if (len < BUFFER_SIZE)
	{
		lo_size = BUFFER_SIZE - len;
		leftover = (char *)malloc((lo_size + 1) * sizeof(char));
		if (!leftover)
			return (NULL);
		i = 0;
		while (lo_size--)
		{
			leftover[i] = str[len + i];
			i++;
		}	
		leftover[i] = 0;
		str[len] = 0;
	}
	return (leftover);
}

static size_t	lo_len(char *lo, char *str)
{
	size_t	len;
	size_t	check;

	len = 0;
	check = 0;
	if (lo)
	{
		while(lo[len])
		{
			str[len] = lo[len];
			if (lo[len] == '\n')
				check = len;
			len++;
		}
	}
	free(lo);
	if (check)
		len = BUFFER_SIZE;
	return (len);
}

char	*get_next_line(int fd)
{
	static	char	*leftover;
	size_t	len;
	char	*str;

	str = (char *)malloc(BUFFER_SIZE + sizeof(char));
	if (!str)
		return (NULL);
	len = lo_len(leftover, str);
	if (len < BUFFER_SIZE)
		len = read(fd, &str[len], BUFFER_SIZE - len);
	if ((int)len < 0)
		return (NULL);
	len = 0;
	while (len < BUFFER_SIZE && str[len] != '\n')
		len++;
	len++;
	leftover = get_leftover(leftover, str, len);
	if (!leftover && str[len])
		return (NULL);
	return (str);
}


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

int	main()
{
	int n = 3;
	int i = 10;
	char c[] = "main.c";
	if (n >= 2)
	{
		int fd = open(c, 'r');
		char *str;
		while (i--)
		{
			str = get_next_line(fd);
			change_color(i);
			printf("%s", str);
			free(str);
		}	
	}
}		
