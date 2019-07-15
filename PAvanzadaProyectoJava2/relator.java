package proyecto1;

public class relator {
	private boolean ganador;
	private float ganando_puntaje;
	private float adelanto_puntaje;
	private float acelero_puntaje;
	private float maslento_puntaje;
	
	relator() {
		this.ganador = false;
		this.ganando_puntaje = 0;
		this.adelanto_puntaje = 0;
		this.acelero_puntaje = 0;
		this.maslento_puntaje = 0;
	}

	public boolean getGanador() {
		return ganador;
	}

	public void setGanador(boolean ganador) {
		this.ganador = ganador;
	}
	
	public void setPrimera_ronda(String primera_ronda) {
		System.out.println(primera_ronda+" se posiciona como el lider al principio de la carrera!!!");
	}

	public void setGanando(String ganando) {
		System.out.println(ganando+" se alza como el lider indiscutible hasta el momento!");
		
	}

	public float getGanando_puntaje() {
		return ganando_puntaje;
	}

	public void setGanando_puntaje(float ganando_puntaje) {
		this.ganando_puntaje = ganando_puntaje;
	}

	public void setAdelanto(String adelanto) {
		System.out.println(adelanto+ " acaba de adelantar de una manera bestial!!!");
	}

	public float getAdelanto_puntaje() {
		return adelanto_puntaje;
	}

	public void setAdelanto_puntaje(float adelanto_puntaje) {
		this.adelanto_puntaje = adelanto_puntaje;
	}

	public void setAcelero(String acelero) {
		System.out.println(acelero + " se mando una tremenda acelerada!!!");
	}

	public float getAcelero_puntaje() {
		return acelero_puntaje;
	}

	public void setAcelero_puntaje(float acelero_puntaje) {
		this.acelero_puntaje = acelero_puntaje;
	}

	public void setMaslento(String maslento) {
		System.out.println(maslento+" deberia de retirarse de la carrera, esto es una verguenza...XD!");
	}

	public float getMaslento_puntaje() {
		return maslento_puntaje;
	}

	public void setMaslento_puntaje(float maslento_puntaje) {
		this.maslento_puntaje = maslento_puntaje;
	}
}
