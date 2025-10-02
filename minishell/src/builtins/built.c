/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 09:38:49 by haxpe-ga          #+#    #+#             */
/*   Updated: 2025/06/16 07:20:38 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	find_command(char **env, char **paths, char **args)
{
	char	*tmp;
	char	*full;

	while (*paths)
	{
		tmp = ft_strjoin(*paths, "/");
		full = ft_strjoin(tmp, args[0]);
		free(tmp);
		if (access(full, X_OK) == 0)
			execve(full, args, env);
		free(full);
		paths++;
	}
}

char	**get_args_from_tokens(t_token *tokens)
{
	t_token	*curr;
	int		count;
	char	**args;

	curr = tokens;
	count = 0;
	while (curr)
	{
		if (curr->type == TOKEN_WORD)
			count++;
		curr = curr->next;
	}
	args = malloc(sizeof(char *) * (count + 1));
	if (!args)
		return (NULL);
	curr = tokens;
	count = 0;
	while (curr)
	{
		if (curr->type == TOKEN_WORD)
			args[count++] = ft_strdup(curr->value);
		curr = curr->next;
	}
	args[count] = NULL;
	return (args);
}

void	execute_child_process(char **args, char **env)
{
	char	**paths;
	char	*path_env;

	if (!access(args[0], X_OK))
		execve(args[0], args, env);
	path_env = get_env_value(env, "PATH");
	if (!path_env || !*path_env)
	{
		printf("%s: No such file or directory\n", args[0]);
		free_split(args);
		exit(127);
	}
	paths = ft_split(path_env, ':');
	find_command(env, paths, args);
	perror(args[0]);
	free_split(args);
	exit(127);
}

void	execute_tokens(t_token *tokens, char **env)
{
	pid_t	pid;
	int		status;
	char	**args;

	status = 0;
	args = get_args_from_tokens(tokens);
	if (!args)
		return ;
	pid = fork();
	if (pid == 0)
	{
		execute_child_process(args, env);
		printf("hola\n");
	}
	else
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
			g_exit_status = WEXITSTATUS(status);
		else if (WIFSIGNALED(status))
			g_exit_status = 128 + WTERMSIG(status);
	}
	free_split(args);
}

int	is_builtin(t_token *tokens)
{
	if (!tokens || !tokens->value)
		return (0);
	if (!ft_strncmp(tokens->value, "cd", ft_strlen(tokens->value)))
		return (1);
	if (!ft_strncmp(tokens->value, "echo", ft_strlen(tokens->value)))
		return (1);
	if (!ft_strncmp(tokens->value, "env", ft_strlen(tokens->value)))
		return (1);
	if (!ft_strncmp(tokens->value, "exit", ft_strlen(tokens->value)))
		return (1);
	if (!ft_strncmp(tokens->value, "export", ft_strlen(tokens->value)))
		return (1);
	if (!ft_strncmp(tokens->value, "pwd", ft_strlen(tokens->value)))
		return (1);
	if (!ft_strncmp(tokens->value, "unset", ft_strlen(tokens->value)))
		return (1);
	if (!ft_strncmp(tokens->value, ".", ft_strlen(tokens->value)))
		return (1);
	return (0);
}
