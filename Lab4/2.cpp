//Iniciar programa.
//Imprimimos en pantalla el enunciado de el problema Y la pregunta respectiva.
//Introducimos las variables que serian los datos que nos da el enunciado y establecemos las formulas de las variables que serian la respuesta
//a la pregunta del problema.
//Imprimimos en pantalla las respuestas de la pregunta.
//Finalizar programa.
#include <stdio.h>

int main(){
	printf("Juan, Manuel y Antonio se reparten 8 huevos revueltos en partes iguales.\n");
	printf("Juan puso 5 huevos, Manuel 3 y Antonio ninguno.\n");
	printf("Acuerdan que, a cambio, Antonio les debe pagar 80 pesos a los 2.\n");
	printf("¿Cuanto de los 80 pesos tendra que dar Antonio a Juan y cuanto a Manuel, para que el trato sea justo para los tres?.\n");
	float dinero_huevos=80,juan=5,manuel=3,juan_le_deben,manuel_le_deben,juanmanuel_le_deben,juan_resive,manuel_resive;
		juan_le_deben=juan-2.666666666;
		manuel_le_deben=manuel-2.66666666666;
		juanmanuel_le_deben=juan_le_deben + manuel_le_deben;
		juan_resive=(juan_le_deben*dinero_huevos)/juanmanuel_le_deben;
		manuel_resive=(manuel_le_deben*dinero_huevos)/juanmanuel_le_deben;
		
		printf("Antonio le debe a Juan %.0f y a Manuel %.0f de los  respectivos 80 pesos.",juan_resive,manuel_resive);
		return 0;
	}
