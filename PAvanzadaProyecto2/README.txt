Proyecto 1: Graficador de iones/Ligando de prote�nas 

El proyecto es un script, el cual tiene la finalidad de verificar si es que se tiene conexi�n a internet, y posterior a esto iniciar un panel interactivo en el cual se le pedir� al usuario introducir el nombre de una prote�na para hacer el match del nombre de esta, en una base de datos, la cual estar� representada en un archivo de texto que se descargar� anteriormente por el script.

Luego de que se vea si el c�digo coincide con el de una prote�na, se proceder� a descargarla de la base de datos de prote�nas online m�s grande del mundo, protein data bank. Se descargar� un archivo el cual tendr� mucha informaci�n acerca de la prote�na, lo que es relevante son el nombre del �tomo, el amino�cido en donde se encuentra, la cadena donde est�n los amino�cidos, el residuo y las coordenadas x,y,z que tiene cada �tomos para poder saber la localizaci�n de este con respecto a otras mol�culas; tambi�n ser� necesario extraer la informaci�n de los iones y ligandos que se encuentran en cada prote�na, donde ser� muy importante tener el nombre que tendr� cada uno de estos, el residuo, la cadena y las coordenadas x,y,z para poder calcular su espacio tridimensional y calcular distancias con cada amino�cido de la prote�na, con tan de que si existe match, estos se unir�n. Este rango deber� ser introducido por el usuario y estar� en la medida de �ngstrom, la cual equivale a 0,000.000.000.1 metros. Sera necesario filtrar toda esta informaci�n mediante la utilizaci�n de awk y para ello se utilizar�n archivos temporales que posteriormente ser�n eliminados.

Una vez filtrada toda la informaci�n necesaria, se crear� un archivo.dot por cada ligando/ion el cual se le introducir�n todos los comandos definidos para usar Graphviz necesarios de la para luego hacer un archivo .png por cada ligando ion que ser� un diagrama de c�mo est� constituida ese sector de la prote�na con cada amino�cido unido al ligando/ion seg�n el rango introducido, con todos los �tomos, amino�cidos y cadenas que este constituya, informaci�n muy �til que sirve para ver las posibles interacciones entre mol�culas de una proteina. 
Para la elaboraci�n del programa, se utiliz� el lenguaje de scripting bash el cual estuvo restringido sobre "nuestros" conocimientos de la PEP-8 (la se utiliza en Python, pero sirve para darle m�s estilo al programa), donde podemos encontrar reglas como:

-El c�digo del programa usa 4 (cuatro) espacios por indotaci�n
-Usar espacios inmediatamente despu�s de una coma, un punto y coma o dos puntos
-Usar espacios inmediatamente despu�s de un operador de asignaci�n
-Las funciones deben ser en min�scula, con las palabras separadas por un guion bajo, aplic�ndose �stos tanto como sea necesario para mejorar la legibilidad

Pre-requisitos:

-Tener instalada cualquier distribuci�n de Linux, no inferior a 14.x.x, debido a la posible ausencia de los paquetes requeridos para hacer un programa de este estilo.

Instalaci�n:

-Ir al siguiente link https://www.linux.org/ y dirigirse a la pesta�a de download donde se podr�n encontrar todas las distribuciones de este sistema operativo, con gu�as incluidas y de manera completamente gratuita.

Detalles:
El programa en general funciona bastante bien, tiene detalles como por ejemplo a la hora de cortar el internet previamente al inicio del programa cuando tiene que descargar cosas, debido a que no se alcanz� a implementar en la zona intermedia el script esta restricci�n, tambi�n los c�digos de las prote�nas se deben escribir con letras may�sculas y si se escriben con min�sculas no tomara el c�digo como ver�dico, debido a que como en la base de datos estaban ya con may�sculas, se decidi� que por mantener la formalidad y autenticidad de donde se est� buscando el dato.

Construido con:
Para la elaboraci�n del programa se utiliz�:
-Editor de texto gnome-builder



Desarrolladores:
-----------------------------------Pedro Salinas Soto------------------------------------