/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 17:27:51 by gboudrie          #+#    #+#             */
/*   Updated: 2015/12/09 15:07:17 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char		*s2;

	s2 = NULL;
	s2 = ft_strnew(len);
	if (!s2)
		return (NULL);
	ft_strncpy(s2, &(s[start]), len);
	return (s2);
}
