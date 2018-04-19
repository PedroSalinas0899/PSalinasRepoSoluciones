#include <stdio.h>
int main(){
	printf("\n Calculadora de segundos apartir de dias:");
	int d;
	printf("\n Introduzca el numero de dias que quiere convertir:");
	scanf("%d",&d);
	int s;
	s=d*86400;
	printf("\n Corresponde a esta cantidad de segundos:%d",s);
	return 0;
}	
