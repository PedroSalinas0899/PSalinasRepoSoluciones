//paso1:poner un procedimiento que hara una parte de la estructura del termometro.
//paso2: utilizaremos un for para definir los numeros que estaran en grande en el termometro.
//paso3: haremos uso de varios if/else if para que los espacios entre los numeros queden bien en el termometro.
//paso4: al cerrar todo los if pondremos un printf de los "|" que estaran debajo de los numeros grandes para que se vea mejor.
//paso5: cerraremos el procedimiento.
//paso6: haremos uso de una funcion para poder mostrar la temperatura que se introduce en la estructura del termometro.
//paso7: en la funcion le pediremos al usuario que introduzca la temperatura que quiera, entre 0 o 50, ya que este es el tamaño dle termometro.
//paso8: haremos uso del procedimiento que hicimos para la estructura del termometro.
//paso9: y pondremos un for para poner tantos "-" como temperatura haya introducido el usuario.
//paso10: a esa temperatura le restaremos 1 para poner un "*" justo donde marca la temperatura y se pueda ver mejor en el termometro.
//paso11: finalizaremos la funcion y retornaremos el valor de la temperatura.
//paso12: iniciaremos el programa llamando a la funcion main y haremos uso de la funcion que tenia el procedimiento.
//paso13: finalizar el programa.

#include <stdio.h>

void termometro(){
	int largo;
	for (largo=0;largo<=50;largo=largo+10){
		if (largo==0){
			printf("%d\t  ",largo);
		}
		else if (largo==10){
			printf("%d\t    ",largo);
			
		}
		else if (largo==20){
			printf("%d\t      ",largo);
			
		}
		else if (largo==30){
			printf("%d\t",largo);
			
		}
		else if (largo==40){
			printf("%d\t  ",largo);
			
		}
		else if (largo==50){
			printf("%d\t ",largo);
			
		}
	}
	printf("\n|\t  |\t    |\t      |\t        |\t  |\n");	

	
	
}

int temperatura(){
	int i,temp;
	printf("Ingrese la temperatura en grados celcius entre 0 a 50 (tamaño del termometro):\n");
	scanf("%d",&temp);
	termometro();
	temp=temp-1;
	for (i=0;i<=temp;i++){
		printf("-");
	}
	printf("*");
	return temp;
}
	
	
	
int main (){
	printf("...:::::Termometro::::::...\n");
	printf("El termometro marca la temperatura del 0 al 50 en grados celcius.\n");
	temperatura();
	return 0;
}

