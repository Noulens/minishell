/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnoulens <tnoulens@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 17:54:20 by tnoulens          #+#    #+#             */
/*   Updated: 2022/08/18 17:54:47 by tnoulens         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t   pid;
    pid_t   res;
    int     status;

    pid = fork();
    if (pid == -1)
        return (1);
    if (pid == 0)
    {
        usleep(50000);
        printf("Child 1 : I'm the first child !\n");
        return (0);
    }
    else if (pid > 0)
    {
        pid = fork();
        if (pid == -1)
            return (1);
        else if(pid == 0)
        {
            usleep(49900);
            printf("Child 2 : I'm the second child...\n");
            return (2);
        }
        else if(pid > 0)
        {
            printf("Parent : I have two children !\n");
            res = wait(&status);
            printf("Parent : I received my child %d\n", res);
            if (WIFEXITED(status))
                printf("Parent : It exited successfully, exit code %d\n", WEXITSTATUS(status));
            else
                printf("Parent : It was interrupted...\n");
            res = wait(&status);
            printf("Parent : I received my child %d\n", res);
            if (WIFEXITED(status))
                printf("Parent : It exited successfully, exit code %d\n", WEXITSTATUS(status));
            else
                printf("Parent : It was interrupted...\n");
        }
    }
    return (0);
}
