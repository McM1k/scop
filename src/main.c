/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:52:12 by gboudrie          #+#    #+#             */
/*   Updated: 2020/09/15 18:15:30 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int		main(int ac, char **av)
{
	GLFWwindow		*window;
	t_obj			*obj;
	unsigned int	shader_program;
	unsigned int	vao;

	if (ac != 2)
		return (-1);
	window = init_window();
	if (!window)
		return (-1);
	if (!(obj = get_obj(av[1])))
		return (-1);
	shader_program = init_shader_program();
	init_tex(shader_program);
	vao = init_vao(obj);
	ft_loop(window, vao, obj, shader_program);
	free_obj(obj);
	glfwTerminate();
	return (0);
}
