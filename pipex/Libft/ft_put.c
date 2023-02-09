/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ouar <hel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:29:42 by hel-ouar          #+#    #+#             */
/*   Updated: 2022/12/24 13:30:41 by hel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_printf(char c, int *len)
{
	if (*len == -1)
		return ;
	if (write(1, &c, 1) != -1)
		*len += 1;
	else
		*len = -1;
}

void	ft_putstr_printf(char *str, int *len)
{
	if (!str)
		str = "(null)";
	while (*str)
		ft_putchar_printf(*str++, len);
}
