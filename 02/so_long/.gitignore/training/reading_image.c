#include "mlx/mlx.h"
#include <stdio.h>

int	main()
{
	void	*mlx;
	void	*img;
	void	*win;
	char	*relative_path = "includes/id_picture.xpm";
	int	width;
	int	height;

	mlx = mlx_init();
	img = mlx_xpm_file_to_image(mlx, relative_path, &width, &height);
	win = mlx_new_window(mlx, width, height, "salut");
	mlx_put_image_to_window(mlx, win, img, 0, 0);
	mlx_loop(mlx);
	return (0);
}
