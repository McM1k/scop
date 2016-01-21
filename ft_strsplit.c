/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/03 20:54:26 by gboudrie          #+#    #+#             */
/*   Updated: 2016/01/21 18:14:20 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_howmuchrow(const char *s, char c)
{
	int		row;
	int		i;

	row = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			row++;
			while ((s[i + 1] != c) && (s[i + 1]))
				i++;
		}
		i++;
	}
	return (row);
}

static char		*ft_setptr(char const *s, char c, int l)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	while (j < l)
	{
		i = k;
		while (s[i] == c)
			i++;
		j++;
		k = i;
		while (s[k] != c)
			k++;
	}
	return ((char *)&s[i]);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**tab;
	int			i;
	char		*ptr;
	int			j;

	i = 0;
	if (!(tab = (char **)ft_memalloc((sizeof(*tab)) * ft_howmuchrow(s, c) + 1)))
		return (NULL);
	tab[ft_howmuchrow(s, c)] = NULL;
	while (i < ft_howmuchrow(s, c))
	{
		ptr = ft_setptr(s, c, i + 1);
		if (!(tab[i] = ft_strnew(ft_strlenc(ptr, c))))
			return (NULL);
		j = 0;
		while (j < ft_strlenc(ptr, c))
		{
			tab[i][j] = *(ptr + j);
			j++;
		}
		i++;
	}
	return (tab);
}
