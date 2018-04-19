//paso1:Iniciar programa.
//paso2:Introducir las variables del valor de la prenda, el valor reducido y el del descuento.
//paso3:Imprimir en pantalla que se introduzca el valor de la prenda el CLP.
//paso4:Escribir un if para ver si el valor de la prenda supera los 2500 para aplicarle un descuento del 15%.
//paso5:Escribir un if para ver si el valor de la prenda es menor que 2500 para aplicarle un descuento del 8%.
//paso6:Imprimir en pantalla el valor final de la prenda reducida y el descuento en si.
//paso7:Finalizar programa.

#include <stdio.h>
int main(){
	float valorprenda,valorreducido,descuento;
	printf("Introduzca el valor de su prenda en CLP:\n");
	scanf("%f",&valorprenda);
		if (valorprenda>2500){
			printf("Su traje obtendra un descuento del 15porcentaje.\n");
			valorreducido=valorprenda*0.85;
			descuento=valorprenda-valorreducido;
		}	
		else if (valorprenda<2500){
			printf("Su traje obtendra un descuento del 8porcentaje.\n");
			valorreducido=valorprenda*0.92;
			descuento=valorprenda-valorreducido;
		}
	printf("El valor final de su prenda es:%.2f\n",valorreducido);
	printf("El valor final de su prenda es:%.2f\n",descuento);
}
