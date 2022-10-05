/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 23:28:09 by waxxy             #+#    #+#             */
/*   Updated: 2022/10/05 12:37:04 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	get_fd_in(t_command *cm)
{
	if (cm->here_doc >= TRUE)
	{
		cm->fd[0] = open(".here_doc.tmp", O_RDONLY);
		if (cm->fd[0] == -1 || cm->fd[0] > FOPEN_MAX)
			perror("get_fd_in");
	}
}

int	nb_cmd(char **argv)
{
	int	i;

	i = 0;
	if (argv == NULL || *argv == NULL)
		return (0);
	else
	{
		while (argv[i])
			i++;
	}
	return (i);
}

void	list_to_array(t_minishell *ms)
{
	t_list	*tmp;
	size_t	idx;

	if (ms->env_array != NULL)
		free(ms->env_array);
	idx = ft_lstsize(ms->env);
	ms->env_array = (char **)ft_calloc(sizeof(char *), idx + 1);
	if (!ms->env_array)
		return (perror("list_to_array"), (void)0);
	tmp = ms->env;
	idx = 0;
	while (tmp != NULL)
	{
		ms->env_array[idx] = tmp->content;
		idx++;
		tmp = tmp->next;
	}
}

void	list_to_export(t_minishell *ms)
{
	t_list	*tmp;
	size_t	idx;

	if (ms->env_array != NULL)
		free(ms->env_array);
	idx = ft_lstsize(ms->env);
	ms->env_array = (char **)ft_calloc(sizeof(char *), idx + 1);
	if (!ms->env_array)
		return (perror("list_to_array"), (void)0);
	tmp = ms->env;
	idx = 0;
	while (tmp != NULL)
	{
		if (ft_strchr(tmp->content, '='))
		{
			ms->env_array[idx] = tmp->content;
			idx++;
		}
		tmp = tmp->next;
	}
}

void	ft_sorted(int nb, char **str)
{
	int		i;
	int		j;
	char	*p;

	i = 1;
	while (i < nb)
	{
		j = i;
		while (j > 0 && ft_strcmp(str[j - 1], str[j]) > 0)
		{
			p = str[j - 1];
			str[j - 1] = str[j];
			str[j] = p;
			--j;
		}
		++i;
	}
}

void swap(t_list *a, t_list *b) 
{ 
    char *temp;
	
	temp = a->content; 
    a->content = b->content; 
    b->content= temp; 
}

void bubblesortlist(t_list *start) 
{ 
    short	swapped;
    t_list	*ptr1;
    t_list	*lptr;
	//int		i;

    //if (start == NULL) 
    //    return ;
	swapped = 0;
	while (swapped)
    do
    { 
        swapped = 0; 
        ptr1 = start; 
  
        while (ptr1->next != lptr) 
        { 
            if (ptr1->content > ptr1->next->content) 
            { 
                swap(ptr1, ptr1->next); 
                swapped = 1; 
            } 
            ptr1 = ptr1->next; 
        } 
        lptr = ptr1; 
    } 
    while (swapped); 
}
