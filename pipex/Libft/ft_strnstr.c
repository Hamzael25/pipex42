/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ouar <hel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 11:01:56 by hel-ouar          #+#    #+#             */
/*   Updated: 2022/11/18 15:14:51 by hel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	if (needle[i] == '\0')
		return ((void *)haystack);
	else if (n == 0)
		return (NULL);
	while (haystack[i] && i < n)
	{
		k = i;
		j = 0;
		while (haystack[i + j] == needle[j] && k < n)
		{
			if (needle[j + 1] == '\0')
				return ((char *)(haystack + i));
			j++;
			k++;
		}
		i++;
	}
	return (0);
}
