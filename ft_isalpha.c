#include "cub3d.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == '/' || c == '.')
	{
		return (1);
	}
	return (0);
}
