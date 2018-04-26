//paso1: hacer un funcion para ver que valor tendran las 20 cuotas y el valor final.
//paso2: pondremos todas las variables que usaremos.
//paso3: haremos uso de un for para indicar que los meses van del 1 al 20 y que aumentan de 1 en 1.
//paso4: pondremos la formula que calculara el valor que se debera pagar en cada mes, acompañado de un prinft que lo imprimira en pantalla.
//paso5: cerraremos el for e imprimiremos en pantalla el valor que se debera pagar todos los meses sumado.
//paso6: iniciaremos el programa llamando a la funcion main .
//paso7: llamaremos a la funcion
//paso8: finalizaremos el programa.


#include <stdio.h>

 int cuotas(){
	float pago_mensual=5;
	float mes;
	float contador;
	for(mes=1;mes<=20;mes++){
			pago_mensual=pago_mensual*2;
			contador=contador+pago_mensual;
			printf("El mes %.1f se debe pagar:%.1f\n",mes,pago_mensual);
		}
	printf("El pago total que se debe efuctuar es:%.1f",contador);
	return contador;
	}
			
 int main(){
	 printf("Algoritmo para determinar cuanto se debe pagar un producto en 20 cuotas (mensual y total).\n");
	 cuotas();
	 return 0;	
 }
	 
