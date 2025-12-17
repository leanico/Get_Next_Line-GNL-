/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leaherre <leaherre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 18:45:08 by leaherre          #+#    #+#             */
/*   Updated: 2025/12/10 18:45:08 by leaherre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = read_and_add_to_stash(stash, fd);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
	{
		free (stash);
		stash = NULL;
		return (NULL);
	}
	stash = update_stash(stash);
	return (line);
}

char	*read_and_add_to_stash(char *stash, int fd)
{
	ssize_t	num;
	char	*temp;
	char	*buffer;

	buffer = init_stash_and_buffer(&stash);
	if (!buffer)
		return (NULL);
	while (!ft_strchr(stash, '\n'))
	{
		num = read(fd, buffer, BUFFER_SIZE);
		if (num < 0)
			return (free(buffer), free(stash), NULL);
		if (num == 0)
			break ;
		buffer[num] = '\0';
		temp = stash;
		stash = ft_strjoin(temp, buffer);
		if (!stash)
			return (free(temp), free(buffer), NULL);
		free(temp);
	}
	free(buffer);
	return (stash);
}

char *init_stash_and_buffer(char **stash)
{
	char	*buffer;

	if (!*stash)
	{
		*stash = malloc(1);
		if (!*stash)
			return (NULL);
		(*stash)[0] = '\0';
	}
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
	{
		free(*stash);
		*stash = NULL;
	}
	return (buffer);
}

char	*extract_line(char *stash)
{
	char	*new_line;
	size_t	len;
	char	*line_break;

	if (stash == NULL || stash[0] == '\0')
		return (NULL);
	line_break = ft_strchr(stash, '\n');
	if (line_break != NULL)
		len = (line_break - stash) + 1;
	else
		len = ft_strlen(stash);
	new_line = ft_substr(stash, 0, len);
	if (new_line == NULL)
		return (NULL);
	return (new_line);
}

char	*update_stash(char *stash)
{
	char	*start_of_rest;
	char	*new_stash;
	size_t	start_index;
	size_t	len_of_rest;

	start_of_rest = ft_strchr(stash, '\n');
	if (!start_of_rest)
	{
		free(stash);
		return (NULL);
	}
	start_index = (start_of_rest - stash) + 1;
	len_of_rest = ft_strlen(stash) - start_index;
	new_stash = ft_substr(stash, start_index, len_of_rest);
	if (!new_stash)
	{
		free(stash);
		return (NULL);
	}
	free(stash);
	return (new_stash);
}


