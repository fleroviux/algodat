#include <math.h>

/**
 * Square root function based on Newton's method:
 *    https://en.wikipedia.org/wiki/Newton%27s_method
 * First we define an error function, where x is the current estimation for sqrt(n).
 *    error(x, n) = x² - n
 * For x=sqrt(n) error(x, n) will be 0.
 * Following the tangent we can then get a better estimation in each iteration.
 */
double my_sqrt(double n) {
	if (n < 0) return NAN;
	
	double x = n*0.5;
	double square = x * x;
	double error = square - n;

	do {
		x = x - error/(2.0*x);
		square = x*x;
		error = square - n;
	} while (error > 0.000001 || error < -0.000001);

	return x;
}
