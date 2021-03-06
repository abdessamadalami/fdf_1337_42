/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_fun.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-oual <ael-oual@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 16:44:37 by ael-oual          #+#    #+#             */
/*   Updated: 2022/04/15 07:44:05 by ael-oual         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include"libft.h"
#include "fdf.h"

void print_matrix(int **xyz_m)
{
	int i;
	i = 0;
	while(xyz_m[i] != 0)
	{
		printf(" index  %d x %d y %d  z  %d color %d  \n",xyz_m[i][0],xyz_m[i][1],xyz_m[i][2],xyz_m[i][3] ,xyz_m[i][4]);
		i++;
	}
}

int ft_strlen_d(char **arr_split)
{
	int index;

	index = 0;
	while(arr_split[index] != 0)
		index++;
	return index;
}

void	my_mlx_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

// void plotLine(int x0, int y0, int x1, int y1)
int *bre_algori(t_point ab, int color ,t_data *img)
  { 
	static int index;
	int dx;
	int sx ;
	int dy;
	int sy;
	int error;
	
	dx = abs(ab.x1 - ab.x0);
    sx = (ab.x0 < ab.x1) ? 1 : -1;
    dy = -abs(ab.y1 - ab.y0);
   	sy = (ab.y0 < ab.y1) ? 1 : -1;
    error = dx + dy;
    while(1)
    {   
		my_mlx_pixel(img, ab.x0, ab.y0, color);
		if( ab.x0 == ab.x1 && y0 == y1)
			break;
		int e2 = 2 * error;
		if (e2 >= dy)
			{ 
		    	if (ab.x0 == ab.x1)
					break;
				error = error + dy;
				ab.x0 = ab.x0 + sx;
			}
		if (e2 <= dx)
			{
				if (y0 == y1)
					break;
				error = error + dx;
				ab.y0 = ab.y0 + sy;
			}
		}
		return 0;
	}

void del(void *ptr)
{
	 free(ptr);
}

void print_f(char **xyz_m)
{
	int i = 0;
	printf(" split of content \n");
	while(xyz_m[i])
	{
		printf(" %s ",xyz_m[i]);
		i++;
	}
}

void	free_function(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}