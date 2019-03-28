#include <math.h>

#ifndef M_PI
#define M_PI (3.14159265358979323846)
#endif

#define FAC_3  (2*3)
#define FAC_5  (FAC_3*4*5)
#define FAC_7  (FAC_5*6*7)
#define FAC_9  (FAC_7*8*9)
#define FAC_11 (FAC_9*10*11)

/* A simple sin(x) implementation using a Taylor polynomial 
 * and fmod to clamp x to the range [-pi, pi].
 * One day I'll figure out how make an efficient fmod myself.
 */
double my_sin(double x) {
	x = fmod(x, M_PI);	
	
	double x2  = x  * x;
	double x3  = x  * x2;
	double x5  = x3 * x2;
	double x7  = x5 * x2;
	double x9  = x7 * x2;
	double x11 = x9 * x2;
	return x - x3/FAC_3 + x5/FAC_5 - x7/FAC_7 + x9/FAC_9 - x11/FAC_11;
}
