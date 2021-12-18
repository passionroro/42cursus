#include "mlx/mlx.h"
#include <stdio.h>

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

int	render_next_frame(t_vars *vars);

int	main()
{
	t_vars	vars;

	vars.mlx = mlx_init();
	mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	mlx_loop(vars.mlx);
}
