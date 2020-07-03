/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:07:37 by gboudrie          #+#    #+#             */
/*   Updated: 2020/07/03 16:09:30 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	framebuffer_size_callback(GLFWwindow *window, int width, int height)
{
	(void)window;
    glViewport(0, 0, width, height);
}  

void	error_callback(int error, const char *decription)
{
	ft_putstr("Error ");
	ft_putnbr(error);
	ft_putstr(" : ");
	ft_putendl(decription);
}

void	key_callback(GLFWwindow *window, int key, int scancode, int action, int mods)
{
	(void)scancode;
	(void)mods;
	if (key == GLFW_KEY_ESCAPE && action ==GLFW_PRESS) 
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}
