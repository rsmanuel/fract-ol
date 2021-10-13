#include "./includes/fractol.h"

void mlx_pixel_insert(t_data *data, int x, int y, int color)
{
	char *pixel;

	pixel = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)pixel = color;
}

void draw_line(t_data *data_img, float beginX, float endX, float beginY, float endY, int color)
{
	float deltaX;
	float deltaY;
	float len;
	float startX;
	float startY;

	// calculalte 2D direction (len X & len Y)
	deltaX = endX - beginX;
	deltaY = endY - beginY;

	// calculate len of line
	len = sqrt((deltaY * deltaY) + (deltaX * deltaX));

	// starting pixels
	startX = beginX;
	startY = beginY;

	// making the distance between pixel_put smaller
	deltaX = deltaX / len;
	deltaY = deltaY / len;

	while (len > 0)
	{
		mlx_pixel_insert(data_img, startX, startY, color);
		startX = startX + deltaX;
		startY = startY + deltaY;
		len--;
	}
}	

void draw_square(t_data *data_img, float beginX, float beginY, float size, int color)
{
	int i;

	i = 0;
	while (i <= size)
	{
		// drawing lines len = beginX + size, with Y + 1 
		draw_line(data_img, beginX, beginX + size, beginY + i, beginY + i, color);
		i++;
	}
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
		info->mlx_win = mlx_new_window(info->mlx_ptr, info->x, info->y, argv[1]);
		data_img->img = mlx_new_image(info->mlx_ptr, info->x, info->y);
		data_img->addr = mlx_get_data_addr(data_img->img, &data_img->bits_per_pixel, &data_img->line_length, &data_img->endian);
		draw_line(data_img, 0, 100, 0, 200, 0x00FFFFFF);
		draw_square(data_img, 500, 500, 400, 0x0010B981);
		mlx_put_image_to_window(info->mlx_ptr, info->mlx_win, data_img->img, 0, 0);
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
