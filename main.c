#include "libft.h"

int main(void)
{
	char *s1;
	char *s2;

	s1 = ft_strnew(15);
	s2 = ft_strnew(15);
	ft_strcpy(s1, "poulet ");
	ft_strcpy(s2, "braisay");
	ft_strncat(s1, s2, 0);
	ft_putendl(s1);
	return (0);
}
