package proyecto1;

import java.util.ArrayList;
import java.util.Scanner;
import java.text.DecimalFormat;

public class carrera {
	private Scanner sc = new Scanner(System.in);
	private ArrayList<vehiculo> pilotos = new ArrayList();
	private ArrayList<mecanico_vehiculo> mecanicos = new ArrayList();	
	private pista circuito;
	private relator comentarista;
	private int cantidad_naves;
	private int turbinas;
	private int tipoCombustible;
	private boolean primera_ronda;
	
	carrera(int numero_naves) {
		primera_ronda = false;
		cantidad_naves = numero_naves + 1;
		circuito = new pista();
		
		comentarista = new relator();
		
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
		
		vehiculo piloto_jugador = new vehiculo();
		piloto_jugador.setNombre("NAVE JUGADOR");
		piloto_jugador.setTurbinas(turbinas);
		piloto_jugador.setTipoCombustible(tipoCombustible);
		piloto_jugador.setDaño(100);
		piloto_jugador.setDistancia(0);
		piloto_jugador.setVelocidad(0);
		piloto_jugador.setReparando(false);
		pilotos.add(piloto_jugador);
		
		String nave_bot;
		String a = "";
		int b = 0;
		int c = 0;
		String d = "";
		
		for ( int i = 1; i < cantidad_naves; i++ ) {
			vehiculo piloto = new vehiculo();
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
			
			if ( c == 1 ) {
				d = "nuclear";
				pilotos.get(i).setAceleracion(8);
			}
			else if ( c == 2 ) {
				d = "diesel";
				pilotos.get(i).setAceleracion(4);
			}
			else if ( c == 3 ) {
				d = "biodiesel";
				pilotos.get(i).setAceleracion(0.6f);
			}
		}
		
		System.out.println("Los competidores han sido escogidos!");
		System.out.println("A continuacion se mostraran las especificaciones de cada una de las naves:");
		
		for ( vehiculo i: pilotos) {
			a = i.getNombre();
			b = i.getTurbinas();
			c = i.getTipoCombustible();
	
			System.out.println(a+"|"+"Cantidad de turbinas: "+b+" Tipo de combustible: "+c);
		}
		System.out.println();
		temporizador();
	}
	
