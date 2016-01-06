/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 22:06:16 by gboudrie          #+#    #+#             */
/*   Updated: 2015/12/20 18:03:58 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *s1, const char *s2, size_t n)
{
	ft_strncpy(s1 + ft_strlen(s1), s2, n);
	if (n <= ft_strlen(s2))
		s1[ft_strlen(s1) + n] = '\0';
	return (s1);
}
