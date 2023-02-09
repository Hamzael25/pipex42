/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ouar <hel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:20:42 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/01/05 12:01:11 by hel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_base_printf(long long unsigned int nb, \
		long long unsigned int taille, char *base, int *len)
{
	if (nb > (taille - 1))
		ft_putnbr_base_printf((nb / taille), taille, base, len);
	ft_putchar_printf(base[nb % taille], len);
}

void	ft_putnbr_printf(int n, int *len)
{
	unsigned int	nb;

	if (n < 0)
	{
		ft_putchar_printf('-', len);
		nb = -n;
	}
	else
		nb = n;
	return (ft_putnbr_base_printf(nb, 10, "0123456789", len));
}
