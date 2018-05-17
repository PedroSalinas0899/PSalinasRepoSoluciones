//Inciamos el programa.
//Realizamos una funcion que tenga las variables de el numero 1 y el numero2 que seran aleatorios, aparte de las variables para finalizar la votacion y para contrar las veces ganadas,
//perdias, empates y votos no validos.
//Ponemos un while que tenga como condicion 1, para que funcione siempre.
//Dentro de el while pondremos 3 if para determinar las 3 opciones principal, votar por el numero1, por el 2 o no valido.
//Dentro de cada if habran otros if para determinar si se gano, se perdio, se empato o fue no valido tomando en cuenta los valores de los numeros aleatoriosl, tambien habran
//impresiones en pantalla seguidas de un scanf, para que el usuario desida si deja de votar o no con una instruccion de break.
//Luego de que se termine el ciclo while, se pondran en pantalla todos los votos efectuados, si es que fueron ganados, perdiso,empates o no fueron validos.
//Llamar la funcion a la funcion principal y finalizazr programa.
//
//


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int votacion(){
	int numero_1;
	int numero_2;
 
	char finalizar;
	char voto;	
	int ganadas=0;
	int perdidas=0;
	int empates=0;
	int votosnovalidos=0;
	while (1){
			printf("Presione A o a si escoge el numero 1 y presione B o b si escoge el numero 2 :\n");
			scanf(" %c",&voto);
			numero_1=(rand() %10)+1; 
			numero_2=(rand() %10)+1;
		if (voto=='A'|| voto=='a'){
				printf("Usted escogio el numero 1.\n");
				printf("el numero 1 es: %d y el numero 2 es: %d\n",numero_1, numero_2);
				if (numero_1>numero_2){
					printf("USTED GANO!!!\n");
					ganadas++;
				}
				if (numero_1<numero_2){
					printf("USTED PERDIO!!!\n");
					perdidas++;
				}
				if (numero_1==numero_2){
					printf("LOS NUMEROS SON IGUALES.");
					empates++;
				}
				printf("Presione n o N si no quiere seguir jugango:\n");
				scanf(" %c",&finalizar);
					if (finalizar=='n' || finalizar=='N'){
						break;
					}
			}
		else if (voto=='B'|| voto=='b'){
				printf("Usted escogio el numero 2.\n");
				printf("el numero 1 es: %d y el numero 2 es: %d\n",numero_1, numero_2);
				if (numero_1<numero_2){
					printf("USTED GANO!!!\n");
					ganadas++;
				}
				if (numero_1>numero_2){
					printf("USTED PERDIO!!!\n");
					perdidas++;
				}
				if (numero_1==numero_2){
					printf("LOS NUMEROS SON IGUALES.");
				    empates++;
				}
				printf("Presione n o N si no quiere seguir jugango:\n");
				scanf(" %c",&finalizar);
					if (finalizar=='n' || finalizar=='N'){
						break;
					}
			}
		else if (voto!='A'|| voto!='a' || voto!='B'|| voto!='b'){
				printf("Opcion no valida.\n");
				votosnovalidos++;
			}
		
		
		}
	printf("Usted gano %d veces.\n",ganadas);
	printf("Usted perdio %d veces.\n",perdidas);
	printf("Usted empato %d veces.\n",empates);
	printf("Hubo %d votos no validos.\n",votosnovalidos);
	return 1;
	}
	
	
int main(){
	srand (time (0));

	votacion();
	return 0;
}
