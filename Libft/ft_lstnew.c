/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ouar <hel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 13:53:49 by hel-ouar          #+#    #+#             */
/*   Updated: 2022/11/18 11:57:46 by hel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*cell;

	cell = malloc(sizeof(t_list));
	if (!cell)
		return (0);
	cell->content = content;
	cell->next = 0;
	return (cell);
}
