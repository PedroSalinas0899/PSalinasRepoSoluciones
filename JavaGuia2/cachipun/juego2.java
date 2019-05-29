package cachipun;

import java.util.Scanner;

public class juego2 {
	
	private persona persona1;
	private persona persona2;
	private Scanner sc = new Scanner(System.in);
	private Boolean listo1 = false;
	private int ganador = 0;
	private int ganador2 = 0;
	private int mano_derecha;
	private int mano_izquierda;
	private int jugador1_derecha;
	private int jugador1_izquierda;		
	private int jugador2_derecha;
	private int jugador2_izquierda;

	juego2(){
		
		this.persona1 = new persona ();
		this.persona2 = new persona ();
	}
	
	public void mecanismo() {	
		while (listo1 == false ) {	
			System.out.println("Jugador 1 derecha | 1: papel, 2: piedra, 3:tijera");
			mano_derecha = sc.nextInt();
			persona1.getMano_derecha().setDerecha(mano_derecha);
			jugador1_derecha = persona1.getMano_derecha().getDerecha();
			
			System.out.println("Jugador 1 izquierda | 1: papel, 2: piedra, 3:tijera");
			mano_izquierda = sc.nextInt();
			persona1.getMano_izquierda().setIzquierda(mano_izquierda);
			jugador1_izquierda = persona1.getMano_izquierda().getIzquierda();
			
			System.out.println("Jugador 2 derecha | 1: papel, 2: piedra, 3:tijera");
			mano_derecha = sc.nextInt();
			persona2.getMano_derecha().setDerecha(mano_derecha);
			jugador2_derecha = persona2.getMano_derecha().getDerecha();
			
			System.out.println("Jugador 2 izquierda| 1: papel, 2: piedra, 3:tijera");
			mano_izquierda = sc.nextInt();
			persona2.getMano_izquierda().setIzquierda(mano_izquierda);
			jugador2_izquierda = persona2.getMano_izquierda().getIzquierda();
			
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
			if ( jugador1_izquierda == 2 && jugador2_izquierda == 3 ) {
				ganador ++;
			}
			else if ( jugador1_izquierda == 2 && jugador2_izquierda == 1 ) {
				ganador2 ++;
			}
			else if ( jugador1_izquierda == 3 && jugador2_izquierda == 2 ) {
				ganador2 ++;
			}
			else if ( jugador1_izquierda == 3 && jugador2_izquierda == 1 ) {
				ganador ++;
			}
			else if ( jugador1_izquierda == 1 && jugador2_izquierda == 2 ) {
				ganador ++;
			}
			else if ( jugador1_izquierda == 1 && jugador2_izquierda == 3 ) {
				ganador2 ++;
			}
			if ( ganador > ganador2 ) {
				System.out.println("Ha ganado el jugador 1");
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
