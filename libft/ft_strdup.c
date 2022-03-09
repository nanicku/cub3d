#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*cpy;

	len = ft_strlen(s1) + 1;
	cpy = malloc(sizeof(char) * len);
	if (!cpy)
		return (0);
	cpy = ft_memcpy(cpy, s1, len);
	return (cpy);
}
