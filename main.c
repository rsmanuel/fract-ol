#include "./minilibx_mms_20200219/mlx.h"

int main(void)
{
	void *mlx_ptr;
	void *mlx_win;
	int i;

	i = 0;
	mlx_ptr = mlx_init();
	mlx_win = mlx_new_window(mlx_ptr, 640, 360, "teste");

	mlx_loop(mlx_ptr);
}
