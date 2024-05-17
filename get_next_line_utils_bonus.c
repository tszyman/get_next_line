/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:54:17 by tszymans          #+#    #+#             */
/*   Updated: 2024/04/29 19:49:51 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	char	*mem_res;

	mem_res = malloc(nmemb * size);
	if (!mem_res)
		return (NULL);
	ft_bzero(mem_res, nmemb * size);
	return (mem_res);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		*str = '\0';
		str++;
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	p = (char *)s;
	while ((char)c != *p)
	{
		if (!*p)
			return (0);
		p++;
	}
	return (p);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*new;
	int		i;
	int		j;

	size = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc((size + 1) * sizeof(char));
	if (!new || !s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i] != 0)
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != 0)
	{
		new[i] = s2[j];
		i++;
		j++;
	}
	new[size] = 0;
	return (new);
}

size_t	ft_strlen(const char *str)
{
	int	strlen;

	strlen = 0;
	if (*str == '\0')
		return (0);
	while (*str != '\0')
	{
		str += 1;
		strlen += 1;
	}
	return (strlen);
}
