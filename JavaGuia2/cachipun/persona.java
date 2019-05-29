package cachipun;

public class persona {
	
	private mano mano_derecha;
	private mano mano_izquierda;
	
	persona(){
		
		this.mano_derecha = new mano (); 
		this.mano_izquierda = new mano ();
		
	}
	
	public mano getMano_derecha() {
		return mano_derecha;
	}
	
	public mano getMano_izquierda() {
		return mano_izquierda;
	}
}
