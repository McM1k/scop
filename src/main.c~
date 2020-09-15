/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <gboudrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 15:52:12 by gboudrie          #+#    #+#             */
/*   Updated: 2020/09/14 19:01:53 by mcm1k            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scop.h"

int     main(int ac, char **av)
{
	if (ac != 2)
		return (-1);
   	GLFWwindow	*window;
	window = init_window();
	if (!window) 
		return(-1);
	t_obj	*obj;
	if (!(obj = get_obj(av[1])))
		return(-1);
	
	unsigned int shaderProgram;
	shaderProgram = init_shader_program();
	init_tex(shaderProgram);
    unsigned int vao;
	vao = init_vao(obj);
	t_vec	cam_pos = set_vec(0.0, 0.0, 1.0, 1.0);
	int		tex_mode;

	t_vec	mix;
	mix = set_vec(1.0, 0.0, 0.0, 0.0);
	tex_mode = 1;
	while(!glfwWindowShouldClose(window))
    {
		tex_mode = change_tex(tex_mode, window);
		mix = update_mix_values(mix, tex_mode);
		cam_pos = move_view(cam_pos, window);
		do_the_mat_stuff(cam_pos, shaderProgram, mix);
		do_the_gl_stuff(window, vao, obj);
    }
 	ft_memdel((void **)&(obj->data));
	ft_memdel((void **)&(obj->indices));
	ft_memdel((void **)&obj);
    glfwTerminate();
    return(0);
}
