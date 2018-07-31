#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
	 srand(time(0));
	 int x=7,y=24;
	 
	 int matriz[x][y];
	 	 
	 for(int i=0;i<x;i++){
			for(int j=0;j<y;j++){
				matriz[i][j] = (rand()%40)+12;
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
	
	

			for(int i=0;i<x;i++){
					int aux;
					for (int k=1;k<y;k++){
						int l;
						l=k;
						aux=matriz[i][k];
						while (l > 0 && aux < matriz[i][l-1]){
							matriz[i][l]=matriz[i][l-1];
							l--;
						}
						matriz[i][l]=aux;
					}	
				}

	printf("Las temperaturas ordenadas son:\n");
	
	for (int i=0;i<x;i++){
		for(int j=0;j<y;j++){
				printf("%d,",matriz[i][j]);
	
		}
		printf("\n");
	}
	printf("\n");

	for (int i=0;i<x;i++){
				printf("La temperatura minima del dia %d es:%d\n",i+1,matriz[i][0]);
				printf("La temperatura maxima del dia %d es:%d\n",i+1,matriz[i][23]);
		}
		printf("\n");
	printf("\n");
	
	
	int temperaturas[168];
	int k = 0;	
		for(int i=0;i<x;i++){
			for(int j=0;j<y;j++){
			temperaturas[k]=matriz[i][j];
			k++;
		}
	}
	
	int aux;
	for (int i=1;i<k;i++){
		int j=i;
		aux=temperaturas[i];
		while (j > 0 && aux < temperaturas[j-1]){
			temperaturas[j]=temperaturas[j-1];
			j--;
		}
		temperaturas[j]=aux;
	}
	
	printf("La temperatura mas baja de la semana es %d y la mas alta es %d\n",temperaturas[0],temperaturas[167]);

	int suma;
	int promedio; 
	
	for (int i=0;i<k;i++){
				suma = suma + temperaturas[i];
		}
	promedio = suma / 168;
	printf("El promedio de la temperatura de la semana es: %d\n",promedio);
	
	int sumadias=0;
	int promediodias=0;
	
	for (int i=0;i<x;i++){
			for (int j=0;j<y;j++){
				sumadias=sumadias + matriz[i][j];
				promediodias=sumadias/24;
					}
			if(promediodias>30){
				printf("El dia %d la media de la temperatura fue superior a 30.\n",i+1);
			}
			printf("El promedio de la temperatura del dia %d es:%d\n",i+1,promediodias);
			sumadias=0;
			promediodias=0;
		}
	
		return 0;
}	

