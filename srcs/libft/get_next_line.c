/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lromano <lromano@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:41:47 by lromano           #+#    #+#             */
/*   Updated: 2024/09/19 14:24:31 by lromano          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char **str)
{
	free(*str);
	*str = NULL;
	return (NULL);
}

char	*leftover(char *storage)
{
	char	*leftover;
	char	*ptr;
	int		len;

	ptr = ft_strchrc(storage, '\n');
	if (!ptr)
	{
		leftover = NULL;
		return (ft_free(&storage));
	}
	else
		len = (ptr - storage) + 1;
	if (!storage[len])
		return (ft_free(&storage));
	leftover = ft_substrc(storage, len, ft_strlenc(storage) - len);
	ft_free(&storage);
	if (!leftover)
		return (NULL);
	return (leftover);
}

char	*create_line(char *storage)
{
	char	*line;
	char	*ptr;
	int		len;

	ptr = ft_strchrc(storage, '\n');
	len = (ptr - storage) + 1;
	line = ft_substrc(storage, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

char	*readbuf(int fd, char *storage)
{
	int		readbytes;
	char	*buffer;

	readbytes = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (ft_free(&storage));
	buffer[0] = '\0';
	while (readbytes > 0 && !ft_strchrc(buffer, '\n'))
	{
		readbytes = read (fd, buffer, BUFFER_SIZE);
		if (readbytes > 0)
		{
			buffer[readbytes] = '\0';
			storage = ft_strjoinc(storage, buffer);
		}
	}
	free(buffer);
	if (readbytes == -1)
		return (ft_free(&storage));
	return (storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = {0};
	char		*line;

	if (fd < 0)
		return (NULL);
	if ((storage && !ft_strchrc(storage, '\n')) || !storage)
		storage = readbuf (fd, storage);
	if (!storage)
		return (NULL);
	line = create_line(storage);
	if (!line)
		return (ft_free(&storage));
	storage = leftover(storage);
	return (line);
}
