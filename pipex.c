/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ouar <hel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 13:31:25 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/01/30 18:55:38 by hel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
		return (perror("fork"));
	if (p->id_first == 0)
	{
		first_child(argv[2], p, envp);
	}
	else
	{
		p->id_second = fork();
		if (p->id_second == -1)
			return (ft_free_tab(p->first_cmd), perror("fork"));
		if (p->id_second == 0)
		{
			second_child(argv[3], p, envp);
		}
		waitpid(p->id_first, NULL, 1);
	}
	close(p->fd[0]);
	close(p->fd[1]);
}

int	init_pipex(t_pipe *p, char **argv, char **envp)
{
	p->infile = open(argv[1], O_RDONLY);
	p->outfile = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (p->infile < 0)
		perror("error infile");
	if (p->outfile < 0)
		return (perror("error outfile"), exit(1), 0);
	p->path = ft_find_path(envp);
	if (!p->path)
		return (perror("error env"), exit(0), 0);
	p->paths = ft_split(p->path, ':');
	if (pipe(p->fd) == -1)
		return (ft_free_tab(p->paths), perror("pipe"), exit(0), 0);
	pipex(p, argv, envp);
	ft_free_tab(p->paths);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipe	p;

	if (argc != 5 || !*envp)
		return (perror("error args"), exit(1), 0);
	else
		init_pipex(&p, argv, envp);
}
