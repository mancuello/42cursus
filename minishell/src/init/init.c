/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 09:10:12 by haxpe-ga          #+#    #+#             */
/*   Updated: 2025/06/16 07:21:55 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(t_env **copy_env, char **env)
{
	*copy_env = malloc(sizeof(t_env));
	if (!*copy_env)
		return ;
	(*copy_env)->env = deep_copy(env);
	if (!(*copy_env)->env)
	{
		free(*copy_env);
		*copy_env = NULL;
		return ;
	}
}

static char	*read_complete_input(char *username)
{
	char	*input;
	char	*extra;
	char	*tmp;
	char	*joined;

	input = readline(username);
	while (input && has_unclosed_quotes(input))
	{
		extra = readline("> ");
		if (!extra)
			break ;
		tmp = input;
		input = ft_strjoin(input, "\n");
		joined = ft_strjoin(input, extra);
		free(tmp);
		free(input);
		input = joined;
		free(extra);
	}
	return (input);
}

static void	handle_builtins(t_token *tokens, t_env *copy_env, char *input)
{
	if (!ft_strncmp(tokens->value, "cd", 2))
		do_cd(tokens, copy_env->env);
	else if (!ft_strncmp(tokens->value, "pwd", 3))
		do_pwd();
	else if (!ft_strncmp(tokens->value, "echo", 4))
		do_echo(tokens);
	else if (!ft_strncmp(tokens->value, "exit", 4))
		do_exit(tokens);
	else if (!ft_strncmp(tokens->value, "env", 3))
		do_env(copy_env->env, input);
	else if (!ft_strncmp(tokens->value, "export", 6))
		do_export(tokens, &copy_env->env);
	else if (!ft_strncmp(tokens->value, "unset", 5))
		do_unset(tokens, copy_env->env);
	else if (!ft_strncmp(tokens->value, ".", 1))
		do_dot(tokens);
}

static void	process_input(char *input, t_env *copy_env, char **env)
{
	t_token	*tokens;

	add_history(input);
	tokens = tokenize(input, copy_env->env);
	if (!tokens)
		return ;
	if (check_pipes(tokens))
		do_pipes(tokens, copy_env->env);
	else if (check_redir(tokens))
		do_redir(tokens, env);
	else if (check_heredoc(tokens))
		do_main_heredoc(tokens, env);
	else if (is_builtin(tokens))
		handle_builtins(tokens, copy_env, input);
	else
		execute_tokens(tokens, copy_env->env);
	free_tokens(tokens);
}

int	minishell_loop(t_env *copy_env, char **env)
{
	char	*input;
	char	*username;

	while (1)
	{
		handle_signals();
		username = ft_strjoin(get_env_value(copy_env->env, "USER"),
				"@minishell$ ");
		if (username == NULL)
			username = ft_strjoin("void", "@minishell$ ");
		input = read_complete_input(username);
		if (!input)
		{
			handle_eof();
			free(username);
			break ;
		}
		if (*input != '\0' && !is_only_spaces(input))
			process_input(input, copy_env, env);
		free(input);
		free(username);
	}
	free_split(copy_env->env);
	free(copy_env);
	return (0);
}
