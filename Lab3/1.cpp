//paso1: declarar la funcion que se utilizara para hacer funcionar el programa.
//paso2: introducir las variables para poner un for.
//paso3: en el for se pone como variable el dia que va a ser igual a 1, que sea menor o igual a 6 y que aumente de 1 en 1.
//paso4: pedirle al usuario que introduzca las horas de trabajo de cada dia.
//paso5: poner la variable contador que vaya sumando las horas de cada dia.
//paso6: finalizar la funcion y pedir que retorne el valor de contador que son las horas totales de trabajo.
//paso7: hacer otra funcion en la cual sacaremos la paga total que se le efectuara al trabajador, incluyendo la funcion anterior.
//paso8: definir la operacion para calcular la paga total, imprimir en pantalla este valor y retornar el valor. 
//paso9: iniciar el programa con la funcion main. 
//paso10: hacer uso de la funcion de la paga total.
//paso11: finalizar programa.

#include <stdio.h>

	float horas_totales(){
		int dia=0.0;
		float hora=0.0;
		float contador=0.0;
		for (dia=1.0;dia<=6.0;dia++){
			printf ("Ingrese el numero de horas que trabajo el dia %d:\n",dia);
			scanf("%f",&hora);
			contador=hora+contador;
		}
	return contador;
	}
	
	int  paga_total(){
	float paga_total;
	float horas=horas_totales();
	paga_total=5000*horas;
	printf("La paga total del empleado segun sus horas trabajadas es:%.1f\n",paga_total);
	return paga_total;
}
	
int main (){
	printf("Programa para calcular el sueldo de un empleado.\n");
	printf("La empresa paga 5.000 pesos la hora.\n");
	paga_total();
	return 0;
}
