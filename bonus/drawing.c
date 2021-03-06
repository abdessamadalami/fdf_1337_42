/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 06:40:26 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/15 09:42:40 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include "fdf.h"

int	ft_strchr_int(const char *str, int c)
{
	const char	*s;
	int			i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return (i);
		i++;
	}	
	return (0);
}

t_point	to_stract(t_data *img, int index, char type)
{
	t_point	ab;

	if (type == 'l')
	{
		ab.x0 = img->xyz_m[index - 1][1];
		ab.y0 = img->xyz_m[index - 1][2];
		ab.color_0 = img -> xyz_m[index - 1][4];
		ab.x1 = img->xyz_m[index][1];
		ab.y1 = img->xyz_m[index][2];
		ab.color_1 = img->xyz_m[index][4];
	}
	if (type == 'c')
	{
		ab.x0 = img-> xyz_m[index][1];
		ab.y0 = img -> xyz_m[index][2];
		ab.color_0 = img -> xyz_m[index][4];
		ab.x1 = img -> xyz_m[index + img -> l_length][1];
		ab.y1 = img -> xyz_m[index + img -> l_length][2];
		ab.color_1 = img -> xyz_m[index + img -> l_length][4];
	}
	return (ab);
}

void	h_v_point(int index, int l_line, int **xyz_m, t_data *img)
{
	t_point	ab;

	if (index > 0 && index % l_line != 0)
	{
		ab = to_stract(img, index, 'l');
		bre_algori(ab, img);
	}
	if (index < img -> n_points - l_line)
	{
		ab = to_stract(img, index, 'c');
		bre_algori(ab, img);
	}
}

void	come_to(int x, int y, t_data *vars)
{
	int			d_x;
	int			d_y;
	static int	i;

	d_x = x - vars->xyz_m[0][1];
	d_y = y - vars->xyz_m[0][2];
	if (i == 0)
	{
		transf_fun(vars, 'x', 200);
		transf_fun(vars, 'y', 200);
	}
	else
	{
		transf_fun(vars, 'x', d_x);
		transf_fun(vars, 'y', d_y);
	}
	i++;
}

void	centr_p(t_data *vars, int x, int y)
{
	int	d_x;
	int	d_y;

	d_x = vars->xyz_m[0][1] - x;
	d_y = vars->xyz_m[0][2] - y;
	printf("dx %d dy %d |n \n", d_x, d_y);
	printf("___________________\n");
	zoom_fun(vars, 1, x, y);
	if (d_x > vars -> screnn.x_length)
		d_x = 0;
	if (d_y > vars -> screnn.y_length)
		d_y = 0;
	transf_fun(vars, 'x', d_x / 10);
	transf_fun(vars, 'y', d_y / 10);
}

int	mouse_up(int button, int x, int y, t_data *vars)
{
	int		img_width;
	int		img_height;

	printf("souri %d \n", button);
	vars -> img = mlx_xpm_file_to_image(vars->mlx,
			"./ds.xpm", &img_width, &img_height);
	if (button == 2)
		z_hook(vars, -1);
	else if (button == 1)
		centr_p(vars, x, y);
	else if (button == 4)
		zoom_fun(vars, -1, x, y);
	else if (button == 5)
		zoom_fun(vars, 1, x, y);
	else if (button == 3)
		come_to(x, y, vars);
	isometric_projection(vars);
	return (0);
}

int	mouse_move(int x, int y, t_data *p)
{
	int	i;
	int	j;

	i = 0;
	while (i < 140)
	{
		j = 0;
		while (j < 140)
		{
			mlx_pixel_put(p->mlx, p->m_win, 1800 + j, 1060 + i, 0);
			mlx_pixel_put(p->mlx, p->m_win, 1800 + j, 1060 + 20 + i, 0);
			j++;
		}
		i++;
	}
	printf("x %d y %d \n", p -> xyz_m[0][1], p -> xyz_m[0][2]);
	mlx_string_put(p->mlx, p->m_win, 1800 - 40, 1060, 0xffffff, "x:");
	mlx_string_put(p->mlx, p->m_win, 1800, 1060, 0xffffff, ft_itoa(x));
	mlx_string_put(p->mlx, p->m_win, 1800 - 40, 1060 + 20, 0xffffff, "y:");
	mlx_string_put(p->mlx, p->m_win, 1800, 1060 + 20, 0xffffff, ft_itoa(y));
	return (0);
}

void	drawing_points(t_data *img)
{
	int	index;

	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
			&img->line_length, &img->endian);
	index = 0;
	while (index < img->n_points)
	{
		if (index > 0 && index % img -> l_length != 0)
			h_v_point(index, img -> l_length, img->xyz_m, img);
		if (index < img-> n_points - img -> l_length)
			h_v_point(index, img -> l_length, img->xyz_m, img);
		index++;
	}
	mlx_put_image_to_window(img->mlx, img->m_win, img->img, 0, 0);
	mlx_key_hook(img->m_win, key_hook, img);
	mlx_hook(img -> m_win, 4, 0L, mouse_up, img);
	mlx_hook(img -> m_win, 5, 0L, mouse_up, img);
	mlx_hook(img -> m_win, 6, 0L, mouse_move, img);
	mlx_loop(img->mlx);
}
