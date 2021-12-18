#include "mlx/mlx.h"
#include <stdio.h>

int	main()
{
	void	*mlx;
	void	*img;
	void	*win;
	char	*ground_path = "includes/textures/ground.xpm";
	int	width;
	int	height;
	int	x;
	int	y;
	int	map_L;
	int	map_l;

	x = 0;
	y = 0;
	map_L = 16;
	map_l = 12;
	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, ground_path, &width, &height);
	printf("height:	%d\n", height);
	printf("width:	%d\n", width);
	win = mlx_new_window(mlx, width*map_L, height*map_l, "salut");
	while (y < height*map_l)
	{
		while (x < width*map_L)
		{
			mlx_put_image_to_window(mlx, win, img, x, y);
			x += width;
		}
		x = 0;
		y += height;
	}
	mlx_loop(mlx);
	return (0);
}
