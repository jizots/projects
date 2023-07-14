#include "fdf.h"
#include <mlx.h>
#include <math.h>
#include <stdio.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}



int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	double	i;
	double from_x = 0, from_y = 500;
	double x = 0, y = 0;
	double radian;
	double radius;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "Hello world!");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	// int theta = 0;//曲線を描画する
	// while (theta < 1000)
	// {
	// 	radian = theta * (M_PI / 180);
	// 	my_mlx_pixel_put(&img, theta, from_y + (sin(radian) * 100), 0x00FF0000);
	// 	theta++;
	// }


	// radius = ft_hypotenus_of_pytgrs(x - from_x, y - from_y);//円を描画する
	// printf("radius:%f\n", radius);
	// radian = atan((y - from_y) / (x - from_x));
	// printf("radian:%f\n", radian);
	// while (radius >= 0)//円を描画する
	// {
	// 	my_mlx_pixel_put(&img, from_x + (radius * cos(radian)), from_y + (radius * sin(radian)), 0x00FF0000 + i);
	// 	radius--;
	// }

	// while (theta < 360)//円を描画する
	// {
	// 	radian = theta * (M_PI / 180);
	// 	my_mlx_pixel_put(&img, offset_x + (radius * cos(radian)), offset_y + (radius * sin(radian)), 0x00FF0000 + i);
	// 	theta += 0.5;
	// }

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}

//cc -I /usr/local/include tes.c '/Users/sotanaka/fdf-0/minilibx_macos/libmlx.a'  -L /usr/local/lib -lmlx -framework OpenGL -framework AppKit

