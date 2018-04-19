#include <stdio.h>
int main (){
	printf("\n Calculador de superficie y perimetro de rectangulos.");
	printf("\n Para continuar introduzca la base y la altura del rectangulo.");
	float base,altura;
	printf("\n Base:");
	scanf("%f",&base);
	printf("\n Altura:");
	scanf("%f",&altura);
	float superficie,perimetro;
	superficie=base*altura;
	perimetro=2*(base+altura);
	printf("\n La superficie del rectangulo es:%.3f",superficie);
	printf("\n El perimetro del rectangulo es:%.3f",perimetro);
	return 0;
}
