/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/09 08:17:02 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/15 11:37:29 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fdf.h"



void rotate_x(t_data *vars)
{
	int i;
	static double x = M_PI_2;
	i = 0;
	while (vars -> xyz_m[i])
	{
		int y = vars -> xyz_old[i][2];
		vars -> xyz_m[i][1] = vars -> xyz_old[i][1];
		vars -> xyz_m[i][2] = y * cos(x)  +  vars -> xyz_old[i][3] * sin(x);
		vars -> xyz_m[i][3] = (-y * sin(x) + vars -> xyz_old[i][3] * cos(x));
		i++;
	}
	x = x + M_PI_2;
}

void rotate_y(t_data *vars)
{
	int i;
	static double y = M_PI;
	i = 0;
	while (i < vars->n_points)
	{
		int a = vars -> xyz_old[i][1];
		vars -> xyz_m[i][1] = a * cos(y) + vars -> xyz_m[i][3] * sin(y);
		vars -> xyz_m[i][2] = vars -> xyz_old[i][2];
		vars -> xyz_m[i][3] = (-a * sin(y) + vars -> xyz_old[i][3] * cos(y));
		i++;
	}
	y = y + M_PI;
}
void rotate_z(t_data *vars)
{
	int i;
	static double z = M_PI_2;
	i = 0;
	while (i < vars->n_points)
	{
		int x = vars -> xyz_old[i][1];
		vars -> xyz_m[i][0] = vars -> xyz_old[i][0];
		vars -> xyz_m[i][1] = x * cos(z) - vars -> xyz_old[i][2] * sin(z);
		vars -> xyz_m[i][2] = x * sin(z)  +  vars -> xyz_old[i][2] * cos(z);
		vars -> xyz_m[i][3] =  vars -> xyz_old[i][3];
		i++;
	}
	z = z + M_PI_2; 
}