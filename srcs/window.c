/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:02:59 by gboudrie          #+#    #+#             */
/*   Updated: 2020/03/05 18:30:50 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>

void		error_callback(int error, const char *description)
{
    puts(description);
}

GLFWwindow	*init_window()
{
    if (!glfwInit())
    {
        puts("Failed to initialize GLFW");
        return(NULL);
    }
    else
    {
        glfwSetErrorCallback(error_callback);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
        glfwWindowHint(GLFW_SCALE_TO_MONITOR, GLFW_TRUE);
        GLFWwindow  *window = glfwCreateWindow(640, 480, "scop", NULL, NULL);
        if (!window)
        {
            puts("Failed to initialize a window");
            return(NULL);
        }
        else
        {
            gladLoadGL(glfwGetProcAddress);
            glfwMakeContextCurrent(window);
            return(window);
        }
    }
}

void		set_callbacks(GLFWwindow *window)
{
	glfwSetKeyCallback(window, key_callback);
} 
