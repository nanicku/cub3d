#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char *)s;
	if (c == 0)
	{
		while (p[i] != '\0')
			i++;
		return (&p[i]);
	}
	while ((p[i] != '\0') && (p[i] != (unsigned char)c))
		i++;
	if (p[i] == '\0')
		return (NULL);
	return (&p[i]);
}
