#include "libft.h"

int	ft_isalnum(int c)
{
	if (((c >= 48) && (c <= 57)) || (ft_isalpha(c)))
		return (1);
	return (0);
}
