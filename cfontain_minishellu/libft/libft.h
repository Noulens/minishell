/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfontain <cfontain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 15:03:00 by cfontain          #+#    #+#             */
/*   Updated: 2022/08/05 10:54:07 by cfontain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

typedef struct s_split
{
	char	**str;
	int		len;
	int		count;
}	t_split;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif 

void	destroy_str(char **str);

int		ft_printf_error(const char *str, ...);
void	ft_checkpourcent_error(const char *str, va_list list, int *i, int *len);
void	ft_putnbr_printf_error(long int nb, int *len);
void	ft_putnegative_error(int *len);
void	ft_writenbr_error(unsigned long int nb, int *len);
void	ft_putstr_printf_error(char *str, int *len);
void	ft_putchar_printf_error(int a, int *len);
void	ft_pointerisnullornot_error(unsigned long nb, int *len);
void	ft_putnbrhex_printf_error(unsigned long int nb, int *len);
void	ft_putnbrhexupper_error(unsigned int nb, int *len);
void	ft_writenbrupper_error(unsigned long int nb, int *len);

int		ft_printf(const char *str, ...);
void	ft_checkpourcent(const char *str, va_list list, int *i, int *len);
void	ft_putnbr_printf(long int nb, int *len);
void	ft_putnegative(int *len);
void	ft_writenbr(unsigned long int nb, int *len);
void	ft_putstr_printf(char *str, int *len);
void	ft_putchar_printf(int a, int *len);
void	ft_pointerisnullornot(unsigned long nb, int *len);
void	ft_putnbrhex_printf(unsigned long int nb, int *len);
void	ft_putnbrhexupper(unsigned int nb, int *len);
void	ft_writenbrupper(unsigned long int nb, int *len);

char	*get_next_line(int fd);
char	*ft_stock_line(char	*line, int *trigger);
char	*ft_read_line(int fd, char *temp, char *line, int i);
char	*ft_final_line(char	*line);
int		ft_end_line(char *line);
char	*ft_strdupgnl(char *s);
char	*ft_strjoingnl(char *s1, char *s2);
char	*ft_callocbzerognl(size_t nmemb, size_t size);

int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_isdigit(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_isprint(int c);
int		ft_atoi(const char *nptr);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memset(void *s, int c, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_itoa(int n);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strjoin(char const *s1, char const *s2);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif 
