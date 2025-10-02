/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_heredoc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcuello <mcuello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 12:33:33 by mcuello           #+#    #+#             */
/*   Updated: 2025/06/16 05:48:48 by mcuello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	report_syntax_error(int fd)
{
	printf("syntax error near unexpected token.\n");
	if (fd != -1)
		close(fd);
	return (-1);
}

static int	process_heredoc_token(t_token *token, int fd)
{
	int	tmp_fd;

	tmp_fd = read_input(token->value);
	if (tmp_fd == -1)
	{
		if (fd != -1)
			close(fd);
		return (-1);
	}
	if (fd != -1)
		close(fd);
	return (tmp_fd);
}

int	get_heredoc(t_token *tokens)
{
	int	fd;

	fd = -1;
	while (tokens)
	{
		if (!tokens || tokens->type != TOKEN_WORD)
			return (report_syntax_error(fd));
		fd = process_heredoc_token(tokens, fd);
		if (fd == -1)
			return (-1);
		tokens = tokens->next;
		if (tokens && tokens->type == TOKEN_HEREDOC)
			tokens = tokens->next;
		else
			break ;
	}
	return (fd);
}
