/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 16:57:26 by gboudrie          #+#    #+#             */
/*   Updated: 2015/12/09 15:06:29 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*s_new;

	i = 0;
	s_new = NULL;
	s_new = ft_strnew(ft_strlen(s));
	if (!s_new)
		return (NULL);
	while (s[i])
	{
		s_new[i] = (*f)(i, s[i]);
		i++;
	}
	s_new[i] = '\0';
	return (s_new);
}
