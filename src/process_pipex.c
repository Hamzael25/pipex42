/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pipex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikaismou <ikaismou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 15:15:56 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/02/09 13:33:39 by ikaismou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static char	*get_cmd(t_pipe	*p, char *str)
{
	char	*tmp;
	int		i;

	i = 0;
	while (p->paths[i])
	{
		tmp = ft_strjoin(p->paths[i], "/");
		p->command = ft_strjoin(tmp, str);
		free(tmp);
		if (open(p->command, O_RDONLY) != -1)
			return (p->command);
		i++;
		free(p->command);
	}
	return (NULL);
}

char	*init_cmd(t_pipe *p, char **tab)
{
	char		*cmd;

	if (tab[0][0] == '/' ||
		(tab[0][0] == '.' && tab[0][1] == '/'))
	{
		if (open(tab[0], O_RDONLY) == -1)
			return (NULL);
		return (tab[0]);
	}
	else
		cmd = get_cmd(p, tab[0]);
	return (cmd);
}

void	first_child(char *str, t_pipe *p, char **envp)
{
	p->first_cmd = ft_split(str, ' ');
	if (!p->first_cmd)
		return (error(p, "first command not found: "), exit(128));
	p->cmd = init_cmd(p, p->first_cmd);
	if (p->cmd == 0 || dup2(p->infile, 0) == -1 \
		|| dup2(p->fd[1], 1) == -1)
		return (error(p, "first command not found : "), exit(128));
	close(p->fd[0]);
	if (execve(p->cmd, p->first_cmd, envp) == -1)
		return (error(p, ""), exit(128));
}

void	second_child(char *str, t_pipe *p, char **envp)
{
	p->second_cmd = ft_split(str, ' ');
	if (!p->second_cmd)
		return (error(p, "second command not found: "), exit(128));
	p->cmd2 = init_cmd(p, p->second_cmd);
	if (p->cmd2 == 0 || dup2(p->outfile, 1) == -1 || dup2(p->fd[0], 0) == -1)
		return (error(p, "second command not found"), exit(128));
	close(p->fd[1]);
	if (execve(p->cmd2, p->second_cmd, envp) == -1)
		return (error(p, ""), exit(128));
}
