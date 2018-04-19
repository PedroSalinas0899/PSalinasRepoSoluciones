//paso1:Iniciar programa.
//paso2:Introducir las variables para poder obtener la cuenta, el numero de personas, el iva de la cuenta, la propina, la cuenta sumada al
//iva y cuanto debera pagar cada uno segun la cuenta TOTAL.
//paso3:Imprimir ne pantalla que se introduzca el numero de personas y cuanto salio la cuenta.
//paso4: Etablecer como obtener todas las variables sabiendo la cuenta y el numero de personas.
//paso5:Imprimir en pantalla el iva de la cuenta, la propina de la cuenta y cuanto debera de pagar cada persona.
//paso6:Finalizar programa.


#include <stdio.h>
int main(){
	printf("\n Programa para ver cuanto tienen que pagar Pepe y sus amigos.\n");
	float iva,cuenta,pepe_y_amigos,propina_total,cuenta_iva,cuenta_total,cuenta_total_cadauno,cuenta_con_iva;
	iva=0.19;	
	printf("Cuantas personas son en total?\n");
	scanf("%f",&pepe_y_amigos);
	printf("Cuanto salio la cuenta de Pepe y sus amigos:");
	scanf("%f",&cuenta);
	propina_total=cuenta*0.1;
	cuenta_iva=iva*cuenta;
	cuenta_con_iva=cuenta_iva+cuenta;
	cuenta_total=propina_total+cuenta_con_iva;
	cuenta_total_cadauno=cuenta_total/pepe_y_amigos;
	printf("El iva de la cuenta es:%.2f\n",cuenta_iva);
	printf("La propina de la cuenta es:%.2f\n",propina_total);
	printf("Cada uno debera pagar segun la propina de la cuenta y al iva que se le agrega:%.2f\n",cuenta_total_cadauno);
	return 0;
}
	
	
	
	

