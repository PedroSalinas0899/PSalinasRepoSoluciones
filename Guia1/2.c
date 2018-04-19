#include <stdio.h>
int main (){
	printf("\n Calculador de cuadrados y cubos de numeros enteros positivos.");
	int numero;
	printf("\n Ingrese su numero entero positivo:");
	scanf("%d",&numero);
	int cuadrado,cubo;
	cuadrado=numero*numero;
	cubo=cuadrado*numero;
	printf("\n El cuadrado de su numero es:%d",cuadrado);
	printf("\n El cubo de su numero es:%d",cubo);
	return 0;
} 
