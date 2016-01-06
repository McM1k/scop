/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 20:12:28 by gboudrie          #+#    #+#             */
/*   Updated: 2015/12/08 16:50:19 by gboudrie         ###   ########.fr       */
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
	size_t		c_begin;
	size_t		c_end;
	size_t		i;

	c_begin = 0;
	c_end = 0;
	i = ft_strlen(s);
	while ((ft_issemispace(s[c_begin]) == 1) && (s[c_begin]))
		c_begin++;
	if (c_begin == i)
		return ("");
	while (ft_issemispace(s[i - 1]) == 1)
	{
		c_end++;
		i--;
	}
	i = ft_strlen(s) - (c_end + c_begin);
	str = ft_strnew(i);
	if (!str)
		return (NULL);
	ft_strncpy(str, &(s[c_begin]), i);
	return (str);
}
