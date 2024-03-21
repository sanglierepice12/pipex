#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_comp(char *string, char *look_for)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (string[i])
	{
		j = 0;
		while (string[i] && string[i] == look_for[j])
		{
			i++;
			j++;
			if (!look_for[j])
				return (1);//equal
		}
		if (string[i])
			i++;
	}
	return (0);//not equal
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size != 0)
	{
		while (src[i] != '\0' && i < size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}

void	ft_free_tab(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

static size_t	ft_count_words(const char *str, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (i == 0 || str[i - 1] == c)
		{
			if (str[i] != c)
				count++;
		}
		i++;
	}
	return (count);
}

static size_t	ft_wordlen(const char *str, char c)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	**ft_fill_tab(char const *s, char c, char **tab)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			len = ft_wordlen(&s[i], c);
			tab[j] = malloc(sizeof(char) * (len + 1));
			if (!tab[j])
			{
				ft_free_tab(tab);
				return (NULL);
			}
			ft_strlcpy(tab[j], &s[i], len + 1);
			i += len;
			j++;
		}
		else
			i++;
	}
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	size_t	size;
	char	**tab;

	size = ft_count_words(s, c);
	tab = malloc(sizeof(char *) * (size + 1));
	if (!tab)
		return (NULL);
	tab = ft_fill_tab(s, c, tab);
	if (!tab)
		return (NULL);
	tab[size] = NULL;
	return (tab);
}

void	_find_if_here(char *env)
{
	access()
}

void	_print_path(char **arv, char **env)
{
	int		i;

	i = 0;
	while (!_comp(env[i], "PATH"))
		i++;
	printf("path = %s\n", env[i]);
	_find_if_here(env[i]);
}

int	main(int arc, char **arv, char **env)
{
	if (arc)
		;
	_print_path(arv, env);
	return (EXIT_SUCCESS);
}