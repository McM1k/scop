/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 13:25:36 by gboudrie          #+#    #+#             */
/*   Updated: 2020/09/21 18:20:19 by mcm1k            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_splitdel(void **split)
{
	void	**ptr;

	ptr = split;
	while (*ptr)
	{
		free(*ptr);
		*ptr = NULL;
		ptr++;
	}
	free(*split);
	*split = NULL;
}
