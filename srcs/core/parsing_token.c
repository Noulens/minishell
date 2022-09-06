/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:36:13 by cfontain          #+#    #+#             */
/*   Updated: 2022/09/06 17:11:36 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int		char_is_token(char c)
{
	if (c == '<' || c == '>' || c == '$' || c == '|')
		return (1);
	else
		return (0);	
}

int	check_quote(char *str, int i)
{
	if (str[i] == 39)
	{
		i++;
		while (str[i] != 0 && str[i] != 39)
			i++;
		if (str[i] != 39)
			return (1);
	}
	if (str[i] == 34)
	{
		i++;
		while (str[i] != 0 && str[i] != 34)
			i++;
		if (str[i] != 34)
			return (1);
	}
	return (0);
}

int	char_is_whitespace(char c)
{
	if (c >= 9 && c <= 11)
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int		next_token_or_space(char *str, int i)
{
	char	c;

	c = 0;
	while (char_is_whitespace(str[i]) == 1)
		i++;	
	while (str[i] != 0 && char_is_token(str[i]) == 0
		&& char_is_whitespace(str[i]) == 0)
	{
		if (char_is_quote(str[i]) == 0)
		{
			if (check_quote(str, i) == 0)
			{
				c = str[i];
				i++;
				while (str[i] != c)
					i++;
			}
		}
		i++;
	}
	return (i);
}

int		next_token(char *str, int i)
{
	char	c;
	
	c = 0;
	while (str[i] != 0 && char_is_token(str[i]) == 0)
	{
		if (char_is_quote(str[i]) == 0)
		{
			if (check_quote(str, i) == 0)
			{
				c = str[i];
				i++;
				while (str[i] != c)
					i++;
			}
		}
		i++;
	}
	return (i);
}
void	ft_strdup_without_quote_2(char *str, char *new_str, int i, int quote)
{
	int		j;
	char	c;
	int		k;

	k = 0;
	j = next_token_or_space(str, i);
	while (i < j)
	{
		if (quote == 0)
			c = 0;
		if (char_is_quote(str[i]) == 0 && quote == 0)
		{
			if (check_quote(str, i) == 0)
			{
				c = str[i];
				quote = 2;
			}
		}	
		if (str[i] != c)
		{
			new_str[k] = str[i];
			k++;
		}
		if (str[i] == c)
			quote--;
		i++;
	}
}

char	*ft_strdup_without_quote(char *str)
{
	int		i;
	int		quote;
	char	*new_str;

	i = 0;
	new_str = NULL;
	quote = 0;
	new_str = calloc(sizeof(char), ft_strlen(str));
	if (new_str == NULL)
		return (NULL);
	while (char_is_whitespace(str[i]) == 1)
		i++;
	ft_strdup_without_quote_2(str, new_str, i, quote);	
	return (new_str);
}

int		chevron_in(char *str, t_command *cmd, int *i)
{
	(*i)++;
	if (str[(*i)] == '<')
	{
		(*i)++;
		cmd->here_doc = 1;
		cmd->limiter = ft_strdup_without_quote(str + (*i));
	}	
	else
	{
		cmd->infile = ft_strdup_without_quote(str + (*i));
		if (cmd->infile == NULL)
			return (1);
		cmd->fd[1] = open(cmd->infile, O_RDONLY);
		if (cmd->fd[1] == -1)
			return (perror(cmd->infile), 1);	
	}	
	(*i) = next_token_or_space(str, (*i));
	return (0);
}

int		chevron_out(char *str, t_command *cmd, int *i)
{
	(*i)++;
	if (str[(*i)] == '>')
	{
		(*i)++;
		cmd->outfile_append  = 1;
	}	
	cmd->outfile = ft_strdup_without_quote(str + (*i));
	if (cmd->outfile == NULL)
		return (1);
	if (cmd->outfile_append != 1)	
		cmd->fd[1] = open(cmd->outfile, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (cmd->outfile_append == 1)
		cmd->fd[1] = open(cmd->outfile, O_WRONLY | O_CREAT, 0644);
	if (cmd->fd[1] == -1)
		return (perror(cmd->outfile), 1);	
	(*i) = next_token_or_space(str, (*i));	
	return (0);
}

int chevron_init(char *str, int *i, t_command *cmd)
{
	if (str[(*i)] == '<')
	{
		if (chevron_in(str, cmd, i) == 1)
			return (1);
	}
	else if (str[(*i)] == '>')
	{
		if (chevron_out(str, cmd, i) == 1)
			return (1);
	}
	return (0);
}	

int		cmd_init_2(char *str, int *i, t_command *cmd, int count)
{
	int		k;
	int		l;

	l = 0;
	k = *i;
	cmd->cmd = malloc(sizeof(char *) * (count + 1));
	if (cmd->cmd == NULL)
		return (1);
	while (l <= count)
	{
		cmd->cmd[l] = 0;
		l++;
	}
	l = 0;
	while (l < count)
	{
		cmd->cmd[l] = ft_strdup_without_quote(str + k);
		k = next_token_or_space(str, k);
		l++;
	}
	*i = k;
	return (0);
}

int		cmd_init(char *str, int *i, t_command *cmd)
{
	int		j;
	int		k;
	int		count;
	
	k = *i;
	j = next_token(str, k);
	k = *i;
	count = 0;
	while (k < j)
	{
		k = next_token_or_space(str, k);
		while (char_is_whitespace(str[k]) == 1)
			k++;
		count ++;
	}
	if (cmd_init_2(str, i, cmd, count) == 1)
		return (1);
	return (0);

}

int parsing_token(char *str, t_command *cmd)
{
	int		i;
	int 	j;
	int		trigg;

	trigg = 0;
	i = 0;
	j = 0;
	cmd->cmd = NULL;
	cmd->outfile_append = 0;
	while (str[i] != 0)
	{
		while (char_is_whitespace(str[i]) == 1)
		i++;	
		if (str[i] == '<' || str[i] == '>')
			{
				if (chevron_init(str, &i, cmd) == 1)
					return (1);
			}
		else if (str[i] != 0)
		{
			if (cmd_init(str, &i, cmd) == 1)
				return (1);
		}		
	}	
	printf("infile =%s\n", cmd->infile);
	printf("outfile =%s\n", cmd->outfile);
	printf("limiter =%s\n", cmd->limiter);
	ft_printab(cmd->cmd);
	printf("%s\n", cmd->cmd[0]);
	printf("heredoc =%d\n", cmd->here_doc);
	printf("append =%d\n", cmd->outfile_append);

	return (0);
}


