package proyecto1;

public class nave extends vehiculo {
	private int turbinas;
	private int tipoCombustible;
	
	nave() {
		super();
	}
	
	public int getTurbinas() {
		return turbinas;
	}
	public void setTurbinas(int turbinas) {
		this.turbinas = turbinas;
	}
	public int getTipoCombustible() {
		return tipoCombustible;
	}
	public void setTipoCombustible(int tipoCombustible) {
		this.tipoCombustible = tipoCombustible;
	}
}
