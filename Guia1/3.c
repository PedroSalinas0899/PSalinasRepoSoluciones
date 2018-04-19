#include <stdio.h>
#include <math.h>
int main (){
	printf("\n Calculadora de raiz de hipotenusa de un triagunlo rectangulo.");
	printf("\n Introduzca los catetos del triagunlo rectangulo.");
	float cateto_1,cateto_2;
	printf("\n Cateto 1:");
	scanf("%f",&cateto_1);
	printf("\n Cateto 2:");
	scanf("%f",&cateto_2);
	float h,hipotenusa;
	h=cateto_1*cateto_1+cateto_2*cateto_2;
	hipotenusa=pow(h,0.5);
	printf("\n La hipotenusa de su cuadrado rectangulo es:%.2f",hipotenusa);
	return 0;
}
