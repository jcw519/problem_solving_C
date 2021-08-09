#include <math.h>

#define MAX 360
#define MIN 0
#define STEP 5

int main(){ 
	
	double pi = 4.0 * atan(1.0);
	
	for(int degree = MIN; degree <= MAX; degree+=STEP){
		double r = pi * (degree/180.0);
		double v = sin(r);
		printf("%d     %f\n",degree, v);
	}
	
	getchar();
}
