//paso1:Iniciar programa.
//paso2:Introducir las variables candidato 1, 2 y 3, la variable de los votos contados y los nulos.
//paso3:Introducir la variable para poder finalizar el programa.
//paso4:Abrir un while para tener un bucle y repetir una instruccion.
//paso5:Ecribir las instrucciones del while .
//paso6:Abrir un switch para poner las opciones dentro del bucle.
//paso7:Poner while para ver si el usuario quiere que el switch se repita o no.
//paso8:Si el usuario no quiere continuar el primer while se cerrara.
//paso9:Imprimir en pantalla que le programa se finalizo.
//paso10:Introducir las variables para poder sacar el porcentaje de los votos al candidato 1,2 y 3 y trambien la de los votos nulos.
//paso11:Imprimir en pantalla para ver el numero de votos efectuados a candidato 1,2,3 o nulo y el porcentaje de cada uno.
//paso12:Abrir un if con 3 posibilidades, para ver quien va a ser el ganador dependiendo de quien tiene la mayor cantidad.
//paso13:Cerrar el if al tener un ganador.
//paso14:Finalizar programa.


#include <stdio.h>
int main(){
	printf("\n Elecciones para presidente del centro de alumnos de la carrera ICB.");
	printf("\n Los candidatos son 3:.");
	int cand1,cand2,cand3,votos,nulos;
	cand1=0;
	cand2=0;
	cand3=0;
	nulos=0;
	char finalizar='v';
	while (finalizar!='f'){
	printf("\n Ingrese 1 si quiere votar por el candidato 1.");
	printf("\n Ingrese 2 si quiere votar por el candidato 2.");
	printf("\n Ingrese 3 si quiere votar por el candidato 3.");
	printf("\n Ingrese cualquier otro numero si quiere votar nulo.");
	printf("\n Ingrese f si quiere terminar el programa:\n");
	scanf("%d",&votos);
	switch (votos){
		case 1: 
			printf("\n Usted voto por el candidato 1:\n");
			cand1++;
			break;
		case 2:
		printf("\n Usted voto por el candidato 2:\n");
			cand2++;
			break;
		case 3:
		printf("\n Usted voto por el candidato 3:\n");
			cand3++;
			break;
		case 4:
		printf("\n Usted voto nulo:\n");
			nulos++;
			break;
		}
		while (getchar()!= '\n');
		printf("Si desea continuar presione cualquier letra y sino presione f:");
		scanf("%c",&finalizar);	
	}

	printf("\n Usted finalizo el programa:%c\n",finalizar);
	
	float total_de_votos,porcentaje_votos1, porcentaje_votos2,porcentaje_votos3,porcentaje_nulos;
	total_de_votos=cand1+cand2+cand3;
	porcentaje_votos1=(cand1/total_de_votos)*100;
	porcentaje_votos2=(cand2/total_de_votos)*100;
	porcentaje_votos3=(cand3/total_de_votos)*100;
	porcentaje_nulos=(nulos/total_de_votos)*100;
	printf("\n Los votos totales del candidato 1 son:%d\n",cand1);
	printf("\n El porcentaje de votos del candidato 1 es:%.2f\n",porcentaje_votos1);
	printf("\n Los votos totales del candidato 2 son:%d\n",cand2);
	printf("\n El porcentaje de votos del candidato 2 es:%.2f\n",porcentaje_votos2);
	printf("\n Los votos totales del candidato 3 son:%d\n",cand3);
	printf("\n El porcentaje de votos del candidato 3 es:%.2f\n",porcentaje_votos3);
	printf("\n Los votos nulos son:%d\n",nulos);
	printf("\n El procentaje de los votos nulos es:%.2f\n",porcentaje_nulos);
	if (cand1>cand2 && cand1>cand3){
		printf("\n Gano el candidato 1!!!\n");
	}
		else if (cand2>cand1 && cand2>cand3){
		printf("\n Gano el candidato 2!!!\n");
	}
		else if (cand3>cand2 && cand3>cand1)
		printf("\n Gano el candidato 3!!!\n");
	return 0;
	
}


		
	
		
	
