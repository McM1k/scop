/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:02:59 by gboudrie          #+#    #+#             */
/*   Updated: 2020/07/09 14:52:42 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
 
GLFWwindow		*init_window()
{
	glfwSetErrorCallback(error_callback);
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	GLFWwindow* window = glfwCreateWindow(800, 600, "Scop", NULL, NULL);
    if (window == NULL)
    {
        ft_putendl("Failed to create GLFW window");
        glfwTerminate();
        return NULL;
    }
    glfwMakeContextCurrent(window);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        ft_putendl("Failed to initialize GLAD");
        return NULL;
    }
	glViewport(0, 0, 800, 600);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwSetKeyCallback(window, key_callback);
	return window;
}
