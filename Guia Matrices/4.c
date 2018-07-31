#include <stdio.h>
#include <stdlib.h>

int main(){
	 int x,y;
	 printf("Indique el numero de filas que quiere:");
	 scanf("%d",&x);
	 printf("Indique el numero de columnas que quiere:");
	 scanf("%d",&y);
	 
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
	
	int simetria=0;
	
	
	for (int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			if(i!=j ){
				if (matriz[i][j]== matriz[j][i]){
			simetria++;		
			}
		}
	
	}
	}
	
	if (simetria==2*x){
		printf("La matriz es simetrica:\n");
		}else{printf("La matriz no es simetrica:\n");
			}
	return 0;
}
