#include "fractol.h"

int		iterate_julia(t_fractol *fractol)
{
	int			iteration;
	t_complex	z;

	iteration = 0;
	z = init_complex(fractol->c.re, fractol->c.im);
	while (pow(z.re, 2.0) + pow(z.im, 2.0) <= 4
		&& iteration < fractol->max_iteration)
	{
		z = init_complex(
			pow(z.re, 2.0) - pow(z.im, 2.0) + fractol->k.re,
			2.0 * z.re * z.im + fractol->k.im);
		iteration++;
	}
	return (iteration);
}
