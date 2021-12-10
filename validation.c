/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmanuel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 18:22:07 by rmanuel           #+#    #+#             */
/*   Updated: 2021/12/10 18:30:10 by rmanuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fractol.h"

int	input_validation(char **str, int argc)
{
	if (argc < 2 || (str[1][0] != 'M' && str[1][0] != 'J'))
		return (-1);
	if (argc != 3 && str[1][0] == 'M')
		return (-1);
	else if (argc != 4 && str[1][0] == 'J')
		return (-1);
	if (str[1][0] == 'M')
	{
		if (!strcmp(str[2], "blue") || !strcmp(str[2], "red")
			|| !strcmp(str[2], "green") || !strcmp(str[2], "white"))
			return (1);
		return (-1);
	}
	else if (str[1][0] == 'J')
	{
		if (str[2][0] != '1' && str[2][0] != '2')
			return (-1);
		if (!strcmp(str[3], "blue") || !strcmp(str[3], "red")
			|| !strcmp(str[3], "green") || !strcmp(str[3], "white"))
			return (1);
		else
			return (-1);
	}
	return (1);
}

void	validation_fail(void)
{
	ft_putcolor_fd(ANSI_COLOR_RED, "Invalid Arguments\n\n", 1);
	ft_putcolor_fd(ANSI_COLOR_CYAN, "Please use this format: ", 1);
	ft_putcolor_fd(ANSI_COLOR_GREEN, "./fractol <fractal> <option", 1);
	ft_putcolor_ds(ANSI_COLOR_GREEN, " (only julia set)> <color>\n\n", 1);
	ft_putcolor_fd(ANSI_COLOR_CYAN, "Available Arguments:\n\n", 1);
	ft_putcolor_fd(ANSI_COLOR_CYAN, "\tfractal: ", 1);
	ft_putcolor_fd(ANSI_COLOR_RESET, "\t 'M' -> Mandelbrot, 'J' -> Julia\n", 1);
	ft_putcolor_fd(ANSI_COLOR_CYAN, "\tJulia Set option: ", 1);
	ft_putcolor_fd(ANSI_COLOR_RESET, "\t '1' -> option 1, '2' -> option 2\n", 1);
	ft_putcolor_fd(ANSI_COLOR_CYAN, "\tcolor: ", 1);
	ft_putcolor_fd(ANSI_COLOR_RESET, "\t\t blue, red, green, white\n", 1);
}
