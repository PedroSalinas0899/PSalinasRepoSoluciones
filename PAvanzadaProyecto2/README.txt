Proyecto 1: Graficador de iones/Ligando de proteínas 

El proyecto es un script, el cual tiene la finalidad de verificar si es que se tiene conexión a internet, y posterior a esto iniciar un panel interactivo en el cual se le pedirá al usuario introducir el nombre de una proteína para hacer el match del nombre de esta, en una base de datos, la cual estará representada en un archivo de texto que se descargará anteriormente por el script.

Luego de que se vea si el código coincide con el de una proteína, se procederá a descargarla de la base de datos de proteínas online más grande del mundo, protein data bank. Se descargará un archivo el cual tendrá mucha información acerca de la proteína, lo que es relevante son el nombre del átomo, el aminoácido en donde se encuentra, la cadena donde están los aminoácidos, el residuo y las coordenadas x,y,z que tiene cada átomos para poder saber la localización de este con respecto a otras moléculas; también será necesario extraer la información de los iones y ligandos que se encuentran en cada proteína, donde será muy importante tener el nombre que tendrá cada uno de estos, el residuo, la cadena y las coordenadas x,y,z para poder calcular su espacio tridimensional y calcular distancias con cada aminoácido de la proteína, con tan de que si existe match, estos se unirán. Este rango deberá ser introducido por el usuario y estará en la medida de Ángstrom, la cual equivale a 0,000.000.000.1 metros. Sera necesario filtrar toda esta información mediante la utilización de awk y para ello se utilizarán archivos temporales que posteriormente serán eliminados.

Una vez filtrada toda la información necesaria, se creará un archivo.dot por cada ligando/ion el cual se le introducirán todos los comandos definidos para usar Graphviz necesarios de la para luego hacer un archivo .png por cada ligando ion que será un diagrama de cómo está constituida ese sector de la proteína con cada aminoácido unido al ligando/ion según el rango introducido, con todos los átomos, aminoácidos y cadenas que este constituya, información muy útil que sirve para ver las posibles interacciones entre moléculas de una proteina. 
Para la elaboración del programa, se utilizó el lenguaje de scripting bash el cual estuvo restringido sobre "nuestros" conocimientos de la PEP-8 (la se utiliza en Python, pero sirve para darle más estilo al programa), donde podemos encontrar reglas como:

-El código del programa usa 4 (cuatro) espacios por indotación
-Usar espacios inmediatamente después de una coma, un punto y coma o dos puntos
-Usar espacios inmediatamente después de un operador de asignación
-Las funciones deben ser en minúscula, con las palabras separadas por un guion bajo, aplicándose éstos tanto como sea necesario para mejorar la legibilidad

Pre-requisitos:

-Tener instalada cualquier distribución de Linux, no inferior a 14.x.x, debido a la posible ausencia de los paquetes requeridos para hacer un programa de este estilo.

Instalación:

-Ir al siguiente link https://www.linux.org/ y dirigirse a la pestaña de download donde se podrán encontrar todas las distribuciones de este sistema operativo, con guías incluidas y de manera completamente gratuita.

Detalles:
El programa en general funciona bastante bien, tiene detalles como por ejemplo a la hora de cortar el internet previamente al inicio del programa cuando tiene que descargar cosas, debido a que no se alcanzó a implementar en la zona intermedia el script esta restricción, también los códigos de las proteínas se deben escribir con letras mayúsculas y si se escriben con minúsculas no tomara el código como verídico, debido a que como en la base de datos estaban ya con mayúsculas, se decidió que por mantener la formalidad y autenticidad de donde se está buscando el dato.

Construido con:
Para la elaboración del programa se utilizó:
-Editor de texto gnome-builder



Desarrolladores:
-----------------------------------Pedro Salinas Soto------------------------------------