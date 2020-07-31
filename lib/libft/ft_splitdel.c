/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/30 13:25:36 by gboudrie          #+#    #+#             */
/*   Updated: 2020/07/31 13:43:16 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_splitdel(void ***split)
{
	void	**ptr;

	ptr = *split;
	while (*ptr)
	{
		ft_memdel(ptr);
		ptr++;
	}
	ft_memdel((void **)split);
}
