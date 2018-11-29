Jail_max_beta

El proyecto es un programa el cual tiene como finalidad uilizarse en la distribucion administrativa de reos en una carcel, 
contando con la funcionalidad de inicio de sesion, la cual podra ser para 3 usuarios, el Alcaide, la secretaria o los guardias, quienes cuentan cada uno con diversas opciones; Los presos tendran un nombre, apellido, rut, nacionalidad, celda, sentencia, estado y una descripcion:

-Guardia: solo revisa hoja de vida, y lista de prisioneros
-Secretaria: puede agregar y cambiar describipcion y sentencia
-Alcaide: cambia estado de los prisioneros

Para poder concretar nuestro proyecto de manera efectiva, ambos integrantes hicimos uso de github para poder traspasarnos nuestros avances de manera optina (link del repositorio donde se encuentran esos avances https://github.com/PedroSalinas0899/PSalinasRepoSoluciones/tree/master/Proyecto3Avances
Para la elaboracion del programa, se utlizo el lenguaje python el cual estuvo restringido sobre "nuestros" conocmientos de la PEP-8, donde podemos encontrar reglas como:

-El codigo del programa usa 4 (cuatro) espacios por indentación
-Usar espacios nmediatamente despues de una coma, un punto y coma o dos puntos-Usar espacios nmediatamente despues de un operador de asignación
-Las funciones deben ser en minúscula, con las palabras separadas
por un guión bajo, aplicándose éstos tanto como sea necesario para
mejorar la legibilidad.

Pre-requisitos:

-Se recomienda tener instalada cualquier distribucion de Linux (ya que, por ejempplo en windowns, es recurrente que ocurran percanses)
-Para poder correr el programa se requiere tener instalado Python v3.x, ya sea en su sistema operativo o en un entorno virtual previamente creado (se recomienda encarecidamente el entorno virtual y de hecho el readme está orientado a hacer uso de el).
-Se necesita tambien tener instalado glade en la maquina y pygobject en el entorno virtual.

Instalacion:

-Ir al siguiente link https://www.linux.org/ y dirigirse a la pestaña de download donde se podran encontrar todas las distribuciones de este sistema operativo, con guias incluidas y de manera completamente gratuita.
-Para la instalacion de Python v3.x, se recomienda visitar el siguiente link donde se muestra un pequeño tutorial de como instalarlo de manera correcta, https://srvbioinf1.utalca.cl/wiki/programacion/python/instalacion
-Y finalmente si se opta por utilizar un entorno virtual (recomendado), favor de dirigirse a este link donde hay un tutorial perfectamente detallado de como crear uno y hacer uso de este https://srvbioinf1.utalca.cl/wiki/programacion/python/entorno-virtual
-°De otra forma recomiendo que se descargue el siguiente script y se haga uso de el para poder descargar python de una forma mas sencilla (ademas de dejar todo listo para hacer el entorno virtual y dejar los comandos listos para ello) http://gitlab.com/confor/python/raw/master/instalar-python-nuevo.sh
-Para instalar glade, abrir la terminal y escribir: "apt-get install", sin las comillas.
-Para instalar pygobject escribir en la terminal y con el entorno virtual abierto: "pip install pygobject", sin las comillas.

Detalles:

El programa en general funciona, pero es bastante poco funcional si es que quisieramos usarlo en la vida real, debido no existe un registro de tiempo para que lo de las sentencias pueda ser llebadas a cabo en tiempo real, al igual que su liberacion se altere con respecto a esto, y la razon de el porque ocurrio esto fue la poca informacion que se tenia sobre las herramientas que estabamos utilizando, la creacion del codigo fue hecha practicamente a ciegas, error tras error y guiandonos exclusivamente de los ejemplos que habia puesto el profesor Fabio en Educandus, ademas de que se sabia muy poco sobre Glade y buscar cosas en internet sobre este resultaba una tarea casi inutil, ya que, la poca informacion que habia estaba en ingles y se utilizaban version muy antiguas.

Construido con:

Para la elaboracion de el programa se utilizo:
-Editor de texto gnome-builder y Geany
-Glade

Desarrolladores:
----------Benjamin Sanzana y Pedro Salinas--------------------------
