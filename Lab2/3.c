//paso1:iniciar el programa.
//paso2:introducir la variable de peso y preguntarsela al usuario.
//paso3:introducir la variable de docis diaria y hacer la formula equivalente.
//paso4: introducir las variables de las gotitas necesarias al dia si es mayor a 1 año o menor y establecer las formulas.
//paso5:imprimir en pantalla la cantidad de gotitas diarias que necesitara si tien mas o menos de 1 año.
//paso6:finalizar programa.
#include <stdio.h>
int main(){
	printf("Programa para calcular la dosis diaria en gotas de medicamento para aliviar el dolor de estomago.\n");
	float peso;
	printf("Introduzca el peso de juanito en kilogramos:\n");
	scanf("%f",&peso);
	float dosis_diaria;
	dosis_diaria=peso*0.2;
	float gotitas,gotitasmenor;
	gotitas=dosis_diaria*2500/500;
	gotitasmenor=gotitas/3;
	printf("Si Juanito tiene mas de  1 año hay que administrarle esta cantidad de gotas al dia para aliviar su dolor de estomago:%.2f\n",gotitas);
	printf("Si Juanito tiene menos de 1 año hay que administrarle esta cantidad de gotas al dia para aliviar su dolor de estomago:%.0f\n",gotitasmenor);
	return 0;
}
	
	
	
	
	
	
