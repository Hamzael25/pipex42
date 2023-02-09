/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_3char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ouar <hel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 15:19:38 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/02/08 19:06:04 by hel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(const char *s, char c, char e, char f)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] == c || s[i] == e || s[i] == f || s[i] == '\0') == 0
			&& (s[i + 1] == c || s[i + 1] == e || s[i + 1] == f
				|| s[i + 1] == '\0') == 1)
			j++;
		i++;
	}
	return (j + 1);
}

static int	ft_sizeword(const char *s, char c, char e, char f)
{
	int	count;

	count = 0;
	while (s)
	{
		if (*s == c || *s == e || *s == f)
			return (count + 1);
		s++;
		count++;
	}
	return (count + 1);
}

static char	**ft_free(char **tab, int j)
{
	int	i;

	i = -1;
	while (i++ < j)
		free (tab[i]);
	free(tab);
	return (NULL);
}

char	**ft_split3(char const *s, char c, char e, char f)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	tab = (char **)malloc(sizeof(char *) * ft_countword(s, c, e, f));
	if (!tab)
		return (NULL);
	while (s[k] && i < ft_countword(s, c, e, f) - 1)
	{
		while (s[k] == c || s[k] == e || s[k] == f)
			k++;
		tab[i] = (char *)malloc(sizeof (char) * ft_sizeword(s + k, c, e, f));
		if (!tab[i])
			return (ft_free(tab, i));
		j = 0;
		while (s[k] && s[k] != c && s[k] != e && s[k] != f)
			tab[i][j++] = s[k++];
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}
