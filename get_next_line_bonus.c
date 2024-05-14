/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:14:15 by tomek             #+#    #+#             */
/*   Updated: 2024/05/14 21:30:41 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoinfree(char *remind, char *buf)
{
	char	*temp;

	temp = ft_strjoin(remind, buf);
	free(remind);
	return (temp);
}

char	*ft_next(char *remind)
{
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (remind[i] && remind[i] != '\n')
		i++;
	if (!remind[i])
	{
		free(remind);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(remind) - i + 1), sizeof(char));
	i++;
	j = 0;
	while (remind[i])
		line[j++] = remind[i++];
	free(remind);
	return (line);
}

char	*find_eol(char *remind)
{
	char	*line;
	int		i;

	if (!*remind)
		return (NULL);
	i = 0;
	while (remind[i] && remind[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char));
	i = 0;
	while (remind[i] && remind[i] != '\n')
	{
		line[i] = remind[i];
		i++;
	}
	if (remind[i] && remind[i] == '\n')
		line[i] = '\n';
	return (line);
}

char	*read_fd(int fd, char *remind)
{
	char	*buf;
	int		bytes_read;

	if (!remind)
		remind = ft_calloc(1, 1);
	buf = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!buf)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		remind = ft_strjoinfree(remind, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (remind);
}

char	*get_next_line(int fd)
{
	char			*line;
	static char		*buffer[FD_MAX];

	if (fd <= -1 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = read_fd(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = find_eol(buffer[fd]);
	buffer[fd] = ft_next(buffer[fd]);
	return (line);
}
