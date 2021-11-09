#include "./includes/fractol.h"

// ./fractol <fractal> [x] [y] <color>
int input_validation(char **str, int argc, t_struct *info)
{
    if (argc != 5)
        return (-1);
    else if(argc == 5 && !ft_strncmp(str[1], "Mandelbrot", 10))
    {
        if ((ft_atoi(str[2]) <= 3000 && ft_atoi(str[2]) >= 0) && (ft_atoi(str[3]) <= 3000 && ft_atoi(str[3]) >= 0))
        {
            info->x = ft_atoi(str[2]);
            info->y = ft_atoi(str[3]);
            info->fractal = str[1];
            info->color = str[4];
            return (1);
        }
        else
            return (-1);
    }
    else 
    {
        return (-1);
    }
    return (0);
}

void validation_fail(void)
{
    ft_putcolor_fd(ANSI_COLOR_RED, "Invalid Arguments\n\n", 1);
	ft_putcolor_fd(ANSI_COLOR_CYAN, "Please use this format: ", 1);
	ft_putcolor_fd(ANSI_COLOR_GREEN, "./fractol <fractal> <x> <y> <color>\n\n", 1);
	ft_putcolor_fd(ANSI_COLOR_CYAN, "Available Arguments:\n\n", 1);
	ft_putcolor_fd(ANSI_COLOR_CYAN, "\tfractal: ", 1);
	ft_putcolor_fd(ANSI_COLOR_RESET, "\t Mandelbrot,  Julia\n", 1);
	ft_putcolor_fd(ANSI_COLOR_CYAN, "\tx: ", 1);
	ft_putcolor_fd(ANSI_COLOR_RESET, "\t\t Window width in pixels (ex: 1920)\n", 1);
	ft_putcolor_fd(ANSI_COLOR_CYAN, "\ty: ", 1);
	ft_putcolor_fd(ANSI_COLOR_RESET, "\t\t Window heigth in pixels (ex: 1080)\n", 1);
	ft_putcolor_fd(ANSI_COLOR_CYAN, "\tcolor: ", 1);
	ft_putcolor_fd(ANSI_COLOR_RESET, "\t\t Blue, Red, Green\n", 1);
}
