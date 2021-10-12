#include "./includes/fractol.h"


void mlx_pixel_insert(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int main(int argc, char **argv)
{
	t_struct *info;
	t_data *data_img;
	int validation;

	info = malloc(sizeof(t_struct));
	data_img = malloc(sizeof(t_data));
	validation = input_validation(argv, argc, info);
	if (validation == 1)
	{
		info->mlx_ptr = mlx_init();
		data_img->img = mlx_new_image(info->mlx_ptr, info->x, info->y);
		data_img->addr = mlx_get_data_addr(data_img->img, &data_img->bits_per_pixel, &data_img->line_length, &data_img->endian);
		info->mlx_win = mlx_new_window(info->mlx_ptr, info->x, info->y, argv[1]);
		mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, data_img->img, 20, 20);
		mlx_loop(info->mlx_ptr);
	}
	else if (validation == -1)
	{
		validation_fail();
		free(info);
		free(data_img);
		exit(EXIT_FAILURE);
	}
}
