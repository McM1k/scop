/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 20:12:28 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/21 17:28:59 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issemispace(char c)
{
	if ((c == ' ') || (c == '\n') || (c == '\t'))
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	char		*str;
	char		*ptr;
	size_t		i;

	ptr = (char *)s;
	while ((ft_issemispace(*ptr) == 1) && (*ptr))
		ptr++;
	i = ft_strlen(ptr);
	if (i == 0)
		return ("");
	while (ft_issemispace(ptr[i - 1]) == 1)
		i--;
	if ((str = ft_strnew(size)) != NULL)
	{
		str[size] = '\0';
		while (size)
		{
			str[size - 1] = ptr[size - 1];
			size--;
		}
		return (str);
	}
	return (NULL);
}
