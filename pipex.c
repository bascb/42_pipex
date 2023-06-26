/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 18:03:05 by bcastelo          #+#    #+#             */
/*   Updated: 2023/06/26 19:47:27 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char **argv, char **env)
{
	t_pipex	params;

	if (argc != 5)
	{
		ft_putendl_fd("Wrong number of arguments!", 2);
		exit(0);
	}
	get_params(argc, argv, env, &params);
	process_commands(params);
	clean_params(&params);
	exit(0);
}

void	process_commands(t_pipex params)
{
	int		pipe_fds[2];
	int		i;
	pid_t	pid;

	if (pipe(pipe_fds) == -1)
		error_exit(&params);
	i = 0;
	while (i < params.total_commands)
	{	
		pid = fork();
		if (pid == -1)
			error_exit(&params);
		if (pid == 0)
			exec_command(pipe_fds, params, i);
		i++;
	}
	close(pipe_fds[0]);
	close(pipe_fds[1]);
	i = 0;
	while (i++ < params.total_commands)
		wait(NULL);
}

void	exec_command(int pipe_fds[2], t_pipex params, int i)
{
	char *const	*command_items;
	const char	*command_path;

	if (i == 0)
	{
		close(pipe_fds[0]);
		duplicate_fd(params.infile_fd, STDIN_FILENO);
		duplicate_fd(pipe_fds[1], STDOUT_FILENO);
	}
	else if (i == params.total_commands - 1)
	{
		close(pipe_fds[1]);
		duplicate_fd(params.outfile_fd, STDOUT_FILENO);
		duplicate_fd(pipe_fds[0], STDIN_FILENO);
	}
	else
	{
		duplicate_fd(pipe_fds[1], STDOUT_FILENO);
		duplicate_fd(pipe_fds[0], STDIN_FILENO);
	}
	command_items = ft_split(params.commands[i], ' ');
	command_path = (const char *)params.commands_paths[i];
	execve(command_path, command_items, params.env);
	error_exit(NULL);
}

char	**get_commands_paths(char **commands,
				int total_commands, char **env_paths)
{
	int		i;
	char	**commands_paths;
	char	**delete;

	commands_paths = ft_calloc(total_commands + 1, sizeof(char *));
	if (commands_paths == NULL)
		return (NULL);
	i = 0;
	while (i < total_commands)
	{
		commands_paths[i] = get_command_path(commands[i], env_paths);
		if (commands_paths[i] == NULL)
		{
			delete = commands_paths;
			while (*commands_paths != NULL)
			{
				free(*commands_paths);
				commands_paths++;
			}
			free(delete);
			return (NULL);
		}
		i++;
	}
	return (commands_paths);
}

void	get_params(int argc, char **argv, char **env, t_pipex *params)
{
	params->total_commands = argc - 3;
	params->commands = argv + 2;
	params->env = env;
	params->infile_fd = open(argv[1], O_RDONLY);
	params->outfile_fd = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR);
	if (params->infile_fd == -1 || params->outfile_fd == -1)
		error_exit(NULL);
	params->env_paths = NULL;
	while (*env != NULL)
	{
		if (ft_strnstr(*env, "PATH=", 5))
		{
			params->env_paths = ft_split(ft_strchr(*env, '=') + 1, ':');
			break ;
		}
		env++;
	}
	if (params->env_paths == NULL)
		error_exit(NULL);
	params->commands_paths = get_commands_paths(params->commands,
			params->total_commands, params->env_paths);
	if (params->commands_paths == NULL)
		error_exit(params);
}
