/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_pipex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikaismou <ikaismou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:31:25 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/02/09 13:33:37 by ikaismou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

char	*ft_find_path(char **envp)
{
	int	i;

	i = 0;
	while (ft_strncmp("PATH", envp[i], 4))
		i++;
	if (!envp[i])
		return (NULL);
	return (envp[i] + 5);
}

void	pipex(t_pipe *p, char **argv, char **envp)
{
	p->id_first = fork();
	if (p->id_first == -1)
		return (error(p, "fork"));
	if (p->id_first == 0)
		first_child(argv[2], p, envp);
	p->id_second = fork();
	if (p->id_second == -1)
		return (error(p, "fork"));
	if (p->id_second == 0)
	{
		second_child(argv[3], p, envp);
	}
	close(p->fd[0]);
	close(p->fd[1]);
	waitpid(p->id_first, NULL, 0);
	waitpid(p->id_second, NULL, 0);
}

int	init_pipex(t_pipe *p, char **argv, char **envp)
{
	p->infile = open(argv[1], O_RDONLY);
	p->outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (p->infile < 0)
		error(p, "error infile");
	if (p->outfile < 0)
		return (error(p, "error outfile"), exit(1), 0);
	p->path = ft_find_path(envp);
	if (!p->path)
		return (error(p, "error env"), exit(0), 0);
	p->paths = ft_split(p->path, ':');
	if (!p->paths)
		return (error(p, "error"), exit(0), 0);
	if (pipe(p->fd) == -1)
		return (error(p, "pipe"), exit(0), 0);
	pipex(p, argv, envp);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	p;

	p.paths = NULL;
	p.first_cmd = NULL;
	p.second_cmd = NULL;
	p.cmd = NULL;
	if (argc != 5 || !*envp)
		return (error(&p, "error args"), exit(1), 0);
	else
		init_pipex(&p, argv, envp);
	free_pipex(&p);
}
