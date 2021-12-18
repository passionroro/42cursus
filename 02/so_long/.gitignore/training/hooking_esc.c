#include "mlx/mlx.h"
#include <stdio.h>

typedef struct	s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

int shutdown(int status, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int close(int keycode, t_vars *vars)
{
	if (keycode == 53)
		mlx_hook(vars, 17, 1L<<19, shutdown, vars);
	return (0);
}

int	main()
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "close me :|");
	mlx_hook(vars.win, 17, 1L<<19, shutdown, &vars);
	mlx_hook(vars.win, 2, 1L<<0, close, &vars);
	mlx_loop(vars.mlx);
}
