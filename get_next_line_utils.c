/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asalkhat <asalkhat@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/09 15:25:45 by asalkhat          #+#    #+#             */
/*   Updated: 2026/10/09 15:36:28 by asalkhat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *strjoin(const char *save, const char *buff)
{
	char *ptr;
	size_t i;
	size_t j;

	i = 0;
	j = ft_strlen(buff);
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

static char	*strjoin_2(const char *save, const char *buff)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = ft_strlen(save);
	j = ft_strlen(buff);
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

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	i = ft_strlen(s);
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

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
