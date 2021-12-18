#include "../mlx/mlx.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_data *data, int x_start, int y_start, int color, int size)
{
	int	x;
	int	y;
	
	my_mlx_pixel_put(data, x_start, y_start, color);
	my_mlx_pixel_put(data, x_start + size + 1, y_start + size + 1, color);
	x = x_start;
	y = y_start;
	while (x_start++ < size + x)
		my_mlx_pixel_put(data, x_start, y_start, color);
	while (y_start++ < size + y)
		my_mlx_pixel_put(data, x_start, y_start, color);
	x_start = x;
	y_start = y;
	while (y_start++ < size + y)
		my_mlx_pixel_put(data, x_start, y_start, color);
	while (x_start++ < size + x)
		my_mlx_pixel_put(data, x_start, y_start, color);

}

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_data	img;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "mlx42");
	img.img = mlx_new_image(mlx_ptr, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_lenght, &img.endian);
	draw_square(&img, 5, 5, 0x0000FF00, 60);
	mlx_put_image_to_window(mlx_ptr, win_ptr, img.img, 0, 0);
	mlx_loop(mlx_ptr);
}
