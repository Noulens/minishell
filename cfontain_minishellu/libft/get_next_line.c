/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 12:20:35 by cfontain          #+#    #+#             */
/*   Updated: 2022/07/14 15:42:54 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_final_line(char	*line)
{
	int		i;
	int		j;
	int		k;
	char	*finalline;

	i = -1;
	j = 0;
	k = 1;
	while (line[j] != '\n' && line[j] != 0)
		j++;
	if (line[j] == '\n')
		k++;
	finalline = ft_callocbzerognl(sizeof(char), (j + k));
	if (finalline == NULL)
		return (free (line), NULL);
	while (++i < j)
		finalline[i] = line[i];
	if (k == 2)
		finalline[i] = '\n';
	return (free (line), finalline);
}

char	*ft_read_line(int fd, char *temp, char *line, int i)
{
	char	*buffer;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (buffer == NULL)
		return (free (line), NULL);
	buffer[0] = 0;
	if (temp)
	{
		free (line);
		line = ft_strdupgnl(temp);
		free (temp);
		if (line == NULL)
			return (NULL);
	}	
	while (ft_end_line(buffer) == 0 && i != 0)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i == -1)
			return (free (buffer), free (line), NULL);
		buffer[i] = 0;
		line = ft_strjoingnl(line, buffer);
		if (line == NULL)
			return (free (buffer), NULL);
	}
	return (free (buffer), line);
}

char	*ft_stock_line(char	*line, int *trigger)
{
	char		*temp;
	size_t		i;

	i = 0;
	while (line[i] != '\n' && line[i] != 0)
		i++;
	if (ft_strlen(line) == i)
		return (NULL);
	temp = ft_strdupgnl(line + i + 1);
	if (temp == NULL)
	{
		(*trigger)++;
		return (NULL);
	}		
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*temp[FOPEN_MAX + 1];
	int			trigger;
	int			i;

	trigger = 0;
	i = 1;
	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 0)
		return (NULL);
	line = ft_callocbzerognl(sizeof(char), 1);
	if (line == NULL)
		return (NULL);
	line = ft_read_line(fd, temp[fd], line, i);
	if (line == NULL)
		return (free (line), free (temp[fd]), NULL);
	temp[fd] = ft_stock_line(line, &trigger);
	if (trigger != 0)
		return (free (line), free (temp[fd]), NULL);
	line = ft_final_line(line);
	if (ft_strlen(line) == 0)
		return (free (temp[fd]), free(line), NULL);
	return (line);
}

/*
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void	ft_open_line(int fd)
{
	char	*str;
	str = get_next_line(fd);
	printf("%s", str);
	while (str != NULL)
	{
		free (str);
		str = get_next_line(fd);
		printf("%s", str);
	}	
	free (str);
}		


int main()
{
	int fd1;
	int fd2;
	int fd3;
	
	//fd1 = open("texte fd1.txt", O_RDONLY);
	//ft_open_line(fd1);
	fd2 = open("texte fd2.txt", O_RDONLY);
	ft_open_line(fd2);
	
	//fd3 = open("texte fd3.txt", O_RDONLY);
	//ft_open_line(fd3);
	
}
*/