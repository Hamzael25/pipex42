/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ouar <hel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:33:09 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/02/08 18:37:35 by hel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

static char	*ft_find_path2(char **envp)
{
	int	i;

	i = 0;
	while (ft_strncmp("PATH", envp[i], 4))
		i++;
	if (!envp[i])
		return (NULL);
	return (envp[i] + 5);
}

static int	init_here_doc(int argc, char **argv, char **envp, t_pipe *p)
{
	if (!*envp)
		return (0);
	if (argc != 6)
		return (error(p, "here_doc : error args"), exit(1), 0);
	p->infile = open("here_doc", O_CREAT | O_RDWR | O_TRUNC, 0644);
	p->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (p->infile < 0)
		error(p, "error infile");
	if (p->outfile < 0)
		return (error(p, "error outfile"), exit(1), 0);
	p->path = ft_find_path2(envp);
	if (!p->path)
		return (error(p, "error env"), exit(0), 0);
	p->paths = ft_split(p->path, ':');
	if (pipe(p->fd) == -1)
		return (error(p, "pipe"), exit(0), 0);
	return (1);
}

int	here_doc(t_pipe *p, int argc, char **argv, char **envp)
{
	char	*tab;

	tab = NULL;
	if (!init_here_doc(argc, argv, envp, p))
		return (exit(1), 0);
	while (1)
	{
		tab = get_next_line_gnl(0);
		if (!ft_strncmp(argv[2], tab, ft_strlen(argv[2])))
			break ;
		write(p->infile, tab, ft_strlen(tab));
	}
	return (1);
}
