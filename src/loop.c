/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.@42.fr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:32:22 by gboudrie          #+#    #+#             */
/*   Updated: 2020/09/12 22:55:22 by mcm1k            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

t_vec   update_mix_values(t_vec mix, int mode)
{
    mix.x -= 0.01;
    mix.y -= 0.01;
    mix.z -= 0.01;
    mix.w -= 0.01;
    if (mix.x < 0.0)
        mix.x = 0.0;
    if (mix.y < 0.0)
        mix.y = 0.0;
    if (mix.z < 0.0)
        mix.z = 0.0;
    if (mix.w < 0.0)
        mix.w = 0.0;
    if (mode == 0 && mix.w < 1.0)
        mix.w += 0.02;
    else if (mode == 1 && mix.x < 1.0)
        mix.x += 0.02;
    else if (mode == 2 && mix.y < 1.0)
        mix.y += 0.02;
    else if (mode == 3 && mix.z < 1.0)
        mix.z += 0.02;
    return (mix);
}

