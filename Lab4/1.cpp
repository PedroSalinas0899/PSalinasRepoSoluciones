//Iniciar el programa.
//Declarar las variables  que utilizaremos; el numero invertido sera 0.
//Pedir al usuario que ingrese el numero a invertir.
//ingresar un while para que recorra el numero ingresado el cual debe ser mayor que 0.
//Dentro de el while ingresaremos la operacion de cada variable.
//El while calculara el resto de el numero y luego el numero se dividira por 10 para que entre denuevo en el bucle, hasta que el numero sea 0
//Pondremos un printf de resto dentro del while para que vaya imprimiendo cada resto, de manera que quede como si el numero inicial se diece 
//vuelta.
//Finalizaremos el while y finalizaremos el programa.
#include <stdio.h>
	
int main (){
	printf("..:::::Invertidor de numeros enteros mayores que 0:::...\n");
	int numero,resto;
	printf("Ingrese el numero entero que quiera invetir:\n");
	scanf("%d",&numero);
	printf("El numero invertido es:\n");
	while (numero>0){
		resto=numero%10;
		numero=numero/10;
		printf("%d",resto);
	}
	return 0;
}
