#include "minishell.h"

int	copy_tab_with_space(char **argv, char *str)
{
	int	i;

	i = 0;
	while (argv[i] != NULL)
	{
		ft_strlcat(str, argv[i], (ft_strlen(str) + ft_strlen(argv[i]) + 1));
		str[ft_strlen(str)] = ' ';
		i++;
	}
	str[(ft_strlen(str) - 1)] = 0;
	return (0);
}

int	ft_count_tab(char **str)
{
	int		i;
	int     len;

	len = 0;
	i = 0;
	if (str)
	{
		while (str[i] != NULL)
		{
			len += ft_strlen(str[i]);
			i++;
		}
	}
	return (len + i);
}

char *str_join_tab(char **argv)
{
	int     i;
	char *str;

	i = ft_count_tab(argv);
	//ft_printf("i =%d\n", i);
	str = calloc(sizeof(char), (i + 1));
	if (str == NULL)
		return (NULL);
	copy_tab_with_space(argv, str);	
	return (str);
}
