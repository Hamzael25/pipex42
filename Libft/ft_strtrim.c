/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ouar <hel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 09:56:02 by hel-ouar          #+#    #+#             */
/*   Updated: 2022/11/18 15:17:37 by hel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	indicestart(char const *s, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		j = 0;
		while (set[j] && s[i] != set[j])
			j++;
		if (set[j] == 0)
			break ;
		i++;
	}
	return (i);
}

static int	indiceend(char const *s, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
		i++;
	i--;
	while (i > 0)
	{
		j = 0;
		while (set[j] && s[i] != set[j])
			j++;
		if (set[j] == 0)
			break ;
		i--;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		len2;
	int		start;
	int		end;
	char	*dest;

	start = indicestart(s1, set);
	end = indiceend(s1, set) + 1;
	len2 = end - start;
	dest = (ft_substr(s1, start, len2));
	return (dest);
}
