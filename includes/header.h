/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:16:54 by gboudrie          #+#    #+#             */
/*   Updated: 2020/07/01 11:56:14 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HEADER_H__
# define __HEADER_H__

# include <glad/glad.h>
# include <GLFW/glfw3.h>

//window.c
void		error_callback(int error, const char *description);
GLFWwindow	*init_window();
void		set_callbacks(GLFWwindow *window);

//events.c
static void key_callback(GLFWwindow *window, int key, int scancode, int action,
						 int mods);


#endif
