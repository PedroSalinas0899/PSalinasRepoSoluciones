#include <stdio.h>
int main (){
	float galones;
	printf("\n Introduzca la cantidad de gasolina surtida en galones:");
	scanf("%f",&galones);
	float litros;
	litros=galones*3.785;
	printf("\n La catidad de gasolina surtida en litros es:%.3f",litros);
	float precio;
	precio=litros*820;
	printf("\n El precio total de la gasolina surtida en CLP es:%.0f",precio);
	return 0;
}
	
