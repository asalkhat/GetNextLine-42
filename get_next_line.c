/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalkhat <asalkhat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/08 19:44:25 by asalkhat          #+#    #+#             */
/*   Updated: 2026/10/09 01:01:08 by asalkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

static char	*strjoin_2(const char *save, const char *buff)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	while (save[i])
		i++;
	while (buff[j])
		j++;
	ptr = malloc(i + j + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (save[i] != '\0')
	{
		ptr[i] = save[i];
		i++;
	}
	j = 0;
	while (buff[j] != '\0')
		ptr[i++] = buff[j++];
	ptr[i] = '\0';
	return (ptr);
}

static char	*strjoin(const char *save, const char *buff)
{
	char	*ptr;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (buff[j])
		j++;
	if (save == NULL)
	{
		ptr = malloc(j + 1);
		if (ptr == NULL)
			return (NULL);
		while (buff[i] != '\0')
		{
			ptr[i] = buff[i];
			i++;
		}
		ptr[i] = '\0';
		return (ptr);
	}
	ptr = strjoin_2(save, buff);
	return (ptr);
}

static char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	if (start >= i)
	{
		ptr = malloc(1);
		if (ptr == NULL)
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	ptr = malloc(len + 1);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < len && s[start + i] != '\0')
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

static char	*read_and_save(int fd, char *save)
{
	char	buff[BUFFER_SIZE + 1];
	int		num;
	int		i;

	while ((num = read(fd, buff, BUFFER_SIZE)) && num != -1)
	{
		buff[num] = '\0';
		i = 0;
		while (buff[i] != '\n' && buff[i] != '\0')
			i++;
		if (buff[i] == '\n')
		{
			save = strjoin(save, buff);
			break ;
		}
		save = strjoin(save, buff);
	}
	if (num == -1)
	{
		free(save);
		return (NULL);
	}
	return (save);
}

static char	*extract_line(char *save)
{
	int		i;

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
	j = 0;
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	while (save[j] != '\0')
		j++;
	ptr = ft_substr(save, i + 1, j - (i + 1));
	free(save);
	return (ptr);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	save = read_and_save(fd, save);
	if (save == NULL)
		return (NULL);
	line = extract_line(save);
	save = update_save(save);
	return (line);
}
