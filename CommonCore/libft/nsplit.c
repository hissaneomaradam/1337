#include <stdio.h>
#include <stdlib.h>
char	*ft_substr(char const *s, unsigned int start, size_t len);

size_t	word_count(char const *s, int c)
{
	size_t	i;
	size_t	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}
static size_t wordlen(char const *s, int c)
{
	size_t	len;
	
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static void	free_mem(char **s, size_t n)
{
	while (n--)
		free(s[n]);
	free(s);
}

static int	fill(char **str, const char *s, int c)
{
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			len = wordlen(s + i, c);
			str[j] = ft_substr(s, i, len);
			if (!str[j])
			{
				free_mem(str, j);
				return (0);
			}
			j++;
			i += len;
		}
	}
	str[j] = NULL;
	return (1);
}

char	**nsplit(const char *s, int c)
{
	char **str;

	str = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!str)
		return (NULL);
	if (!fill(str, s, c))
		return (NULL);
	return (str);
}

int	main()
{
	char **str;
	int	i;

	i = 0;
	str =  nsplit("nhellon nwordn nimn nadamn", 'n');
	while (str[i])
	{
		printf("%s", str[i]);
		free(str[i]);
		i++;
	}
	free(str);
}
