#include <mlx.h>
#include <stdio.h>
#include <stdlib.h>
#include "libft.h"
#include <math.h>
// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// 	int		x0;
// 	int		y0;
// }				t_vars;

// int	key_hook(int keycode, t_vars *vars)
// {
// 	static int i;
	
	
// 	printf(" x %d___ y %d %d \n",vars -> x0, vars -> y0, keycode );
// 	mlx_string_put(vars -> mlx,vars -> win, vars -> x0, vars -> y0, 0,"3");
// 	mlx_string_put(vars -> mlx,vars -> win, vars -> x0, vars -> y0, 0,"3");
// 	// mlx_string_put(vars -> mlx,vars -> win, vars -> x0, vars -> y0, 0x00000,"3");
// 	// mlx_string_put(vars -> mlx,vars -> win, vars -> x0, vars -> y0, 0x00000,"3");
// 	if (keycode == 69)
// 	{
// 		vars -> x0 = vars -> x0 + 30 ;
// 		vars -> y0 = vars -> y0 + 30 ;
// 	}
// 	if (keycode == 78)
// 	{
// 		vars -> x0 = vars -> x0 - 30;
// 		vars -> y0 = vars -> y0 - 30;
// 	}
// 	mlx_string_put(vars -> mlx,vars -> win, vars -> x0, vars -> y0, 0x1cc738,"3");
// 	return (0);
// }


// int mouse_hook(int keycode, t_vars *vars)
// {
//     static int i;
// 	// int c = vars->x0;
// 	// printf("key_hook! %d  \n",c);
// 	//#000000
// 	mlx_string_put(vars -> mlx,vars -> win, 60 , 63, 0x1cc738,"aidjf");
	
// 	if (keycode == 5)
// 	{
// 		printf("key_hook 5 ! : %d %d \n",keycode,i);
		
// 		// segfoult problem 
// 		i = i + 1;
// 	}
// 	if (keycode == 4)
// 	{
// 		i--;
// 		printf("key_hook 4 ! : %d %d \n",keycode,i);
// 	}
// 	return (0);
// }


// int		mlx_mouse_get_pos(void *win_ptr, int *x, int *y)
// {
// 	printf("sdf");
// 	return 0;
// }
// int	ft_strchr_int(const char *str, int c)
// {
// 	const char	*s;
// 	int i;

// 	i = 0;

// 	while (str[i] != '\0')
// 	{
// 		if (str[i] == (unsigned char)c)
// 			return (i);
// 		i++;
// 	}
	
// 			return (0);
// }

// int to_decimal(char *str)
// {
// 	int i;
// 	char c;
// 	int nbr;
// 	int len;
// 	char *hix="0123456789abcdef";
	
// 	i = 0; 
// 	c = 0;
// 	nbr = 0;
// 	if (str[0] == '0' && str[1] == 'x')
// 		str = str + 2;
//  	len = ft_strlen(str) - 1;
// 	while(str[i] != '\0')
// 	{
// 		c =  ft_tolower(str[i]);
// 		nbr = nbr + ft_strchr_int(hix, c) * pow(16, len);
// 		i++;
// 		len--;
// 	}
// 	return 0;
// }
// int	main(void)
// {
// 	t_vars	*vars;
// 	int x0, y0, x1,y1;
// 	char *img;
// 	vars = malloc(sizeof(t_vars));
// 	vars -> x0 = 220;
// 	vars -> y0= 30;
// 	vars -> mlx = mlx_init();
	
// 	//char a = 0xFF0000;
// 	//to_decimal(a);
// 	 int b = 0x810202;
//     // ft_printf("+++ %d ++", b);
// 	// printf(" %x %d %d", a , a, b);// imkn ft_printf t9di lrarad 
// 	img = malloc (640 * 480);
// 	vars -> win = mlx_new_window(vars -> mlx, 640, 480, "Hello world!");
// 	mlx_key_hook(vars -> win, key_hook, vars);
// 	//mlx_key_hook(vars.win, mouse_hook, &vars);
// 	mlx_string_put(vars -> mlx,vars->win,50, 50, 188608, "0");
// 	int i = 0;
// 	printf(" %d ", b);
// 	while(i <=  250)
// 	{
// 		//mlx_string_put(vars -> mlx, vars->win, 50, 50 + 2 + i, b, "df");
// 		//b--;
// 		img[i] = (char)b;
// 		i++;
// 	}
// 	printf("(<%d>)",b);

