/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 23:53:42 by bcastelo          #+#    #+#             */
/*   Updated: 2023/06/26 17:32:02 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft.h"
# include <stdio.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/wait.h>

typedef struct s_pipex
{
	int			infile_fd;
	int			outfile_fd;
	char *const	*env;
	char		**env_paths;
	char		**commands;
	char		**commands_paths;
	int			total_commands;
}				t_pipex;

void	exec_command(int pipe_fds[2], t_pipex params, int i);

void	process_commands(t_pipex params);

char	*get_command_path(char *command, char **env);

char	**get_commands_paths(char **commands,
			int total_commands, char **env_paths);

void	duplicate_fd(int fd, int new_fd);

void	get_params(int argc, char **argv, char **env, t_pipex *params);

void	error_exit(t_pipex *params);

void	free_memory(char **array);

void	clean_params(t_pipex *params);

#endif