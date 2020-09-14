/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:07:37 by gboudrie          #+#    #+#             */
/*   Updated: 2020/09/09 13:53:20 by mcm1k            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

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
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) 
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	if (key == GLFW_KEY_X && action == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	if (key == GLFW_KEY_X && action == GLFW_RELEASE)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

t_vec   move_view(t_vec cam_pos, GLFWwindow *window)
{
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        cam_pos.y += 0.01;
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        cam_pos.y -= 0.01;
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        cam_pos.x -= 0.01;
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        cam_pos.x += 0.01;
    if (glfwGetKey(window, GLFW_KEY_PAGE_UP) == GLFW_PRESS
		|| glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        cam_pos.z -= 0.01;
    if (glfwGetKey(window, GLFW_KEY_PAGE_DOWN) == GLFW_PRESS
		|| glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
        cam_pos.z += 0.01;

    return (cam_pos);
}

int		change_tex(int tex_mode, GLFWwindow *window)
{	
    if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS
		|| glfwGetKey(window, GLFW_KEY_KP_0) == GLFW_PRESS
	    || glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		return (0);
    else if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS
		|| glfwGetKey(window, GLFW_KEY_KP_0) == GLFW_PRESS
		|| glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		return (1);
    else if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS
		|| glfwGetKey(window, GLFW_KEY_KP_0) == GLFW_PRESS
		|| glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
		return (2);
    else if (glfwGetKey(window, GLFW_KEY_0) == GLFW_PRESS
		|| glfwGetKey(window, GLFW_KEY_KP_0) == GLFW_PRESS
		|| glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
		return (3);
	else
		return (tex_mode);
}
