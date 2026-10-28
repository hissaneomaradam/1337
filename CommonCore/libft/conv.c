#include <stdio.h>
char	*ft_strdup(const char *s);

char	*conv(const char *r)
{
	int	i;
	char *p;
	p = ft_strdup(r);
	i = 0;
	while (p[i])
	{
		if (p[i] == '0')
			p[i] = '1';	
		else
			p[i] = '0';
		i++;
	}
	p[i - 1] = '1';
	return (p);
}
#include <stdio.h>
int	main()
{
	printf("%s\n", conv("0101101110100000"));
}

