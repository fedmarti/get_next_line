/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fedmarti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 15:12:58 by fedmarti          #+#    #+#             */
/*   Updated: 2022/11/14 15:13:02 by fedmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <limits.h>

static int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	if (str)
	{
		while (str[len])
			len++;
	}
	return (len);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;
	char	*temp;
	size_t	tot_size;

	if (!nmemb || !size)
		return (NULL);
	tot_size = size * nmemb;
	if (tot_size > (size_t) INT_MAX)
		return (NULL);
	array = malloc(tot_size);
	if (!array)
		return (NULL);
	temp = (char *) array;
	while (tot_size--)
		*temp++ = 0;
	return (array);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	char	*str;

	str = (char *)ft_calloc(ft_strlen(s1) + ft_strlen(s2) + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (*s1)
		{
			str[i] = *s1++;
			i++;
		}
	}
	if (s2)
	{
		while (*s2)
		{
			str[i] = *s2++;
			i++;
		}
	}
	return (str);
}

int	check(char *str)
{
	if (str)
	{
		while (*str && *str != '\n')
			str++;
		if (*str == '\n')
		{
			if (!str[1])
				return (0);
		}
	}
	return (1);
}

void	ft_reset(char **p)
{
	if (!*p)
		return ;
	free(*p);
	*p = NULL;
}
