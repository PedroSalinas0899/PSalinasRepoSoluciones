#include <stdio.h>
int main(){
	printf("\n Calculador de sueldo total mensual, inclluyendo las comisiones semanales(en CLP).");
	printf("\n La comision semanal es 7%%");
	float s;
	printf("\n Introduzca su sueldo mensual en CLP:");
	scanf("%f",&s);
	float stotal,c,totalc;
	c=0.07;
	totalc=c*s;
	stotal=s+totalc;
	printf("\n Al final del mes se resibe en CLP:%.3f",stotal);
	printf("\n Al finalizar el mes, lo que correspondio a las comisiones en CLP es de:%.3f",totalc);
	return 0;
}
