/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:40:13 by gboudrie          #+#    #+#             */
/*   Updated: 2015/12/04 18:50:49 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*s_new;

	i = 0;
	s_new = NULL;
	s_new = ft_strnew(ft_strlen(s));
	if (!s_new)
		return (NULL);
	while (s[i])
	{
		s_new[i] = f(s[i]);
		i++;
	}
	s_new[i] = '\0';
	return (s_new);
}
