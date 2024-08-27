/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmendez- <pmendez-@student42.madrid>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 18:29:28 by pmendez-          #+#    #+#             */
/*   Updated: 2023/10/11 13:01:18 by pmendez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static char	*ft_free_join(char *str, char *buffer)
{
	char	*aux;

	aux = ft_strjoin(str, buffer);
	free(str);
	return (aux);
}

static char	*ft_read_file(int fd, char *str)
{
	int		read_bytes;
	char	*buffer;

	if (str == NULL)
		str = ft_calloc(1, sizeof(char));
	buffer = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (buffer == NULL)
		return (NULL);
	read_bytes = 1;
	while (read_bytes > 0)
	{
		read_bytes = read(fd, buffer, BUFFER_SIZE);
		if (read_bytes < 0)
		{
			free(buffer);
			free(str);
			return (NULL);
		}
		buffer[read_bytes] = 0;
		str = ft_free_join(str, buffer);
		if (ft_strchr(str, '\n'))
			break ;
	}
	free(buffer);
	return (str);
}

static char	*first_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer || !buffer[0])
		return (NULL);
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	line = (char *)ft_calloc((i + 2), sizeof(char));
	if (line == NULL)
		return (NULL);
	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] && buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	return (line);
}

static char	*pass_line(char *buffer)
{
	int		cont;
	int		j;
	char	*line;

	cont = 0;
	j = 0;
	while (buffer[cont] && buffer[cont] != '\n')
		cont++;
	if (!buffer[cont])
	{
		free (buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - cont + 1), sizeof(char));
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	cont++;
	while (buffer[cont])
		line[j++] = buffer[cont++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if ((buffer[fd] != NULL && buffer[fd][0] != '\0'))
		{
			free(buffer[fd]);
			buffer[fd] = NULL;
			return (NULL);
		}
	}
	buffer[fd] = ft_read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = first_line(buffer[fd]);
	if (line == NULL)
		return (NULL);
	buffer[fd] = pass_line(buffer[fd]);
	if (buffer[fd][0] == 0)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (line);
}
