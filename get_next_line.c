/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalkhat <asalkhat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 15:05:32 by asalkhat          #+#    #+#             */
/*   Updated: 2026/10/10 10:52:08 by asalkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_and_save_2(const char *save)
{
	int	i;

	if (save == NULL)
		return (0);
	i = 0;
	while (save[i] != '\0')
	{
		if (save[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*read_and_save(int fd, char *save)
{
	char	*buff;
	char	*temp;
	int		num;

	buff = malloc(BUFFER_SIZE + 1);
	if (buff == NULL)
		return (free(save), NULL);
	num = 1;
	while (num > 0)
	{
		if (read_and_save_2(save))
			break ;
		num = read(fd, buff, BUFFER_SIZE);
		if (num < 0)
			return (free(buff), free(save), NULL);
		if (num == 0)
			break ;
		buff[num] = '\0';
		temp = strjoin(save, buff);
		if (!temp)
			return (free(buff), free(save), NULL);
		free(save);
		save = temp;
	}
	return (free(buff), save);
}

static char	*extract_line(char *save)
{
	int	i;

	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	if (save[i] == '\n')
		return (ft_substr(save, 0, i + 1));
	return (ft_substr(save, 0, i));
}

static char	*update_save(char *save)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	if (save[i] == '\0' || save[i + 1] == '\0')
		return (free(save), NULL);
	j = ft_strlen(save);
	ptr = ft_substr(save, i + 1, j - (i + 1));
	free(save);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = read_and_save(fd, save);
	if (save == NULL)
		return (NULL);
	line = extract_line(save);
	if (line == NULL)
	{
		free(save);
		save = NULL;
		return (NULL);
	}
	save = update_save(save);
	return (line);
}
