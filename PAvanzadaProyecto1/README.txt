Proyecto 1: Graficar prote�nas

El proyecto es un script, el cual tiene la finalidad de verificar si es que se tiene conexi�n a internet, y posterior a esto iniciar un panel interactivo en el cual se le pedir� al usuario introducir el nombre de una prote�na para hacer el match del nombre de esta, en una base de datos, la cual estar� representada en un archivo de texto que se descargar� anteriormente por el script.

Luego de que se vea si el c�digo coincide con el de una prote�na, se proceder� a descargarla de la base de datos de prote�nas online mas grande del mundo, protein data bank. Se descargar� un archivo el cual tendr� mucha informaci�n acerca de la prote�na, lo que es relevante son el nombre del �tomo, el amino�cido en donde se encuentra, la cadena donde est�n los amino�cidos y el residuo. Sera necesario filtrar toda esta informaci�n y para ello se utilizar�n archivos temporales que posteriormente ser�n eliminados.


Una vez filtrada toda la informaci�n necesaria, se crear� un archivo .dot el cual se le introducir�n todos los comandos necesarios para luego hacer un archivo .png que ser� un diagrama de como esta constituida la prote�na, con todos los �tomos, amino�cidos y cadenas que este constituya. 


Para la elaboraci�n del programa, se utiliz� el lenguaje de scripting bash el cual estuvo restringido sobre "nuestros" conocimientos de la PEP-8 (la se utiliza en Python, pero sirve para darle m�s estilo al programa), donde podemos encontrar reglas como:

-El c�digo del programa usa 4 (cuatro) espacios por indentaci�n
-Usar espacios inmediatamente despu�s de una coma, un punto y coma o dos puntos-Usar espacios inmediatamente despu�s de un operador de asignaci�n
-Las funciones deben ser en min�scula, con las palabras separadas
por un guion bajo, aplic�ndose �stos tanto como sea necesario para
mejorar la legibilidad.

Pre-requisitos:

-Tener instalada cualquier distribuci�n de Linux.

Instalaci�n:

-Ir al siguiente link https://www.linux.org/ y dirigirse a la pesta�a de download donde se podr�n encontrar todas las distribuciones de este sistema operativo, con gu�as incluidas y de manera completamente gratuita.

Detalles:

El programa en general funciona bastante bien, tiene detalles como por ejemplo a la hora de cortar el internet previamente al inicio del programa cuando tiene que descargar cosas, debido a que no se alcanzo a implementar en la zona intermedia el script esta restricci�n, tambi�n los c�digos de las prote�nas se deben escribir con letras may�sculas y si se escriben con min�sculas no tomara el c�digo como ver�dico, debido a que como en la base de datos estaban ya con may�sculas, se decidi� que por mantener la formalidad y autenticidad de donde se esta buscando el dato, no hacer adaptaciones con respecto a esto. 

Construido con:

Para la elaboraci�n del programa se utiliz�:
-Editor de texto gnome-builder



Desarrolladores:
-----------------------------------Pedro Salinas Soto------------------------------------
