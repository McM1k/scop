/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 16:16:54 by gboudrie          #+#    #+#             */
/*   Updated: 2020/07/07 11:12:59 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __HEADER_H__
# define __HEADER_H__

# include <glad.h>
# include <GLFW/glfw3.h>
# include <libft/libft.h>

//window.c
GLFWwindow		*init_window();
unsigned int	init_shader_program();

//events.c
void	framebuffer_size_callback(GLFWwindow *window, int width, int height);
void	error_callback(int error, const char *description);
void	key_callback(GLFWwindow *window, int key, int scancode, int action, int mods);
#endif
