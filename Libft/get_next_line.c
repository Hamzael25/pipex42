/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ouar <hel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 13:58:34 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/01/05 14:22:39 by hel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_newtmp_gnl(char *tmp)
{
	char	*new;
	int		i;
	int		size;
	int		j;

	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!tmp[i] || !tmp)
		return (free(tmp), NULL);
	size = (ft_strlen_gnl(tmp) - i);
	new = malloc(sizeof(char) * size);
	if (!new)
		return (free(tmp), NULL);
	j = 0;
	i++;
	while (tmp[i] != '\0')
		new[j++] = tmp[i++];
	new[j] = '\0';
	return (free(tmp), new);
}

char	*ft_newline_gnl(char *tmp)
{
	char	*line;
	int		i;

	i = 0;
	if (!tmp[i])
		return (NULL);
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	if (tmp[i] == '\0')
		line = malloc(sizeof(char) * (i + 1));
	else
		line = malloc(sizeof(char) * (i + 2));
	if (!line)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		line[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_tmp_gnl(int fd, char *tmp)
{
	char		*str;
	int			rd;

	str = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!str)
		return (free(tmp), NULL);
	rd = 1;
	while (!ft_strchr_gnl(tmp, '\n') && rd != 0)
	{
		rd = read(fd, str, BUFFER_SIZE);
		if (rd == -1)
			return (free(tmp), free(str), NULL);
		str[rd] = '\0';
		tmp = ft_strjoin_gnl(tmp, str);
	}
	free(str);
	return (tmp);
}

char	*get_next_line_gnl(int fd)
{
	static char	*tmp;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (read(fd, NULL, 0) == -1)
		return (free(tmp), tmp = NULL, NULL);
	tmp = ft_tmp_gnl(fd, tmp);
	if (!tmp)
		return (free(tmp), NULL);
	line = ft_newline_gnl(tmp);
	if (line)
		tmp = ft_newtmp_gnl(tmp);
	else
	{
		free(tmp);
		tmp = NULL;
	}
	return (line);
}
