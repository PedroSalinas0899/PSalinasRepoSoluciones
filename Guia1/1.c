#include <stdio.h>
int main (){
	printf("\n Sistema de entrega de numero de matricula y promedio semestral del alumno Pedro Salinas.");
	printf("\n Para poder proseguir, porfavor ingrese las 3 calificaciones que obtuvo en el semestre.");
	float c1,c2,c3;
	printf("\n Calificacion 1:");
	scanf("%f",&c1);
	printf("\n Calificacion 2:");
	scanf("%f",&c2);
	printf("\n Calificacion 3:");
	scanf("%f",&c3);
	float resultado,promedio_semestral;
	resultado=c1+c2+c3;
	promedio_semestral=resultado/3;
	int numero_de_matricula;
	numero_de_matricula = 2018430022;
	printf("\n Su numero de matricula es:%d",numero_de_matricula);
	printf("\n Y su promedio semestral es:%.2f",promedio_semestral);
	return 0;
}
