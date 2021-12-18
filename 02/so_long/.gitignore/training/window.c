#include "mlx/mlx.h"

int	main()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 1920, 1080, "mlx42");
	mlx_loop(mlx_ptr);
}
