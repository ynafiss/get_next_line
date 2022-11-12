/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynafiss <ynafiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 15:37:39 by ynafiss           #+#    #+#             */
/*   Updated: 2022/11/11 16:03:14 by ynafiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_ft(int fd, char *str)
{
	char	*d;
	int		i;

	i = 1;
	d = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!d)
		return (NULL);
	while (!ft_strchr(str, '\n') && i != 0)
	{
		i = read(fd, d, BUFFER_SIZE);
		if (i == -1)
		{
			free(d);
			free (str);
			return (0);
		}
		d[i] = '\0';
		str = ft_strjoin(str, d);
		if (!str)
			return (NULL);
	}
	free(d);
	return (str);
}

char	*ft_fr(char *str)
{
	int		i;
	int		j;
	char	*d;

	i = 0;
	j = 0;
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	if (!str[i])
	{
		free (str);
		return (NULL);
	}
	i++;
	d = malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!d)
	{
		free (str);
		return (NULL);
	}
	while (str[i] != '\0')
		d[j++] = str[i++];
	d[j] = '\0';
	free (str);
	return (d);
}

char	*ft_l1(char *s)
{
	int		i;
	int		j;
	char	*d;

	i = 0;
	j = 0;
	if (!ft_strlen(s))
		return (NULL);
	while (s[i] != '\n' && s[i] != '\0')
		i++;
	if (s[i] == '\n')
		d = malloc(sizeof(char) * (i + 2));
	else
		d = malloc(sizeof(char) * (i + 1));
	if (!d)
		return (NULL);
	while (j <= i && s[j] != '\0')
	{
		d[j] = s[j];
		j++;
	}
	d[j] = '\0';
	return (d);
}

char	*get_next_line(int fd)
{
	static char	*str[OPEN_MAX];
	char		*ptr;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	str[fd] = ft_ft(fd, str[fd]);
	if (str[fd] == NULL)
		return (NULL);
	ptr = ft_l1(str[fd]);
	str[fd] = ft_fr(str[fd]);
	return (ptr);
}
