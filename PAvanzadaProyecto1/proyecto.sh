function grafico {
	pdb=$1
	proteina=$2

	grep ^ATOM $pdb > $proteina".txt"
	awk 'length($3) > 3 { $3 = substr($3,1,3)" "substr($3,5,3)}
		{print $0}' $proteina".txt" > $proteina"2.txt"
	awk 'length($4) > 3  { $4 = substr($4,2,3)}
	{print $0}' $proteina"2.txt" > $proteina"3.txt"
	rm -f $proteina".txt"
	rm -f $proteina"2.txt"

	awk -v CONVFMT='%.0f ' -f grafico.awk $proteina"3.txt" > $proteina".dot"
	dot -Tpng -o  "$proteina".png "$proteina".dot
	}
if ping -c 1 google.com; then
	clear
	if [[ ! -f "bd-pdb.txt" ]]; then
		echo "Se requiere descargar la base de datos donde se encuentran las proteinas."
		wget https://icb.utalca.cl/~fduran/bd-pdb.txt
	else
		echo "La base de datos de proteinas ya esta descargada."
	fi

	proteina=0
	cerrar=0
	while [[ $cerrar == 0 ]]; do
		echo "1.-Introduzca el nombre de una proteina(letras en mayus)."
		echo "2.-Introduzca (f/F) para salir."
		echo -n "---->"
		read proteina
		a=\"$proteina\"
		salir=0
		if [[ $a != "\"f\"" ]] && [[ $a != "\"F\""  ]]; then
			while [[ $salir == 0 ]]; do
				if [[ $a == "\"\"" ]]; then
					echo "Se requiere el nombre de una proteina."
					salir=1
				else
					b=`awk -F, '{print $1}' bd-pdb.txt`
					encontrado=0
					for i in $b; do
						if [[ $i == $a ]]; then
							let encontrado=1
						fi
					done

					if [[ $encontrado == 1 ]]; then
						echo "Se ha encontrado el id."
						echo "Se comprobara si es una proteina"

						c=`echo "\""$proteina"Protein\""`
						d=`awk -F\",\" '{print $1 $4}' bd-pdb.txt`

						encontrado=0
						for i in $d; do
							if [[ $i == $c ]]; then
								let encontrado=1
							fi
						done

						i=`echo "$a" | cut -c 2-5`.png
						f=`echo "$a" | cut -c 2-5`
						e=`echo "$a" | cut -c 2-5`.pdb

						if [[ $encontrado == 1 ]]; then
							echo "Si es una proteina."
							e=`echo "$a" | cut -c 2-5`.pdb
							echo $e
							if [[ ! -f "$e" ]]; then
								echo "Se descargara la proteina."
								wget https://files.rcsb.org/download/$e
									if [[ ! -f "$i" ]]; then
										grafico $e $f
										echo "El png de la proteina se ha creado."
										rm -f $f".dot"
										rm -f $f".pdb"
										rm -f $f"3.txt"
										salir=1
									else
										echo "El png de la proteina ya estaba creado."
										rm -f $f".dot"
										rm -f $f".pdb"
										rm -f $f"3.txt"
										salir=1
									fi
							else
								echo "La proteina ya se encuentra descargada."
									if [[ ! -f "$i" ]]; then
										grafico $e $f
										echo "El png de la proteina se ha creado."
										rm -f $f".dot"
										rm -f $f".pdb"
										rm -f $f"3.txt"
										salir=1
									else
										echo "El png de la proteina ya estaba creado."
										rm -f $f".dot"
										rm -f $f".pdb"
										rm -f $f"3.txt"
										salir=1
									fi
							fi
							salir=1
						else
							echo "No es una proteina."
							salir=1
						fi
					else
						echo "No se ha encontrado la id ."
						salir=1
					fi
				fi
			done
		else
			cerrar=1
		fi
	done
	else
		clear
		echo "No hay internet, no se puede continuar."
fi