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
				if (i==j){
				matrizA[i][j]=1;
				}else{
					matrizA[i][j]=0;	 
			}
		}
		}
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			printf("%d-",matrizA[i][j]);
	 }
	 printf("\n");
 }
 return 0;
}
