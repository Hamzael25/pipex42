/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_pipex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikaismou <ikaismou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 16:35:29 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/02/09 13:33:41 by ikaismou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

void	free_pipex(t_pipe *p)
{
	if (p->first_cmd)
		ft_free_tab(p->first_cmd);
	if (p->second_cmd)
		ft_free_tab(p->second_cmd);
	if (p->paths)
		ft_free_tab(p->paths);
	if (p->cmd)
		free(p->cmd);
}

void	error(t_pipe *p, char *str)
{
	free_pipex(p);
	perror(str);
}

void	init_tab(t_pipe *p)
{
	p->paths = NULL;
	p->first_cmd = NULL;
	p->second_cmd = NULL;
	p->cmd = NULL;
}
