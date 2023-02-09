/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ouar <hel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:08:57 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/01/15 17:52:41 by hel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	overflow(int sign)
{
	if (sign == -1)
		return (0);
	else
		return (-1);
}

static int	ft_isspace(int c)
{
	if ((c > 8 && c < 14) || c == 32)
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	int			i;
	long long	nbr;
	long long	signe;

	i = 0;
	nbr = 0;
	signe = 1;
	while (ft_isspace(str[i]) && str[i] != 0)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		if (!ft_isdigit(str[i + 1]))
			return (0);
		i++;
	}
	while (ft_isdigit(str[i]) && str[i] != 0)
	{
		if (nbr != (nbr * 10 + (str[i] - '0')) / 10)
			return ((int)overflow(signe));
		nbr = nbr * 10 + (str[i] - 48);
		i++;
	}
	return (nbr * signe);
}
