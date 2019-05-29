package tenis;

import java.util.Scanner;

public class juego {
	private Scanner sc = new Scanner(System.in);
	private jugador jugador1;
	private jugador jugador2;
	private int puntaje_1 = 0;
	private int puntaje_2 = 0;
	private int jugo1 = 0;
	private int jugo2 = 0;
	private int jugadas = 0;
	private char eleccion;
	private Boolean efectuado;

	juego(){
		this.jugador1 = new jugador();
		this.jugador2 = new jugador();
		mecanismo();
	}
	
	public void mecanismo() {
		int energia1 = 0; 
		int energia2 = 0;
		int chance = 0;
		int disminucion = 0;
		System.out.println("Bienvenidos al Tie Break del ATP 250 de Utalca!!!");
		
		while ( puntaje_1 - puntaje_2 != 2 || puntaje_1 - puntaje_2 != 2 && jugadas >= 6 ) {
			efectuado = false;
			energia1 = (int)(Math.random() * 6 + 5);
			jugador1.setEnergia_jugador1(energia1);
			energia2 = (int)(Math.random() * 6 + 5);
			jugador2.setEnergia_jugador2(energia2);
			System.out.printf("La energia del jugador 1 es:"+energia1);
			System.out.printf("\nLa energia del jugador 2 es:"+ energia2+"\n");
			
			while ( efectuado == false ) {	
				if ( jugadas == 0 ) {
					System.out.println("Turno del jugador 1: a)izquierda s)centro b)derecha");
					eleccion = sc.next().charAt(0);
					jugadas++;
					
					if ( eleccion == 'a' ) {
						System.out.println("El jugador lanzo hacia el lado izquierdo!");
						chance = (int)(Math.random() * 4 + 1);
						disminucion = (int)(Math.random() * 3 + 1);
					
						//if ( chance == 0 ) {
						//	System.out.println("La pelota cayo dentro de la cancha, por lo que se sigue jugando.");
						//	energia1 = energia1 - disminucion;
						//}
						if ( chance == 1 ) {
							System.out.println("La pelota se quedo en la red!. El jugador 1 pierde el punto.");
							efectuado = true;
						}
						else if ( chance == 2 ) {
							System.out.println("La pelota cayo fuera de la cancha!. El jugador 1 pierde el punto.");
							efectuado = true;
						}
						else if ( chance == 3 ) {
							System.out.println("Tiro ganador!!!! El jugador 1 gana el punto.");
							puntaje_1++;
							efectuado = true;
						}
					}
					else if ( eleccion == 's') {
						System.out.println("El jugador lanzo hacia el centro!");
						chance = (int)(Math.random() * 4 + 1);
						disminucion = (int)(Math.random() * 3 + 1);
					
						//if ( chance == 0 ) {
						//	System.out.println("La pelota cayo dentro de la cancha, por lo que se sigue jugando.");
						//	energia1 = energia1 - disminucion;
						//}
						if ( chance == 1 ) {
							System.out.println("La pelota se quedo en la red!. El jugador 1 pierde el punto.");
							efectuado = true;
						}
						else if ( chance == 2 ) {
							System.out.println("La pelota cayo fuera de la cancha!. El jugador 1 pierde el punto.");
							efectuado = true;
						}
						else if ( chance == 3 ) {
							System.out.println("Tiro ganador!!!! El jugador 1 gana el punto.");
							puntaje_1++;
							efectuado = true;
						}
					}
					else if ( eleccion == 'd' ) {
						System.out.println("El jugador lanzo hacia el lado derecho!");
						chance = (int)(Math.random() * 4 + 1);
						disminucion = (int)(Math.random() * 3 + 1);
					
						//if ( chance == 0 ) {
						//	System.out.println("La pelota cayo dentro de la cancha, por lo que se sigue jugando.");
						//	energia1 = energia1 - disminucion;
						//}
						if ( chance == 1 ) {
							System.out.println("La pelota se quedo en la red!. El jugador 1 pierde el punto.");
							efectuado = true;
						}
						else if ( chance == 2 ) {
							System.out.println("La pelota cayo fuera de la cancha!. El jugador 1 pierde el punto.");
							efectuado = true;
						}
						else if ( chance == 3 ) {
							System.out.println("Tiro ganador!!!! El jugador 1 gana el punto.");
							puntaje_1++;
							efectuado = true;
						}
					}
					
				}
				else if ( jugadas > 0 && jugo2 == 2 ) {
					System.out.println("Turno del jugador 1: a)izquierda s)centro b)derecha");
					eleccion = sc.next().charAt(0);
					jugadas++;
					jugo1++;
					
					if (jugo1 >= 2) {
						jugo2 = 0;
					}
					
					if ( eleccion == 'a' ) {
						System.out.println("El jugador lanzo hacia el lado izquierdo!");
						chance = (int)(Math.random() * 4 + 1);
						disminucion = (int)(Math.random() * 3 + 1);
					
						//if ( chance == 0 ) {
						//	System.out.println("La pelota cayo dentro de la cancha, por lo que se sigue jugando.");
						//	energia1 = energia1 - disminucion;
						//}
						if ( chance == 1 ) {
							System.out.println("La pelota se quedo en la red!. El jugador 1 pierde el punto.");
							efectuado = true;
						}
						else if ( chance == 2 ) {
							System.out.println("La pelota cayo fuera de la cancha!. El jugador 1 pierde el punto.");
							efectuado = true;
						}
						else if ( chance == 3 ) {
							System.out.println("Tiro ganador!!!! El jugador 1 gana el punto.");
							puntaje_1++;
							efectuado = true;
						}
					}
					else if ( eleccion == 's' ) {
						System.out.println("El jugador lanzo hacia el centro!");
						chance = (int)(Math.random() * 4 + 1);
						disminucion = (int)(Math.random() * 3 + 1);
					
						//if ( chance == 0 ) {
						//	System.out.println("La pelota cayo dentro de la cancha, por lo que se sigue jugando.");
						//	energia1 = energia1 - disminucion;
						//}
						if ( chance == 1 ) {
							System.out.println("La pelota se quedo en la red!. El jugador 1 pierde el punto.");
							efectuado = true;
						}
						else if ( chance == 2 ) {
							System.out.println("La pelota cayo fuera de la cancha!. El jugador 1 pierde el punto.");
							efectuado = true;
						}
						else if ( chance == 3 ) {
							System.out.println("Tiro ganador!!!! El jugador 1 gana el punto.");
							puntaje_1++;
							efectuado = true;
						}
					}
					else if ( eleccion == 'd' ) {
						System.out.println("El jugador lanzo hacia el lado derecho!");
						chance = (int)(Math.random() * 4 + 1);
						disminucion = (int)(Math.random() * 3 + 1);
					
						//if ( chance == 0 ) {
						//	System.out.println("La pelota cayo dentro de la cancha, por lo que se sigue jugando.");
						//	energia1 = energia1 - disminucion;
						//}
						if ( chance == 1 ) {
							System.out.println("La pelota se quedo en la red!. El jugador 1 pierde el punto.");
							efectuado = true;
						}
						else if ( chance == 2 ) {
							System.out.println("La pelota cayo fuera de la cancha!. El jugador 1 pierde el punto.");
							efectuado = true;
						}
						else if ( chance == 3 ) {
							System.out.println("Tiro ganador!!!! El jugador 1 gana el punto.");
							puntaje_1++;
							efectuado = true;
						}
					}
				}
				else {
					System.out.println("Turno del jugador 2: a)izquierda s)centro b)derecha");
					eleccion = sc.next().charAt(0);
					jugadas++;
					jugo2++;
					
					if ( eleccion == 'a' ) {
						System.out.println("El jugador lanzo hacia el lado izquierdo!");
						chance = (int)(Math.random() * 4 + 1);
						disminucion = (int)(Math.random() * 3 + 1);
					
						//if ( chance == 0 ) {
						//	System.out.println("La pelota cayo dentro de la cancha, por lo que se sigue jugando.");
						//	energia2 = energia2 - disminucion;
						//}
						if ( chance == 1 ) {
							System.out.println("La pelota se quedo en la red!. El jugador 2 pierde el punto.");
							efectuado = true;
						}
						else if ( chance == 2 ) {
							System.out.println("La pelota cayo fuera de la cancha!. El jugador 2 pierde el punto.");
							efectuado = true;
						}
						else if ( chance == 3 ) {
							System.out.println("Tiro ganador!!!! El jugador 2 gana el punto.");
							puntaje_2++;
							efectuado = true;
						}
					}
					else if ( eleccion == 's' ) {
						System.out.println("El jugador lanzo hacia el centro!");
						chance = (int)(Math.random() * 4 + 1);
						disminucion = (int)(Math.random() * 3 + 1);
					
						//if ( chance == 0 ) {
						//	System.out.println("La pelota cayo dentro de la cancha, por lo que se sigue jugando.");
						//	energia2 = energia2 - disminucion;
						//}
						if ( chance == 1 ) {
							System.out.println("La pelota se quedo en la red!. El jugador 2 pierde el punto.");
							efectuado = true;
						}
						else if ( chance == 2 ) {
							System.out.println("La pelota cayo fuera de la cancha!. El jugador 2 pierde el punto.");
							efectuado = true;
						}
						else if ( chance == 3 ) {
							System.out.println("Tiro ganador!!!! El jugador 2 gana el punto.");
							puntaje_2++;
							efectuado = true;
						}
					}
					else if ( eleccion == 'd' ) {
						System.out.println("El jugador lanzo hacia el lado derecho!");
						chance = (int)(Math.random() * 4 + 1);
						disminucion = (int)(Math.random() * 3 + 1);
					
						//if ( chance == 0 ) {
						//	System.out.println("La pelota cayo dentro de la cancha, por lo que se sigue jugando.");
						//	energia2 = energia2 - disminucion;
						//}
						if ( chance == 1 ) {
							System.out.println("La pelota se quedo en la red!. El jugador 2 pierde el punto.");
							efectuado = true;
						}
						else if ( chance == 2 ) {
							System.out.println("La pelota cayo fuera de la cancha!. El jugador 2 pierde el punto.");
							efectuado = true;
						}
						else if ( chance == 3 ) {
							System.out.println("Tiro ganador!!!! El jugador 2 gana el punto.");
							puntaje_2++;
							efectuado = true;
						}
					}
				}
			}
		}
		if ( puntaje_1 >= 7 && puntaje_1 > puntaje_2 ) {
			System.out.println("GANA EL JUGADOR 1 CON UN PUNTAJE DE:"+ puntaje_1 + " a " + puntaje_2);
		}
		else if ( puntaje_2 >= 7 && puntaje_2 > puntaje_1 ) {
			System.out.println("GANA EL JUGADOR 2 CON UN PUNTAJE DE:"+ puntaje_2 + " a " + puntaje_1);
		}
		
	}
}
