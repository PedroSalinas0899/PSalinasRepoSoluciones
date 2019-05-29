package cachipun;

import java.util.Scanner;

public class juego1 {

	private persona persona1;
	private persona persona2;
	private Scanner sc = new Scanner(System.in);
	private Boolean listo1 = false;
	private int ganador = 0;
	private int ganador2 = 0;
	private int mano_derecha;
	private int jugador1_derecha;		
	private int jugador2_derecha;

	juego1(){
		
		this.persona1 = new persona ();
		this.persona2 = new persona ();
	}
	
	public void mecanismo() {
		
		while (listo1 == false ) {
			System.out.println("Jugador 1 | 1: papel, 2: piedra, 3:tijera");
			mano_derecha = sc.nextInt();
			persona1.getMano_derecha().setDerecha(mano_derecha);
			jugador1_derecha = persona1.getMano_derecha().getDerecha();
			
			System.out.println("Jugador 2 | 1: papel, 2: piedra, 3:tijera");
			mano_derecha = sc.nextInt();
			persona2.getMano_derecha().setDerecha(mano_derecha);
			jugador2_derecha = persona2.getMano_derecha().getDerecha();
		
			if ( jugador1_derecha == 2 && jugador2_derecha == 3 ) {
				ganador ++;
			}
			else if ( jugador1_derecha == 2 && jugador2_derecha == 1 ) {
				ganador2 ++;
			}
			else if ( jugador1_derecha == 3 && jugador2_derecha == 2 ) {
				ganador2 ++;
			}
			else if ( jugador1_derecha == 3 && jugador2_derecha == 1 ) {
				ganador ++;
			}
			else if ( jugador1_derecha == 1 && jugador2_derecha == 2 ) {
				ganador ++;
			}
			else if ( jugador1_derecha == 1 && jugador2_derecha == 3 ) {
				ganador2 ++;
			}
			if ( ganador > ganador2 ) {
				System.out.println("Ha ganado el jugador 1 ");
				listo1 = true;	
				dibujo_final a = new dibujo_final();
				System.out.println("Jugador 1");
				a.Ganador();
				System.out.println("Jugador 2");
				a.Perdedor();
			}
			else if ( ganador < ganador2 ) {
				System.out.println("Ha ganado el jugador 2");
				listo1 = true;
				dibujo_final a = new dibujo_final();
				System.out.println("Jugador 2");
				a.Ganador();
				System.out.println("Jugador 1");
				a.Perdedor();
				
			}
			else if ( ganador == ganador2 ) {
				System.out.println("Empate. Repitan el juego ");
			}
		}	
	}
}
