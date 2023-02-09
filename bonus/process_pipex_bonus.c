/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pipex_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikaismou <ikaismou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/29 18:28:20 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/02/09 15:06:49 by ikaismou         ###   ########.fr       */
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

void	exec(t_pipe *p, char *str, char **envp)
{
	p->first_cmd = ft_split(str, ' ');
	if (!p->first_cmd)
		return (error(p, "command not found: "), exit(1));
	p->cmd = init_cmd(p, p->first_cmd);
	if (p->cmd == 0)
		return (error(p, "command not found: "), exit(1));
	if (execve(p->cmd, p->first_cmd, envp) == -1)
		return (error(p, ""), exit(1));
}

void	pipex_multiple(t_pipe *p, char **envp)
{
	if (p->id_first == 0)
	{
		close(p->fd[1]);
		if (dup2(p->fd[0], 0) == -1)
			return (error(p, ""), exit(1));
		waitpid(p->id_first, NULL, 0);
	}
	else
	{
		p->id_second = fork();
		if (p->id_second == -1)
			return (error(p, "fork"));
		if (p->id_second == 0)
		{
			close(p->fd[0]);
			if (dup2(p->fd[1], 1) == -1 \
				|| execve(p->cmd, p->first_cmd, envp) == -1)
				return (error(p, ""), exit(1));
		}
		free_pipex(p);
		exit(0);
	}
}
