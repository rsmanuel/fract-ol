#ifndef MINITALK_H
# define MINITALK_H

# include "../libft/libft.h"
# include "../minilibx_mms_20200219/mlx.h"

typedef struct s_struct
{
    void *mlx_ptr;
    void *mlx_win;
    int x;
    int y;
    char *fractal;
    char *color;
    int precision;
}       t_struct;

typedef struct s_data 
{
    void *img;
    char *addr;
    int bits_per_pixel;
    int line_length;
    int endian;
}       t_data;

int input_validation(char **str, int argc, t_struct *info);
void validation_fail(void);

#endif
