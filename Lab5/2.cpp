//Iniciamos el programa.
//Se imprime en pantalla que el usuario introduzca un numero.
//Ponemos un bloque de if para ver si el numero es negativo o positivo.
//Y si es positivo se imprime la raiz digital llamando a una funcion que lo calculara.
//Se crea la funcion que calculara la raiz digital separando los numero, sumandolos hasta que de el digito que se necesita.
//Finalizar el programa en la funcion principal main.
//


#include <stdio.h>
int raiz(int numero2){
	if(numero2<=9){
		return numero2;
	}
	else {
		return (raiz((numero2%10) + raiz(numero2/10)));
	}
	return 1;
}

int main(){
	int numero1;
	printf("Introduzca un numero:\n");
	scanf("%d",&numero1);
		if(numero1<0){
		printf("El numero es negativo. \n");
	}
	else {
		printf("EL numero es posiutivo y su raiz digital sera: %d \n", raiz(numero1));
	}
	return 0;
}
