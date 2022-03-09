#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		n;
	char	*fin;

	fin = (char *)s;
	n = ft_strlen(fin);
	if ((unsigned char)c == '\0')
		return (&fin[n]);
	while (n >= 0)
	{
		if (fin[n] == (unsigned char)c)
		{
			return (&fin[n]);
		}
		n--;
	}
	return (NULL);
}
