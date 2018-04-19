#include <stdio.h>
int main(){
	printf("\n Datos de un dinosaurio.");
	char nombre[6000000];
	float l,p;
	printf("\n Introduzca el nombre del dinosaurio:");
	scanf("%s",&nombre[6000000]);
	printf("\n Introduzca el peso del dinosaurio en libras:");
	scanf("%f",&l);
	printf("\n Introduzca la longitud del dinosaurio en pies:");
	scanf("%f",&p);
	float k,m;
	k=l*0.45;
	m=p*0.3048;
	printf("\n El nombre del dinosaurio es:%s",&nombre[6000000]);
	printf("\n El peso del dinosaurio en kilogramos es:%.4f",k);
	printf("\n La longitud del dinosaurio en metros es:%.4f",m);
	return 0;
}
