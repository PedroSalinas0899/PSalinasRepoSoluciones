Proyecto 1: Graficar proteínas

El proyecto es un script, el cual tiene la finalidad de verificar si es que se tiene conexión a internet, y posterior a esto iniciar un panel interactivo en el cual se le pedirá al usuario introducir el nombre de una proteína para hacer el match del nombre de esta, en una base de datos, la cual estará representada en un archivo de texto que se descargará anteriormente por el script.

Luego de que se vea si el código coincide con el de una proteína, se procederá a descargarla de la base de datos de proteínas online mas grande del mundo, protein data bank. Se descargará un archivo el cual tendrá mucha información acerca de la proteína, lo que es relevante son el nombre del átomo, el aminoácido en donde se encuentra, la cadena donde están los aminoácidos y el residuo. Sera necesario filtrar toda esta información y para ello se utilizarán archivos temporales que posteriormente serán eliminados.


Una vez filtrada toda la información necesaria, se creará un archivo .dot el cual se le introducirán todos los comandos necesarios para luego hacer un archivo .png que será un diagrama de como esta constituida la proteína, con todos los átomos, aminoácidos y cadenas que este constituya. 


Para la elaboración del programa, se utilizó el lenguaje de scripting bash el cual estuvo restringido sobre "nuestros" conocimientos de la PEP-8 (la se utiliza en Python, pero sirve para darle más estilo al programa), donde podemos encontrar reglas como:

-El código del programa usa 4 (8 tambien es valido para no tener que cambiar por tener codigo ya hecho con 8) espacios por indentación
-Usar espacios inmediatamente después de una coma, un punto y coma o dos puntos-Usar espacios inmediatamente después de un operador de asignación
-Las funciones deben ser en minúscula, con las palabras separadas
por un guion bajo, aplicándose éstos tanto como sea necesario para
mejorar la legibilidad.

Pre-requisitos:

-Tener instalada cualquier distribución de Linux.

Instalación:

-Ir al siguiente link https://www.linux.org/ y dirigirse a la pestaña de download donde se podrán encontrar todas las distribuciones de este sistema operativo, con guías incluidas y de manera completamente gratuita.

Detalles:

El programa en general funciona bastante bien, tiene detalles como por ejemplo a la hora de cortar el internet previamente al inicio del programa cuando tiene que descargar cosas, debido a que no se alcanzo a implementar en la zona intermedia el script esta restricción, también los códigos de las proteínas se deben escribir con letras mayúsculas y si se escriben con minúsculas no tomara el código como verídico, debido a que como en la base de datos estaban ya con mayúsculas, se decidió que por mantener la formalidad y autenticidad de donde se esta buscando el dato, no hacer adaptaciones con respecto a esto. 

Construido con:

Para la elaboración del programa se utilizó:
-Editor de texto gnome-builder



Desarrolladores:
-----------------------------------Pedro Salinas Soto------------------------------------
