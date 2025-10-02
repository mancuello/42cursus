/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrac_clean_cmd.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:26:05 by mcuello           #+#    #+#             */
/*   Updated: 2025/06/16 03:00:20 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	set_redir_append(t_redir *redir, char *filename)
{
	int	fd;

	if (redir->output)
		free(redir->output);
	redir->output = ft_strdup(filename);
	fd = open(redir->output, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (fd != -1)
		close(fd);
	else
		perror("open");
	redir->append = 1;
}

static void	set_redir_out(t_redir *redir, char *filename)
{
	int	fd;

	if (redir->output)
		free(redir->output);
	redir->output = ft_strdup(filename);
	fd = open(redir->output, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd != -1)
		close(fd);
	else
		perror("open");
	redir->append = 0;
}

int	handle_redirection(t_token **tokens, t_redir *redir)
{
	t_token	*curr;

	curr = *tokens;
	if ((curr->type == TOKEN_REDIR_IN || curr->type == TOKEN_REDIR_OUT
			|| curr->type == TOKEN_REDIR_APPEND) && curr->next)
	{
		if (bad_filename(curr->next))
			return (-1);
		if (curr->type == TOKEN_REDIR_IN)
			redir->input = ft_strdup(curr->next->value);
		else if (curr->type == TOKEN_REDIR_APPEND)
			set_redir_append(redir, curr->next->value);
		else if (curr->type == TOKEN_REDIR_OUT)
			set_redir_out(redir, curr->next->value);
		*tokens = curr->next->next;
		return (1);
	}
	if ((curr->type == TOKEN_REDIR_IN || curr->type == TOKEN_REDIR_OUT
			|| curr->type == TOKEN_REDIR_APPEND) && curr->next == NULL)
		return (-1);
	return (0);
}

static void	append_clean_token(t_token **head, t_token **last, t_token *src)
{
	t_token	*new;

	new = create_token_for_redir(src->value, src->type);
	if (!*head)
	{
		*head = new;
		*last = new;
	}
	else
	{
		(*last)->next = new;
		*last = new;
	}
}

t_token	*extract_clean_cmd(t_token *tokens, t_redir *redir)
{
	t_token	*head;
	t_token	*last;
	int		handle_result;

	head = NULL;
	last = NULL;
	handle_result = 0;
	while (tokens)
	{
		handle_result = handle_redirection(&tokens, redir);
		if (handle_result == -1)
		{
			if (!tokens->next)
				printf("bash: syntax error near unexpected token `newline'\n");
			return (NULL);
		}
		if (handle_result == 1)
			continue ;
		append_clean_token(&head, &last, tokens);
		tokens = tokens->next;
	}
	return (head);
}
