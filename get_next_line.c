/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomek <tomek@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/06 18:14:15 by tomek             #+#    #+#             */
/*   Updated: 2024/04/26 19:03:45 by tomek            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*get_next_line(int fd);
static int	read_fd(int fd, char **remind);
static char	*find_eol(char **remind);

static char	*find_eol(char **remind)
{
	char	*line;
	int		pos;
	char	*temp;

	if (!ft_strchr(*remind, '\n'))
	{
		line = *remind;
		*remind = ft_strdup("");
	}
	else
	{
		pos = ft_strchr(*remind, '\n') - *remind;
		line = ft_substr(*remind, 0, pos - 1);
		temp = *remind;
		*remind = ft_substr(temp, pos + 1, ft_strlen(temp) - (pos + 1));
		free(temp);
	}
	return (line);
}

static int	read_fd(int fd, char **remind)
{
	char	*str;
	char	*temp;
	int		bytes_read;

	str = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (0);
	while (!ft_strchr(str, '\n'))
	{
		bytes_read = read(fd, str, BUFFER_SIZE);
		if (bytes_read == -1 || bytes_read == 0)
			break ;
		str[bytes_read] = '\0';
		temp = *remind;
		*remind = ft_strjoin(temp, str);
		free(temp);
	}
	free(str);
	return (bytes_read > 0);
}
ghjh


char	*get_next_line(int fd)
{
	int				buffer;
	char			*line;
	static char		*remind;

	if (!remind)
		remind = ft_strdup("");
	if (fd <= -1 || BUFFER_SIZE <= 0)
	{
		free(remind);
		return (0);
	}
	buffer = read_fd(fd, &remind);
	if ((!buffer && !*remind) || !remind)
	{
		if (remind)
		{
			free(remind);
			remind = NULL;
		}
		return (0);
	}
	line = find_eol(&remind);
	return (line);
}
