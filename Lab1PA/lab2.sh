cd

if [[ ! -d "$1" ]]; then
	echo "El directorio $1 no existe."
	echo "Se creara el directorio."
	mkdir $1
	cd $1
else
	echo "El directorio ya existe."

	salir1="s"
	while [[ $salir1 = "s" ]]; do
		echo "Desea cambiar el nombre del directorio?(s/n)"
		read opc
		if [[ $opc = "s" ]]; then
			salir2="s"
			while [[ $salir2 = "s" ]]; do
				echo "Ingrese el nuevo nombre para el directorio:"
				read name
				if [[ ! -d "$name" ]]; then
					echo "El directorio $name no existe."
					echo "Se creara el directorio."
					mv $1 $name
					echo "Se ingresara al directorio."
					cd $name
					salir2="n"
				else
					echo "Ese nombre ya existe."
				fi
			done
			salir1="n"
		elif [[ $opc = "n" ]]; then
			echo "Se ingresara al directorio ya existente y se borrara todo."
			cd $1
			salir1="n"
		else
			echo "Opcion no valida."
		fi
	done
fi

echo $PWD

touch ekisde

rm -r *

touch 1t4v_docking.mol2
touch 1t4v_referencia.mol2
touch 2r2m_docking.mol2
touch 2r2m_referencia.mol2
touch 3ldx_docking.mol2
touch 3ldx_docking_new.mol2
touch 3ldx_referencia.mol2
touch 3ldx_referencia_new.mol2

mkdir c1
mkdir c2
mkdir c3

for i in $(ls); do
	if [[ `echo "$i" | cut -c1` == "1" ]]; then
		mv $i c1/
	elif [[ `echo "$i" | cut -c1` == "2" ]]; then
		mv $i c2/

	elif  [[ `echo "$i" | cut -c1` == "3" ]]; then
		mv $i c3/
	fi
done