	public void temporizador() {
		int finalizar = 0;
		int tiempo = 2;
		int posicion = 1;
		boolean fin = false;
		
		while ( finalizar < cantidad_naves ) {
			for ( vehiculo i: pilotos) {
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
	                avance_carrera();
	                relato_carrera();
	                System.out.println();
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
		for ( vehiculo i: pilotos) {
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

		for ( vehiculo i: pilotos) {
			if ( i.getReparando() == false ) {
				int explosion_improvista = (int)(Math.random() * 100 + 1); 
				
				i.setAceleracion(i.getAceleracion() + (i.getAceleracion() * 64 / 100));
				i.setAceleracion(i.getAceleracion() + (i.getAceleracion() * i.getTurbinas() / 3));
				
				if ( explosion_improvista >= 65 ) {
					i.setAceleracion(i.getAceleracion() * 1.2f);
				}
				else if ( explosion_improvista >= 80 ) {
					i.setAceleracion(i.getAceleracion() * 1.8f);
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
		
		for ( vehiculo i: pilotos) {
			if ( i.getPosicionFinal() != 0 ) {
				i.setDaño(0);
				i.setAceleracion(0);
				i.setVelocidad(0);
				i.setDistancia(circuito.getLargo());
			}
		}
	}
	
	public void avance_carrera() {
		float porcentaje_corrido;
		float porcentaje_corrido_redondeado;
		
		for ( int i = 0; i < cantidad_naves; i++ ) {
			porcentaje_corrido = (pilotos.get(i).getDistancia() * 100) / circuito.getLargo() ;
			porcentaje_corrido_redondeado = Math.round(porcentaje_corrido);
			
			if ( porcentaje_corrido_redondeado > 100 ) {
				porcentaje_corrido_redondeado = 100;
			}
			
			for ( int j = 0; j < porcentaje_corrido_redondeado; j++ ) {
				System.out.print("|");
			}
			System.out.print(pilotos.get(i).getNombre());
			System.out.println();
		}
		
	}
	
	public void relato_carrera() {
		System.out.println();
		float posiciones[] = new float[cantidad_naves];
		String nombre_posiciones[] = new String[cantidad_naves];
		
		float posiciones_anteriores[] = new float[cantidad_naves];
		String nombre_posiciones_anteriores[] = new String[cantidad_naves];
		
		float aceleraciones_anteriores[] = new float[cantidad_naves];
		String nombre_aceleraciones_anteriores[] = new String[cantidad_naves];
		
		float aceleraciones[] = new float[cantidad_naves];
		String nombre_aceleraciones[] = new String[cantidad_naves];
		
		for ( int i = 0; i < cantidad_naves; i++ ) {
			posiciones[i] = pilotos.get(i).getDistancia();
			nombre_posiciones[i] = pilotos.get(i).getNombre();
		}
		
		for ( int i = 1; i < cantidad_naves; i++ ) {
			for ( int j = 0; j < cantidad_naves - 1; j++ ) {
				if ( posiciones[j] > posiciones[j+1] ) {
					float aux = posiciones[j];
					posiciones[j] = posiciones[j+1];
					posiciones[j+1] = aux;
					
					String aux2 = nombre_posiciones[j];
					nombre_posiciones[j] = nombre_posiciones[j+1];
					nombre_posiciones[j+1] = aux2;
				}	
			}
		}
		
		for ( int i = 0; i < cantidad_naves; i++ ) {
			posiciones[i] = pilotos.get(i).getAceleracion();
			nombre_posiciones[i] = pilotos.get(i).getNombre();
		}
		
		for ( int i = 1; i < cantidad_naves; i++ ) {
			for ( int j = 0; j < cantidad_naves - 1; j++ ) {
				if ( aceleraciones[j] > aceleraciones[j+1] ) {
					float aux = aceleraciones[j];
					aceleraciones[j] = aceleraciones[j+1];
					aceleraciones[j+1] = aux;
					
					String aux2 = nombre_aceleraciones[j];
					nombre_aceleraciones[j] = nombre_aceleraciones[j+1];
					nombre_aceleraciones[j+1] = aux2;
				}	
			}
		}
		
		if ( primera_ronda == false ) {
			comentarista.setPrimera_ronda(nombre_posiciones[0]);
			primera_ronda = true;
		}
		else if ( primera_ronda == true ) {
			if ( comentarista.getGanador() == false ) {
				//RELATO DE GANADOR SEGUN DIFERENCIA DE DISTANCIA
				float diferencia1;
				diferencia1 = ((posiciones[0] - posiciones[1]) * 100 / 600000);
				
				comentarista.setGanando_puntaje(diferencia1);
				//RELATO DE ADELANTADOR AL LIDER 
				float diferencia2 = 0;
				String nave_adelanto = "";
				float auxiliar = 0;
				
				for ( int i = 0; i < cantidad_naves; i++ ) {
					for ( int j = 0; j < cantidad_naves; j++ ) {
						if ( posiciones_anteriores[i] >= posiciones_anteriores[j] ) {
							if ( posiciones[i] < posiciones[j] ) {
								if ( diferencia2 == 0 ) {
									diferencia2 = ((posiciones[j] - posiciones[i]) * 100 / 600000);
									nave_adelanto = nombre_posiciones[j];
								}
								else if ( diferencia2 != 0 ) {
									auxiliar = ((posiciones[j] - posiciones[i]) * 100 / 600000);
									if ( auxiliar > diferencia2 ) {
										diferencia2 = auxiliar;
										nave_adelanto = nombre_posiciones[j];
									}
								}
							}
						}
					}	
				}
				comentarista.setAdelanto_puntaje(diferencia2);				
				//RELATO DE MEJOR ACELERACION CON RESPECTO A LA ANTERIOR
				float diferencia3 = 0;
				String nave_acelero = "";
				auxiliar = 0;
				
				for ( int i = 0; i < cantidad_naves; i++ ) {
					if ( diferencia3 == 0 ) {
						diferencia3 = ((aceleraciones[i] - aceleraciones_anteriores[i]) * 100 / 600000);
						nave_acelero = nombre_aceleraciones[i];
					}
					else if ( diferencia3 != 0 ) {
						auxiliar = ((aceleraciones[i] - aceleraciones_anteriores[i]) * 100 / 600000);
						if ( auxiliar > diferencia3 ) {
							diferencia3 = auxiliar;
							nave_acelero = nombre_aceleraciones[i];
						}
					}
				}
				comentarista.setAcelero_puntaje(diferencia3);
				//VERIFICAR CUAL COMENTARIO SERA EMITIDO
				float a = comentarista.getGanando_puntaje();
				float b = comentarista.getAdelanto_puntaje();
				float c = comentarista.getAcelero_puntaje();
	
				if ( a > b && a > c) {
					comentarista.setGanando(nombre_posiciones[0]);
				}
				else if ( b > a && b > c ) {
					comentarista.setAdelanto(nave_adelanto);
				}
				else {
					comentarista.setAcelero(nave_acelero);
				}
			}
			else if ( comentarista.getGanador() == true ) {
				//RELATO DE MEJOR ACELERACION CON RESPECTO A LA ANTERIOR
				float diferencia3 = 0;
				float auxiliar = 0;
				
				for ( int i = 0; i < cantidad_naves; i++ ) {
					if ( diferencia3 == 0 ) {
						diferencia3 = ((aceleraciones[i] - aceleraciones_anteriores[i]) * 100 / 600000);
					}
					else if ( diferencia3 != 0 ) {
						auxiliar = ((aceleraciones[i] - aceleraciones_anteriores[i]) * 100 / 600000);
						if ( auxiliar > diferencia3 ) {
							diferencia3 = auxiliar;
						}
					}
				}
				comentarista.setAcelero_puntaje(diferencia3);	
				//RELATO DEL COMPETIDOR MAS LENTO
				float diferencia4;
				diferencia4 = ((posiciones[cantidad_naves-1] - posiciones[0]) * 100 / 600000);; 
				comentarista.setMaslento_puntaje(diferencia4);
				//VERIFICAR CUAL ES  EL RELATO QUE SE DIRA
				float a = comentarista.getAcelero_puntaje();
				float b = comentarista.getMaslento_puntaje();
				 
				if ( a > b ) {
					comentarista.setAcelero(nombre_posiciones[0]);
				}
				else {
					comentarista.setMaslento(nombre_posiciones[cantidad_naves-1]);
				}
			}
			
		}
		
		for ( int i = 0; i < cantidad_naves; i++ ) {
			posiciones_anteriores[i] = posiciones[i];
			nombre_posiciones_anteriores[i] = nombre_posiciones[i];
		}
		
		for ( int i = 0; i < cantidad_naves; i++ ) {
			aceleraciones_anteriores[i] = aceleraciones[i];
			nombre_aceleraciones_anteriores[i] = nombre_aceleraciones[i];
		}
		
		
		for ( int i = 0; i < cantidad_naves; i++ ) {
			if ( pilotos.get(i).getPosicionFinal() != 0 ) {
				comentarista.setGanador(true);
			}
		}		
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
		
		System.out.println();
		for ( int i = 0; i < cantidad_naves; i++ ) {
			System.out.println(ganadores_nombre[i]+"| Posicion: "+ganadores[i]);
		}
	}
}


