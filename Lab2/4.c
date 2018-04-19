//paso1:iniciar programa.
//paso2:introducir las variables de el puntaje, y los goles que marcaran cada 1 de los 2 equipos, establecemos el puntaje en 0.
//paso3:preguntamos al usuario el marcador de la fecha 1,2,3,4 y 5
//paso4:introducir un if con 3 opciones para cada fecha y ver si es que ganaron, empataron o perdieron.
//paso5:en cada if se le sumara 3,1 o 0 dependiendo de el resultado.
//paso6:imprimir en pantalla el total de puntaje de los glorioso botenido en las 5 fechas.
//paso7:finalizar programa.
#include <stdio.h>
int main(){
	printf("Programa para poder calcular los puntos de un equipo:");
	int puntaje,gloriosos,enemigos;
	puntaje=0;
	  
	printf("Ingrese el marcador de la fecha 1.\n");
	printf("Ingrese los goles de los gloriosos:");
	scanf("%d",&gloriosos);
	printf("Ingrese los goles de los enemigos:\n");
	scanf("%d",&enemigos);
	
	 if (gloriosos==enemigos){
		 printf("Los glorioso empataron:\n");
		 puntaje++;
	 }
	 else if (gloriosos<enemigos){
		 printf("Los gloriosos perdieron:\n");
	 }
	 else if (gloriosos>enemigos){
		 printf("Los gloriosos ganaron:\n");
		 puntaje=puntaje+3;
	 }
	 
	 printf("Ingrese el marcador de la fecha 2.\n");
	printf("Ingrese los goles de los gloriosos:\n");
	scanf("%d",&gloriosos);
	printf("Ingrese los goles de los enemigos:\n");
	scanf("%d",&enemigos);
	
	 if (gloriosos==enemigos){
		 printf("Los glorioso empataron:\n");
		 puntaje++;
	 }
	 else if (gloriosos<enemigos){
		 printf("Los gloriosos perdieron:\n");
	 }
	 else if (gloriosos>enemigos){
		 printf("Los gloriosos ganaron:\n");
		 puntaje=puntaje+3;
	 }
	 printf("Ingrese el marcador de la fecha 3.\n");
	printf("Ingrese los goles de los gloriosos:\n");
	scanf("%d",&gloriosos);
	printf("Ingrese los goles de los enemigos:\n");
	scanf("%d",&enemigos);
	
	 if (gloriosos==enemigos){
		 printf("Los glorioso empataron:\n");
		 puntaje++;
	 }
	 else if (gloriosos<enemigos){
		 printf("Los gloriosos perdieron:\n");
	 }
	 else if (gloriosos>enemigos){
		 printf("Los gloriosos ganaron:\n");
		 puntaje=puntaje+3;
	 }
	 printf("Ingrese el marcador de la fecha 4.\n");
	printf("Ingrese los goles de los gloriosos:\n");
	scanf("%d",&gloriosos);
	printf("Ingrese los goles de los enemigos:\n");
	scanf("%d",&enemigos);
	
	 if (gloriosos==enemigos){
		 printf("Los glorioso empataron:\n");
		 puntaje++;
	 }
	 else if (gloriosos<enemigos){
		 printf("Los gloriosos perdieron:\n");
	 }
	 else if (gloriosos>enemigos){
		 printf("Los gloriosos ganaron:\n");
		 puntaje=puntaje+3;
	 }
	 printf("Ingrese el marcador de la fecha 5.\n");
	printf("Ingrese los goles de los gloriosos:\n");
	scanf("%d",&gloriosos);
	printf("Ingrese los goles de los enemigos:\n");
	scanf("%d",&enemigos);
	
	 if (gloriosos==enemigos){
		 printf("Los glorioso empataron:\n");
		 puntaje++;
	 }
	 else if (gloriosos<enemigos){
		 printf("Los gloriosos perdieron:\n");
	 }
	 else if (gloriosos>enemigos){
		 printf("Los gloriosos ganaron:\n");
		 puntaje=puntaje+3;
	 }
	 
	 printf("El puntaje total obtenido por los gloriosos es:%d\n",puntaje);
	return 0;
}
	 
	 
