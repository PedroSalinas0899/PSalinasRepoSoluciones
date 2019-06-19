package proyecto1;

import java.util.ArrayList;
import java.util.Scanner;

public class carrera {
	private Scanner sc = new Scanner(System.in);
	private ArrayList<nave> pilotos = new ArrayList();
	private ArrayList<mecanico_vehiculo> mecanicos = new ArrayList();	
	private pista circuito;
	private int cantidad_naves;
	private int turbinas;
	private int tipoCombustible;
	
	carrera(int numero_naves) {
		cantidad_naves = numero_naves + 1;
		circuito = new pista();
		
		for ( int i = 0; i < cantidad_naves; i++ ) {
			mecanico_vehiculo mecanico = new mecanico_vehiculo();
			mecanico.setOcupado(false);
			mecanico.setReparacion(0);
			mecanicos.add(mecanico);
		}
		agregacion_naves();
	}
	
	public void agregacion_naves() {	
		boolean continuar = false;
				
		while ( continuar == false ) {		
			System.out.println("Ingrese la cantidad de turbinas que quiere");	
			System.out.println("(Cada turbina es un multiplicador x1.3 de la aceleracion");
			System.out.println("y ademas el daño resivido a la nave sera x1.3):");
			turbinas = sc.nextInt();
			sc.nextLine();
			
			if ( turbinas > 0 ) {
				continuar = true;
			}
			else {
				System.out.println("Valor no valido, ingrese nuevamente:");
			}
		}
		
		continuar = false;
		while ( continuar == false ) {
			System.out.println("Ingrese el tipo de combustible que desea");
			System.out.println("1 para el nuclear + 4% de aceleracion x segundo");
			System.out.println("2 para el diesel + 2% de aceleracion x segundo");
			System.out.println("3 para el biodiesel + 0.3% de aceleracion x segundo");
			tipoCombustible = sc.nextInt();
			sc.nextLine();
			
			if ( tipoCombustible == 1 || tipoCombustible == 2 || tipoCombustible == 3 ) {
				continuar = true;
			}
			else {
				System.out.println("Valor no valido, ingrese nuevamente:");
			}
		}
		
		nave piloto_jugador = new nave();
		piloto_jugador.setNombre("NAVE JUGADOR");
		piloto_jugador.setTurbinas(turbinas);
		piloto_jugador.setTipoCombustible(tipoCombustible);
		piloto_jugador.setDaño(100);
		piloto_jugador.setDistancia(0);
		piloto_jugador.setVelocidad(0);
		piloto_jugador.setReparando(false);
		pilotos.add(piloto_jugador);
		
		String nave_bot;
		for ( int i = 1; i < cantidad_naves; i++ ) {
			nave piloto = new nave();
			nave_bot = "NAVE BOT "+i;
			turbinas = (int)(Math.random() * 6 + 1); 
			tipoCombustible = (int)(Math.random() * 3 + 1);
			piloto.setNombre(nave_bot);
			piloto.setTurbinas(turbinas);
			piloto.setTipoCombustible(tipoCombustible);
			piloto.setDaño(100);
			piloto.setDistancia(0);
			piloto.setVelocidad(0);
			piloto.setReparando(false);
			pilotos.add(piloto);
		}
		
		System.out.println("Los competidores han sido escogidos!");
		System.out.println("A continuacion se mostraran las especificaciones de cada una de las naves:");
		
		String a = "";
		int b = 0;
		int c = 0;
		String d = "";
		for ( nave i: pilotos) {
			a = i.getNombre();
			b = i.getTurbinas();
			c = i.getTipoCombustible();
			if ( c == 1 ) {
				d = "nuclear";
				i.setAceleracion(8);
			}
			else if ( c == 2 ) {
				d = "diesel";
				i.setAceleracion(4);
			}
			else if ( c == 3 ) {
				d = "biodiesel";
				i.setAceleracion(0.6f);
			}
			System.out.println(a+"|"+"Cantidad de turbinas: "+b+" Tipo de combustible: "+d);
		}
		System.out.println();
		//DEBO IMPRIMIR UNA INTEFAZ DE INICIO, TIEMPO 0
		temporizador();
	}
	
	public void temporizador() {
		int finalizar = 0;
		int tiempo = 2;
		int posicion = 1;
		boolean fin = false;
		
		while ( finalizar < cantidad_naves ) {
			for ( nave i: pilotos) {
				if (i.getDistancia() >= circuito.getLargo() && i.getPosicionFinal() == 0 ) {
					i.setPosicionFinal(circuito.getLargo() + tiempo);
					i.setPosicionCarrera(posicion);
					posicion++;
					finalizar++;
				}
			}
			
			if ( finalizar == cantidad_naves ) {
				fin = true;
			}
			try {
	                Thread.sleep(2000);
	                correr_carrera(tiempo);
	                tiempo = tiempo + 2;
	            } catch (InterruptedException e) {
	                e.printStackTrace();
	            }
		}
		if ( fin == true ) {
			termina_carrera();
		}
	}
	
