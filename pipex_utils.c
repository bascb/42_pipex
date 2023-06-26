/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 12:20:33 by bcastelo          #+#    #+#             */
/*   Updated: 2023/06/26 18:22:08 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_command_path(char *command, char **env_paths)
{
	char	**command_items;
	char	*path;
	size_t	path_size;

	command_items = ft_split(command, ' ');
	while (*env_paths != NULL)
	{
		path_size = ft_strlen(command_items[0]) + ft_strlen(*env_paths) + 2;
		path = ft_calloc(path_size, sizeof(char));
		ft_strlcpy(path, *env_paths, path_size);
		ft_strlcat(path, "/", path_size);
		ft_strlcat(path, command_items[0], path_size);
		if (access(path, X_OK) == 0)
		{
			free_memory(command_items);
			return (path);
		}
		free(path);
		env_paths++;
	}
	free_memory(command_items);
	return (NULL);
}

void	duplicate_fd(int fd, int new_fd)
{
	if (fd != new_fd)
	{
		if (dup2(fd, new_fd) == -1)
			error_exit(NULL);
		close(fd);
	}
}

void	error_exit(t_pipex *params)
{
	perror("pipex");
	if (params != NULL)
		clean_params(params);
	exit(0);
}

void	free_memory(char **array)
{
	char	**aux;

	aux = array;
	while (*aux != NULL)
	{
		free(*aux);
		aux++;
	}
	free(array);
}

void	clean_params(t_pipex *params)
{
	if (params->env_paths != NULL)
	{
		free_memory(params->env_paths);
		params->env_paths = NULL;
	}	
	if (params->commands_paths != NULL)
	{
		free_memory(params->commands_paths);
		params->commands_paths = NULL;
	}
}
