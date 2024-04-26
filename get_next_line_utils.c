/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 16:54:17 by tszymans          #+#    #+#             */
/*   Updated: 2024/04/26 18:16:20 by tomek            ###   ########.fr       */
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
	new = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
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
	dupl = (char *)malloc((s_len + 1) * sizeof(char));
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
		return ((char *)((1) * sizeof(char)));
	if (end > len)
		end = len;
	ret = (char *)malloc((end + 1) * sizeof(char));
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

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;
	char	*s;

	s = (char *)src;
	i = 0;
	if (n != 0)
	{
		while (*s != '\0' && i < (n - 1))
		{
			*dst = *s;
			dst++;
			s++;
			i++;
		}
		*dst = '\0';
	}
	return (ft_strlen(src));
}

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;
	char	*s;

	i = 0;
	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	s = (char *)src;
	if (n == 0 && !dst)
		return (len_src);
	if (n <= len_dst)
		return (n + len_src);
	while (i < (n - len_dst - 1) && s[i] != '\0' )
	{
		dst[len_dst + i] = s[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_dst + len_src);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (0);
	i = 0;
	while (i < n)
	{
		*((unsigned char *)dest + i) = *((unsigned char *)src + i);
		i++;
	}
	return (dest);
}