function filtrar {
    pdb=$1
    proteina=$2
    rango=$3
    
    #Se filtra unicamente para ATOM, donde se revisaran los fallos en columnas
    #1-2, 3-4,4-5 y 5-6
    grep ^ATOM $pdb > $proteina".txt"
    awk 'length($3) > 3 { $3 = substr($3,1,3)" "substr($3,5,3)}
        {print $0}' $proteina".txt" > $proteina"1.txt"
    awk 'length($4) > 3  { $4 = substr($4,2,3)}
        {print $0}' $proteina"1.txt" > $proteina"2.txt"
    awk 'length($5) > 1 { $5 = substr($5,1,1)" "substr($5,2,4)}
        {print $0}' $proteina"2.txt" > $proteina"a.txt"
    #Se filtra unicamente para HETATM, donde se revisaran los fallos en columnas
    #1-2, 3-4,4-5 y 5-6
    grep ^HETATM $pdb > $proteina".txt"
    awk 'length($1) > 6 { $1 = substr($1,1,6)" "substr($1,7,5)}
        {print $0}' $proteina".txt" > $proteina"1.txt"
    awk 'length($5) > 1 { $5 = substr($5,1,1)" "substr($5,2,4)}
        {print $0}' $proteina"1.txt" > $proteina"2.txt"
    awk '$4 != "HOH" {print $0}' $proteina"2.txt" > $proteina"b.txt"
    #Se calculan los centros geometricos con archivo cg.awk, y se introduce
    #el rango en el archivo core (se necesitara de un archivo pivote mas adelante 
    #el cual sera numero_il)
    awk -v CONVFMT='%.0f ' -f cg.awk $proteina"b.txt" > $proteina"numero_il.txt"
    awk -v CONVFMT='%.0f ' -f cg.awk $proteina"b.txt" >> $proteina"a.txt"
    echo "$rango" >> $proteina"a.txt"
    
    numero_il=`awk -F\",\" '{print $0}' $proteina"numero_il.txt"`
    cabeza="HETATM"
    cantidad=0
    #gracias a este for se podra calcular el numero de iones/ligando que hay
    #y la variable resultante nos servira para calcular numero de graficos por hacer
    for i in $numero_il; do
        if [[ $i == "HETATM" ]]; then
            cantidad=$((cantidad+1))
        fi
    done
    
    uno=1
    for (( i=$uno; i<=$cantidad; i++ )); do
        awk -v posicion=$i -f distancias.awk $proteina"a.txt" > $proteina"c"-$i".txt"
        awk -v CONVFMT='%.0f' -f grafico.awk $proteina"c"-$i".txt" > $proteina-$rango-$i".dot"
        dot -Tsvg -o  "$proteina"-"$rango"-"$i".svg "$proteina"-"$rango"-"$i".dot
    done
    
    rm -f $proteina"a.txt" 
    rm -f $proteina"b.txt" 
    rm -f $proteina".txt" 
    rm -f $proteina"1.txt" 
    rm -f $proteina"2.txt" 
    rm -f $proteina"numero_il.txt"
    
    for (( i=$uno; i<=$cantidad; i++ )); do
        rm -f $proteina"c-"$i".txt"
        rm -f $proteina"-"$rango"-"$i".dot"
    done
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
    rango=0
    cerrar=0
    while [[ $cerrar == 0 ]]; do
        echo ""
        echo "1.-Introduzca el nombre de una proteina(letras en mayus)."
        echo "2.-Introduzca (f/F) para salir."
        echo -n "---->"
        read proteina
        
        a=\"$proteina\"
        salir=0
        if [[ $a != "\"f\"" ]] && [[ $a != "\"F\""  ]]; then
            while [[ $salir == 0 ]]; do
                if [[ $a == "\"\"" ]]; then
                    echo "Se requiere introducir una id."
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
                        
                        f=`echo "$a" | cut -c 2-5`
                        e=`echo "$a" | cut -c 2-5`.pdb
                        if [[ $encontrado == 1 ]]; then
                            echo "Si es una proteina."
                            if [[ ! -f "$e" ]]; then
                                echo "Se descargara la proteina."
                                wget https://files.rcsb.org/download/$e
                                
                                salir2=0
                                while [[ $salir2 == 0 ]]; do
                                    echo "Introduzca el rango en Angstrom para el ligando/ION"
                                    echo -n "---->"
                                    read rango
                                    
                                    re='^-?[0-9]+([.][0-9]+)?$'
                                    if ! [[ $rango =~ $re ]]; then
                                        echo "Valor no valido."
                                    else
                                        i=`echo "$f-$rango"`-1.svg
                                        if [[ ! -f "$i" ]]; then
                                            filtrar $e $f $rango
                                            echo "Los png han sido creados."
                                            
                                            salir=1
                                            salir2=1
                                        else
                                            echo "Los png con ese rango ya estaban creados."
                                            
                                            salir=1
                                            salir2=1
                                        fi
                                    fi
                                done
                            else
                                echo "La proteína ya se encuentra descargada."
                                
                                salir2=0
                                while [[ $salir2 == 0 ]]; do
                                    echo "Introduzca el rango en Angstrom para el ligando/ION"
                                    echo -n "---->"
                                    read rango
                                    
                                    re='^-?[0-9]+([.][0-9]+)?$'
                                    if ! [[ $rango =~ $re ]]; then
                                        echo "Valor no valido."
                                    else
                                        i=`echo "$f-$rango"`-1.svg
                                        if [[ ! -f "$i" ]]; then
                                            filtrar $e $f $rango
                                            echo "Los png han sido creados."
                                            
                                            salir=1
                                            salir2=1
                                        else
                                            echo "Los png con ese rango ya estaban creados."
                                            
                                            salir=1
                                            salir2=1
                                        fi
                                    fi
                                done
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
            clear
            
            cerrar=1
        fi
    done
else
    clear
    echo "No hay acceso a internet, no se puede continuar."
fi