#include "./includes/fractol.h"

/*void zoom(t_struct *info, int button, int x, int y)
{
	
	if (button == 4)
		info->step /= 1.5;
	if (button == 5)
		info->step *= 1.1;
	start_window(info);
}*/

int key_event(int button, t_struct *params)
{
	t_struct *info = params;
	if (button == 53)
	{
		mlx_clear_window(info->mlx_ptr, info->mlx_win);
		exit(EXIT_SUCCESS);
	}
	return (0);
}

/*int mouse_event(int button, int x, int y, t_struct *params)
{
	t_struct *info;

	info = params;
	if (button == 4 || button == 5)
		zoom(info, button, x, y);
	return (0);*/
