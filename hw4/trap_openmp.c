#include<stdio.h>
#include <omp.h>

#define a 2.0
#define b 127.0
#define n 100000000

double f(double x){
	return x*x+2*x-4;
} 

int main(){
	double h,approx,t1,t2;
	int i;
	t1=omp_get_wtime();
	h=(b-a)/n;
	approx=(f(a)+f(b))/2.0;
#	pragma omp parallel for num_threads(2) reduction(+: approx)
	for (i=1;i<n;i++)
		approx+=f(a+i*h);
	approx=h*approx;
	t2=omp_get_wtime();
	printf("The integral estimate from %f to %f is %f and took %f seconds\n",a,b,approx,t2-t1);
	return 0;
}


