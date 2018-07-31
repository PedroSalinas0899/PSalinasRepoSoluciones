#include <stdio.h>
#include <stdlib.h>

int main(){
	 int x,y;
	 printf("Indique el numero de filas que quiere:");
	 scanf("%d",&x);
	 printf("Indique el numero de columnas que quiere:");
	 scanf("%d",&y);
	 
	 system("clear");
	 
	 int matrizA[x][y];
	 
	 for(int i=0;i<x;i++){
		 for(int j=0;j<y;j++){
				int f;
				printf("Ingrese los %d valores de la fila %d:\n",x,i+1);
				scanf("%d",&f);
				matrizA[i][j]=f;	 
				f=0;
				system("clear");	 
			}
		}
		
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			printf("%d-",matrizA[i][j]);
	 }
	 printf("\n");
	}
	int contador=0;
	int aux=0;
	int total=0;
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			contador=matrizA[i][j];
			aux=contador+aux;
		}
		printf("La suma de la fila %d  es: %d \n",i+1,aux);
		aux=0;
		contador=0;
	}
	
	int contador2=0;
	int aux2=0;
	int total2=0;
	for(int j=0;j<y;j++){
		for(int i=0;i<x;i++){
			contador2=matrizA[i][j];
			aux2=contador2+aux2;
		}
		printf("La suma de la columna %d  es: %d \n",j+1,aux2);
		aux2=0;
		contador2=0;
	}
	
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			total= total + matrizA[i][j];
		}
	}
	
	printf("La suma total de las filas es : %d\n",total);

	for(int j=0;j<y;j++){
		for(int i=0;i<x;i++){
			total2= total2 + matrizA[i][j];
		}
	}
	
	printf("La suma total de las columnas es : %d",total2);
	
	return 0;
}
