//paso1:iniciar programa.
//paso2:introducir las variables para parar de imprimir numero, 
//
//
//paso1:iniciar programa.
//paso2:introducir las 3 variables para poder hacer la piramide.
//paso3:poner un while y poner la condicion de que pare en los numeros del 1 al 9.
//paso4:pedirle al usuario que introduzca el tamaño de la piramide para abajo.
//paso5: cerrar el while y poner un for que tenga como variable n, condicion que sea menor o igual que el tamaño de la piramide 
//y que aumente de 1 en 1, esto para poder hacer la parte de la izquierda de la piramide.

//paso6:abrir otro for en la variable m que va a ser igual que n pero menos 1, como condicion que sea mayor o 
//igual a 1 y que aumente negativamente en 1, esto para poder realizar la parte de la derecha de la piramide

//paso7:cerrar el for y poner un printf con un salto de lineas para que la estructura de la piramide quede bien.
//paso8:cerrar el programa.
#include <stdio.h>
int main(){
	int parar,n,m;
	while(parar<1||parar>9){
		printf("Ingrese el tamaño de la piramide, del 1 al 9:\n");
		scanf("%d",&parar);
	}
	for (n=1; n<=parar;n++){
		for(m=1;m<=n;m++){
			printf("%d",m);
		}
		for(m=n-1;m>=1;m--){
			printf("%d",m);
		}
	printf("\n");
	
	}
	return 0;
}
