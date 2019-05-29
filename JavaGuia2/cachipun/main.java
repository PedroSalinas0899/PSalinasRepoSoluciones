package cachipun;

import java.util.Scanner;

public class main {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int juego;
		
		System.out.println("Ingrese 1 para modo 1 mano: ");
		System.out.println("Ingrese 2 para modo 2 manos: ");
		juego = sc.nextInt();
		if ( juego == 1 ) {
			juego1 juego_1 = new juego1();
			juego_1.mecanismo();
		
		}
		
		else if ( juego == 2 ) {
			juego2 juego_2 = new juego2();
			juego_2.mecanismo();
	
		}
		else {
			System.out.println("Opcion no valida.");	
		
		}
	}
}
