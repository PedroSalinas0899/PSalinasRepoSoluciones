#include <stdio.h>
#include <math.h>
int main(){
	printf("\n Evaluador del polinomio p(x)=xxx+2xx+3x+5.");
	float x;
	printf("\n Introduzca su valor de x:");
	scanf("%f",&x);
	float xd;
	xd=pow(x,3)+2*pow(x,2)+3*x+5;
	printf("\n El valor de su polinomio para su valor de x es:%f",xd);
	return 0;
}
