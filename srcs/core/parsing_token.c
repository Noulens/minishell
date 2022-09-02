/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_token.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 10:36:13 by cfontain          #+#    #+#             */
/*   Updated: 2022/09/02 15:51:36 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	chevron_here_doc(char *str)
{
	(void)str;
}

void	chevron_out_double(char *str)
{
	(void)str;
}

int		chevron_no_sep(char c)
{
	if (c == 0 || c == '<' || c == '>' || c == '$' || c == '|' || c == ' ')
		return (1);
	else
		return (0);	
}

int	check_sing_quote(char *str, int i)
{
	i++;
	while (str[i] != 0 && str[i] != 39)
		i++;
	if (str[i] != 39)
		return (1);
	return (0);
}

void	str_copy_single_quote(char *src, char *dest, int *i, int *j)
{
	(*i)++;
	while (src[(*i)] != 0 && src[(*i)] != 39)
	{
		dest[(*j)] = src[(*i)];
		(*i)++;
		(*j)++;
	}
	printf("%s\n", dest);
}

//Si plusieurs >, il  va creer tous les fichiers a chaque fois, par contre il ne redirigera que sur le dernier fichier de la ligne
char	*simple_chevron(char *str, int *i, int in_or_out) 
{
	char	*file;
	int		j;
	int		trigger;
	int		fd;

	fd = 0;
	trigger = 0;
	file = calloc(sizeof(char), 100);
	if (file == NULL)
		return (NULL);
	j = 0;
	while (str[(*i)] == ' ')	
		(*i)++;
	while (str[(*i)] != 0 && chevron_no_sep(str[(*i)]) == 0)
	{
		trigger = 0;
		if (str[(*i)] == 39)
		{
			if (check_sing_quote(str, (*i)) == 0)
			{
				str_copy_single_quote(str, file, i, &j);
				trigger++;
			}	
		}
		if (trigger == 0)
		{
			file[j] = str[(*i)];
			j++;
		}	
		(*i)++;
	}
	if (j == 0)
		return (free (file), ft_printf("synthax error near unexpected token\n"), NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (perror(file), NULL);
	if (in_or_out == 0)
		fd = open(file, O_RDONLY);
	if (in_or_out == 1)	
		fd = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	close (fd);	
	return (file);
}

void chevron_init(char *str, int *i) // FAIRE LA REGLE DU <<< ET DU <>
{
	if (str[(*i)] == '<')
	{
		if (str[(*i) + 1] == '<')
			chevron_here_doc(str);
		else
			simple_chevron(str, i, 0);
	}
	if (str[(*i)] == '>')
	{
		if (str[(*i) + 1] == '>')
			chevron_out_double(str);
		else
			simple_chevron(str, i, 1);
	}
}

void parsing_token(char *str)
{
	int		i;

	i = 0;
	while (str[i] != 0)
	{
		while (str[i] == ' ')
			i++;
		if (str[i] == '<' || str[i] == '>')
			chevron_init(str, &i);
	}
}