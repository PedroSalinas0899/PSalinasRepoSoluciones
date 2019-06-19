package proyecto1;

public class vehiculo {
	private String nombre;
	private float daño;
	private float distancia;
	private float velocidad;
	private float aceleracion;
	private boolean reparando;
	private int posicionFinal;
	private int posicionCarrera;
	
	vehiculo(){
		this.posicionFinal = 0;
	}
	
	public String getNombre() {
		return nombre;
	}
	public void setNombre(String nombre) {
		this.nombre = nombre;
	}
	public float getDaño() {
		return daño;
	}
	public void setDaño(float daño) {
		this.daño = daño;
	}
	public float getDistancia() {
		return distancia;
	}
	public void setDistancia(float distancia) {
		this.distancia = distancia;
	}
	public float getVelocidad() {
		return velocidad;
	}
	public void setVelocidad(float velocidad) {
		this.velocidad = velocidad;
	}
	public float getAceleracion() {
		return aceleracion;
	}
	public void setAceleracion(float aceleracion) {
		this.aceleracion = aceleracion;
	}
	public boolean getReparando() {
		return reparando;
	}
	public void setReparando(boolean reparando) {
		this.reparando = reparando;
	}
	public int getPosicionFinal() {
		return posicionFinal;
	}
	public void setPosicionFinal(int posicionFinal) {
		this.posicionFinal = posicionFinal;
	}
	public int getPosicionCarrera() {
		return posicionCarrera;
	}
	public void setPosicionCarrera(int posicionCarrera) {
		this.posicionCarrera = posicionCarrera;
	}
}
