cd
if [[ ! -d "$1" ]]; then
		echo "Se requiere de un directorio para listar."
	else
		cd $1
		ls -lSr | awk '{print $9}' | nl
	fi
exit 1