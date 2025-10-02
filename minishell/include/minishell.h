/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haxpe-ga <haxpe-ga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:39:34 by mcuello           #+#    #+#             */
/*   Updated: 2025/06/16 11:38:31 by haxpe-ga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <signal.h>
# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdbool.h>
# include "libft.h"

extern int	g_exit_status;

typedef enum e_token_type
{
	TOKEN_WORD,
	TOKEN_PIPE,
	TOKEN_REDIR_IN,
	TOKEN_REDIR_OUT,
	TOKEN_REDIR_APPEND,
	TOKEN_HEREDOC,
	TOKEN_EOF
}	t_token_type;

typedef struct s_token
{
	char			*value;
	t_token_type	type;
	struct s_token	*next;
}	t_token;

typedef struct s_env
{
	char	**env;
	t_token	*token;
}	t_env;

typedef struct s_redir
{
	char		*input;
	char		*output;
	int			append;
}	t_redir;

typedef struct s_child_args
{
	t_token	*cmd;
	char	**env;
	int		in_fd;
	t_token	*tokens;
	int		fd[2];
}	t_child_args;

typedef struct s_cmd_result
{
	t_token	*cmd;
	int		heredoc_fd;
}	t_cmd_result;

t_token	*tokenize(char *input, char **env);
void	free_tokens(t_token *tokens);
void	free_split(char **args);
void	print_tokens(t_token *tokens);
int		find_equal(char *str);
char	**deep_copy(char **env);

void	do_dot(t_token *tokens);
void	execute_tokens(t_token *tokens, char **env);
void	remove_var(char **env, int index);
int		is_builtin(t_token *tokens);
void	do_pwd(void);
void	do_cd(t_token *tokens, char **env);
void	do_echo(t_token *tokens);
void	do_env(char **env, char *input);
void	do_export(t_token *tokens, char ***env);
void	do_unset(t_token *tokens, char **env);

t_token	*create_token(char *value, t_token_type type);
int		is_metacharacter(char c);
void	skip_spaces(char **input);
t_token	*handle_redirection_2(char **input);
char	*extract_word(char **input);

void	do_exit(t_token *tokens);
char	*get_env_value(char **env, const char *key);
void	handle_signals(void);
void	handle_eof(void);

void	do_pipes(t_token *token, char **env);
int		check_pipes(t_token *tokens);
t_token	*extract_cmd(t_token **tokens, t_token_type TOKEN_TYPE);
int		count_cmds(t_token *tokens);
int		is_last_token_pipe(t_token *tokens);
void	append_tokens(t_token **head, t_token *new_tokens);
int		executable_cmds(t_token **tokens, char **env);
void	exec_pipeline(t_token *tokens, char **env, pid_t *pids);

void	init_child_args_part1(t_child_args *args, t_token *cmd,
			char **env, int in_fd);
void	init_child_args_part2(t_child_args *args, t_token *tokens,
			int fd[2]);

void	do_redir(t_token *tokens, char **env);
int		check_redir(t_token *tokens);
t_token	*extract_clean_cmd(t_token *tokens, t_redir *redir);
int		handle_redirection(t_token **tokens, t_redir *redir);
void	free_redir(t_redir *redirs);
t_token	*create_token_for_redir(char *value, t_token_type type);
int		bad_filename(t_token *filename);
void	redir_child(t_token *cmd, t_redir *redir_info, char **env);
t_redir	*create_redir_struct(void);

void	child_process(t_token *cmd, char **env, int in_fd, int *fd);
void	parent_process(int *in_fd, int *fd, int has_pipe);
int		get_heredoc(t_token *tokens);
int		read_input(char *delimiter);
t_token	*deep_copy_tokens(t_token *tokens);
int		check_heredoc(t_token *tokens);
int		is_delimiter(char *input, char *delimiter);
int		init_pipe(int pipe_fd[2]);

void	do_main_heredoc(t_token *tokens, char **env);

char	*expand_env_variable(char *str, char **env);
int		has_unclosed_quotes(const char *input);
int		is_only_spaces(const char *str);

void	init_env(t_env **copy_env, char **env);
int		minishell_loop(t_env *copy_env, char **env);

int		is_metacharacter(char c);

int		handle_invalid_var(char *value);
void	replace_existing_var(char ***env, int pos, char *value);
void	add_new_var(char ***env, char *value);
int		is_valid_var_name(char *str);
#endif