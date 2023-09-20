/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agvincen <agvincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/12 15:35:36 by agvincen          #+#    #+#             */
/*   Updated: 2023/08/26 23:58:57 by agvincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_next(char *buffer)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (0);
	}
	temp = ft_calloc_gnl(ft_strlen_gnl(buffer) - i + 1, sizeof(char));
	j = 0;
	while (buffer[i + 1] != '\0')
	{
		temp[j] = buffer[i + 1];
		i++;
		j++;
	}
	temp[j] = '\0';
	free (buffer);
	return (temp);
}

char	*ft_clean_line(char *buffer)
{
	int		i;
	char	*temp;

	i = 0;
	if (!buffer[i])
		return (0);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	temp = ft_calloc_gnl(i + 2, sizeof(char));
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		temp[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
		temp[i] = '\n';
	return (temp);
}

char	*ft_read_line(int fd, char *buffer)
{
	char	*temp;
	int		already_read;

	temp = ft_calloc_gnl((BUFFER_SIZE + 1), sizeof(char));
	already_read = 1;
	while (already_read != 0 && !ft_strchr_gnl(buffer, '\n'))
	{
		already_read = read(fd, temp, BUFFER_SIZE);
		if (already_read == -1)
		{
			free(temp);
			free(buffer);
			return (0);
		}
		temp[already_read] = '\0';
		buffer = ft_strjoin_gnl(buffer, temp);
	}
	free(temp);
	return (buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[FOPEN_MAX];
	char		*line;

	if (fd < 0 || BUFFER_SIZE == 0)
		return (0);
	buffer[fd] = ft_read_line(fd, buffer[fd]);
	if (!buffer[fd])
		return (0);
	line = ft_clean_line(buffer[fd]);
	buffer[fd] = ft_next(buffer[fd]);
	return (line);
}

/* int	main(void)
{
	int	fd;

	fd = open("file.txt", O_RDONLY);
	printf("%s", get_next_line(fd));
	close(fd);
	return (0);
}
 */