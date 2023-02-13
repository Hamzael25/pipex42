/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ouar <hel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 13:33:09 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/02/09 19:40:24 by hel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/pipex.h"

static int	init_here_doc(int argc, char **argv, char **envp, t_pipe *p)
{
	if (!*envp)
		return (0);
	p->infile = open("infile", O_CREAT | O_RDWR | O_TRUNC, 0644);
	p->outfile = open(argv[argc - 1], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (p->infile < 0)
		error(p, "error infile");
	if (p->outfile < 0)
		return (error(p, "error outfile"), exit(1), 0);
	while (1)
	{
		write(1, "here_doc> ", 10);
		p->line = get_next_line_gnl(0);
		if (!p->line)
			return (free(p->line), 0);
		if ((!ft_strncmp(argv[2], p->line, ft_strlen(argv[2]))
				&& p->line[ft_strlen(argv[2])] == '\n'))
			break ;
		write(p->infile, p->line, ft_strlen(p->line));
		free(p->line);
	}
	free(p->line);
	return (1);
}

int	here_doc(t_pipe *p, int argc, char **argv, char **envp)
{
	if (!init_here_doc(argc, argv, envp, p))
		return (exit(1), 0);
	p->path = ft_find_path(envp);
	if (!p->path)
		return (error(p, "error env"), exit(0), 0);
	p->paths = ft_split(p->path, ':');
	close(p->infile);
	p->infile = open("infile", O_RDONLY);
	return (1);
}