	public void correr_carrera(int tiempo) {
		for ( nave i: pilotos) {
			if ( i.getDaño() == 0 ) {
				i.setReparando(true);
				i.setAceleracion(0);
				i.setVelocidad(0);
			}
			else if ( i.getDaño() == 100 ) {
				i.setReparando(false);
				i.setVelocidad(0);
				
				if ( i.getTipoCombustible() == 1 ) {
					i.setAceleracion(8);	
				}
				else if ( i.getTipoCombustible() == 2 ) {
					i.setAceleracion(4);	
				}
				else if ( i.getTipoCombustible() == 3 ) {
					i.setAceleracion(0.6f);	
				}
			}
		}

		for ( int i = 0; i < cantidad_naves; i++) {
			if ( pilotos.get(i).getReparando() == true ) {
				mecanicos.get(i).setOcupado(true);
			}
			else if ( pilotos.get(i).getReparando() == false ) {
				mecanicos.get(i).setOcupado(false);
			}
		}

		for ( nave i: pilotos) {
			if ( i.getReparando() == false ) {
				int explosion_improvista = (int)(Math.random() * 100 + 1); 
				i.setAceleracion(i.getAceleracion() + (i.getAceleracion() * 64 / 100));
				i.setAceleracion(i.getAceleracion() + (i.getAceleracion() * i.getTurbinas() / 3));
				if ( explosion_improvista >= 65 ) {
					i.setAceleracion(i.getAceleracion() * 1.5f);
				}
				else if ( explosion_improvista >= 80 ) {
					i.setAceleracion(i.getAceleracion() * 2);
				}
				
				i.setVelocidad(i.getVelocidad() + i.getAceleracion() * tiempo);
				i.setDistancia(i.getDistancia() + i.getVelocidad() * tiempo);
				
				if ( i.getTipoCombustible() == 1 ) {
					i.setDaño(i.getDaño() - i.getTurbinas() * 1.3f * 4  );
					if ( i.getDaño() <= 0 ) {
						i.setDaño(0);
					}
				}
				else if ( i.getTipoCombustible() == 2 ) {
					i.setDaño(i.getDaño() - i.getTurbinas() * 1.3f * 2  );
					if ( i.getDaño() <= 0 ) {
						i.setDaño(0);
					}
				}
				else if ( i.getTipoCombustible() == 3 ) {
					i.setDaño(i.getDaño() - i.getTurbinas() * 1.3f * 0.3f );
					if ( i.getDaño() <= 0 ) {
						i.setDaño(0);
					}
				}
			}
		}
		
		for ( mecanico_vehiculo i: mecanicos ) {
			if ( i.getOcupado() == true ) {
				i.setReparacion(i.getReparacion() + 20);
			}
		}
		
		for ( int i = 0; i < cantidad_naves; i++) {
			if ( mecanicos.get(i).getReparacion() == 100 ) {
				 mecanicos.get(i).setReparacion(0);
				 mecanicos.get(i).setOcupado(false);
				 pilotos.get(i).setReparando(false);
				 pilotos.get(i).setDaño(100);
			}
		}
		
		for ( nave i: pilotos) {
			if ( i.getPosicionFinal() != 0 ) {
				i.setDaño(0);
				i.setAceleracion(0);
				i.setVelocidad(0);
				i.setDistancia(circuito.getLargo());
			}
		}
		
		for ( nave i: pilotos) {
			if ( i.getPosicionFinal() == 0 ) {
				float a = i.getAceleracion();
				float b = i.getDistancia();
				float c = i.getVelocidad();
				float d = i.getDaño();
				System.out.println(i.getNombre()+"|"+"Velocidad:"+c+" |Aceleracion:"+a+" |Distancia:"+b+" |Daño:"+d);
			}
		}
		System.out.println();
	}

	public void termina_carrera() {
		int ganadores[] = new int[cantidad_naves];
		String ganadores_nombre[] = new String[cantidad_naves];
		
		for ( int i = 0; i < cantidad_naves; i++ ) {
			ganadores[i] = pilotos.get(i).getPosicionCarrera();
			ganadores_nombre[i] = pilotos.get(i).getNombre();
		}
		
		for ( int i = 1; i < cantidad_naves; i++ ) {
			for ( int j = 0; j < cantidad_naves - 1; j++ ) {
				if ( ganadores[j] > ganadores[j+1] ) {
					int aux = ganadores[j];
					ganadores[j] = ganadores[j+1];
					ganadores[j+1] = aux;
					
					String aux2 = ganadores_nombre[j];
					ganadores_nombre[j] = ganadores_nombre[j+1];
					ganadores_nombre[j+1] = aux2;
				}	
			}
		}
		
		for ( int i = 0; i < cantidad_naves; i++ ) {
			System.out.println(ganadores_nombre[i]+"| Posicion: "+ganadores[i]);
		}
	}
}

	
	
