#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	 int x=4,y=5;
	 
	 int matriz[x][y];
	 
	 for(int i=0;i<x;i++){
			for(int j=0;j<y;j++){
				printf("Ingrese el dato %d de la fila %d:\n",j+1,i+1);
				scanf("%d",&matriz[i][j]);
		}
		system("clear");
	}
	system("clear");
	
	for (int i=0;i<x;i++){
		for(int j=0;j<y;j++){
				printf("%d,",matriz[i][j]);
	
		}
		printf("\n");
	}
	printf("\n");
	
	int vector[x];
	int aux=0;
	
	for(int i=0;i<x;i++){
		for (int j=0;j<y;j++){
			aux = matriz[i][j]+ aux;
				vector[i] = aux;
			}
			aux = 0;
		}
	for (int i=0;i<x;i++){
				printf("%d,",vector[i]);
	
		}
		printf("\n");
	return 0;
	}
	


	