// // mlx_mouse_hook(vars -> win,  mouse_hook, vars);
// //	func_text(&vars);
// //	mlx_mouse_hook(vars.win, mlx_mouse_move, &vars);
// 	//mlx_mouse_move(vars.win, 50, 50);
// 	mlx_loop(vars -> mlx);
// }
#include <mlx.h>

typedef struct	s_data {

	void	*img;
	char	*addr;
	void	*mlx;
	void	*mlx_win;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_rgb {
	float		d_r;
	float		d_g;
	float		d_b;
}				t_rgb;

void	my_mlx_pixel(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
void  black_baground(t_data *vars)
{
	int index;
	int j;

	index = 0;
	j = 0;
	while (index < 1920)
	{ 
		j = 0;
		while(j < 1080)
		{
			mlx_pixel_put(vars->mlx,vars->mlx_win, index,j,0x810202);
			j++;
		}
		index++;
	}
}

int	key_hook(int keycode, t_data *vars)
{
	static int i;
	t_data	img;

		
	if (keycode == 53)
		exit(0);
	if (keycode == 69)
	{
		black_baground(vars);
		//	mlx_pixel_put(vars->mlx,vars->mlx_win, 50 + i,i,0x810202);
	
	}
		// my_mlx_pixel(vars, 5 + i, 5 + i, 0x810202);
		// my_mlx_pixel(vars, 5 + i + 300, 5 + i + 120, 0x810202);
		//u must change this rabish code
		// vars -> x_y_z_matrix = vars ->x_y_z_old;
		// isometric_projection(vars -> x_y_z_old ,vars -> line_length , vars -> n_points,vars);
		// drawing_points(vars -> x_y_z_old , vars -> line_length , vars -> n_points,vars);
		//mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars -> img, 0, 0);
	
	//printf(" %d \n",keycode); // + == 69 - = 78
	return (0);
}

 t_rgb get_deffrent(int color,int color2)
 {
	t_rgb a;

	a.d_r = ((float)((color2/(256 * 256))) -  (color/(256 * 256))) /408;
	a.d_g = ((float)(((color2/ 256) % 256)) - ((color/256) % 256)) /408;
	a.d_b = ((float)((color2 % 256)) - (color % 256)) /408; //diffent
	printf("%f %f %f \n",a.d_b,a.d_g,a.d_r);
	return a;
 }

void get_color(int *color, t_rgb d)
{
	float r,g,b;
	r = (*color/(256 * 256)) + d.d_r;
	g = ((*color/256) % 256) + d.d_g;
	b = (*color % 256) + d.d_b;
//	printf(" %f %f %f  d  %f %f %f \n",r,g,b,d.d_r,d.d_g,d.d_b);
	*color = 256 * 256 * r + 256 * g + b;
}



int	main(void)
{
	
	t_data	img;
	t_rgb d_color;

	img.mlx = mlx_init();
	img.mlx_win = mlx_new_window(img.mlx, 1920, 1080, "Hello world!");
	img.img = mlx_new_image(img.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	int i = 0;
	//c1 add 3 colum to array for rgb color and function to convert rgb to hexa
	//c2 convert color to hexa and get rgb and make the coler and put it to 


	
	int color = 0xffffff;
	int color1 = 0x004bbd;
	d_color = get_deffrent(color,color1);
	printf("%f %f %f \n",d_color.d_r,d_color.d_g,d_color.d_b);
	// 256 * 256 * r + 256 * g + b
	//printf(" %f ", (256 * 256) * -0.507157 * 489 -0.521472 * 489 * 256 - 0.521472 * 489);
	while (i < 408)
	{
		my_mlx_pixel(&img, 5 + i, 5 + i, color);
		my_mlx_pixel(&img, 5 + i + 30, 5 + i + 20, color);
		get_color(&color,d_color);
		//color1 = color1 - 339967;
		//printf(" %d \n",color1);
		i++;
	}
	printf("%d",color);

	mlx_key_hook(img.mlx_win, key_hook, &img);
	mlx_put_image_to_window(img.mlx, img.mlx_win, img.img, 0, 0);
	mlx_loop(img.mlx);
}
