/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ouar <hel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 14:25:09 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/02/06 19:00:16 by hel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_pipe
{
	int		infile;
	int		outfile;
	int		fd[2];
	char	*path;
	char	**paths;
	char	**first_cmd;
	char	**second_cmd;
	char	*cmd;
	char	*cmd2;
	int		id_first;
	int		id_second;
	char	*command;
	char	*initcmd;
}				t_pipe;

char	*ft_find_path(char **envp);

void	error(t_pipe *p, char *str);

void	free_pipex(t_pipe *p);

void	first_child(char *str, t_pipe *p, char **envp);

void	second_child(char *str, t_pipe *p, char **envp);

int		init_pipex(t_pipe *p, char **argv, char **envp);

void	pipex(t_pipe *p, char **argv, char **envp);

void	exec(t_pipe *p, char *str, char **envp);

void	pipex_multiple(t_pipe *p, char **envp);

char	*init_cmd(t_pipe *p, char **tab);

void	init_tab(t_pipe *p);

#endif