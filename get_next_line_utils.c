/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tszymans <tszymans@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:54:17 by tszymans          #+#    #+#             */
/*   Updated: 2024/04/10 19:04:09 by tszymans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	size_t	s1_len;
	size_t	s2_len;
	char	*new;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new = (char *)ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (!new)
		return (0);
	ft_strlcpy(new, s1, s1_len + 1);
	ft_strlcat(new, s2, s1_len + s2_len + 1);
	return (new);
}

char	*ft_strdup(const char *s)
{
	int		s_len;
	char	*dupl;

	s_len = ft_strlen(s);
	dupl = ft_calloc(s_len + 1, sizeof(char));
	ft_memcpy(dupl, s, s_len + 1);
	return (dupl);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ret;
	size_t	end;
	size_t	s_len;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	end = 0;
	if (start < s_len)
		end = s_len - start;
	else
		return ((char *)ft_calloc((1), sizeof(char)));
	if (end > len)
		end = len;
	ret = (char *)ft_calloc((end + 1), sizeof(char));
	if (!ret)
		return (0);
	ft_strlcpy(ret, s + start, end + 1);
	return (ret);
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
