#include "./includes/fractol.h"

int input_validation(char **str, int argc, t_struct *info)
{
    if (argc != 3)
        return (-1);
    else if(argc == 3)
    {
            info->fractal = str[1];
            info->color = str[2];
            return (1);
    }
    return (-1);
}

void validation_fail(void)
{
    ft_putcolor_fd(ANSI_COLOR_RED, "Invalid Arguments\n\n", 1);
	ft_putcolor_fd(ANSI_COLOR_CYAN, "Please use this format: ", 1);
	ft_putcolor_fd(ANSI_COLOR_GREEN, "./fractol <fractal> <color>\n\n", 1);
	ft_putcolor_fd(ANSI_COLOR_CYAN, "Available Arguments:\n\n", 1);
	ft_putcolor_fd(ANSI_COLOR_CYAN, "\tfractal: ", 1);
	ft_putcolor_fd(ANSI_COLOR_RESET, "\t Mandelbrot,  Julia\n", 1);
	ft_putcolor_fd(ANSI_COLOR_CYAN, "\tcolor: ", 1);
	ft_putcolor_fd(ANSI_COLOR_RESET, "\t\t Blue, Red, Green\n", 1);
}
