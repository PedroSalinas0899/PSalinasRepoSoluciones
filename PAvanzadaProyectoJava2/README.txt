Proyecto Java 2: F-Zero continuacion 

El proyecto es un programa hecho en java, el cual intenta simular un famoso videojuego de carreras el cual se llama F-Zero, sin embargo, lo que se pretende lograr ahora es la implementacion de un relator dentro de la carrera, al igual que elimninar la herencia de las naves usando interfaces en lugar de esta.

El juego consta con un solo modo de juego en donde se correr� una pista completamente lineal contra cierta cantidad de bots que escoja el jugador. La nave del jugador tendr� para equiparse con x cantidad de turbinas y seleccionar uno de los 3 combustibles, los cuales tienen caracter�sticas espec�ficas.

Las naves de los bots ser�n equipadas de manera aleatoria, (si, pueden salir naves iguales para los bots o incluso naves bots que sean iguales a las del usuario).
Las naves tendr�n la facultad de estropearse, lo cual est� asociado a la cantidad de turbinas y combustible que lleven, y de este modo se quedar�n quitas en la pista a la espera de un mec�nico personal que reparara la nave.

Cada 2 segundos se imprimir� un tablero en pantalla el cual nos indicar� de manera gr�fica en que tramo de la pista se encuentra cada nave, utilizando pipes, las cuales ir�n desde el 1 al 100 y representara de manera porcentual (%) donde se encuentra situada cada nave. Al realizarse la carrera habr� un locutor el cual estar� diciendo comentario acerca de los sucesos m�s importantes que ocurran cada 2 segundos en la carrera. La carrera no termina hasta que el ultimo competidor llegue a la meta. Al finalizar la carrera se imprimir�n las posiciones en las que quedo cada uno, de haber empates uno se dar� cuenta por que m�s de 1 competidor comparte determinada posici�n, lo que significa que ambas naves llegaron a la meta en el mismo intervalo de tiempo.

Para la realizaci�n de este proyecto se us� el lenguaje de programaci�n Java 11, donde el objetivo principal era hacer uso de clases y/o objetos con la finalidad de entender c�mo trabajan y operan este tipo de herramientas, las cuales son el enfoque principal de lo que es la POO.

Para la elaboraci�n del programa, se utiliz� el lenguaje de programaci�n Java 11, donde la escritura de c�digo estuvo limitada por conocimientos de la PEP-8 (la utilizada en Python, pero que sirve para darle m�s estilo al programa), donde podemos encontrar reglas como:

-El c�digo del programa usa 4 (cuatro) espacios por indotaci�n
-Usar espacios inmediatamente despu�s de una coma, un punto y coma o dos puntos
-Usar espacios inmediatamente despu�s de un operador de asignaci�n
-Las funciones deben ser en min�scula, con las palabras separadas por un guion bajo, aplic�ndose �stos tanto como sea necesario para mejorar la legibilidad

Pre-requisitos:

-Tener instalada cualquier distribuci�n de Linux, no inferior a 14.x.x, debido a la posible ausencia en la obtenci�n de los paquetes requeridos para hacer un programa de este estilo.

Instalaci�n:

-(Para el entorno linux)Ir al siguiente link https://www.linux.org/ y dirigirse a la pesta�a de download donde se podr�n encontrar todas las distribuciones de este sistema operativo, con gu�as incluidas y de manera completamente gratuita.

-Para poder instalar java es necesario seguir los siguientes pasos en la consola:

apt install openjdk-11-jre

apt-cache search openjdk jre

El IDE a utilizar ser�: Eclipse IDE for Java Developers, para instalar lo pueden realizar directamente desde la terminal utilizando los siguientes comandos:

#Descargar desde icb.utalca.cl usando wget

wget https://icb.utalca.cl/~fduran/eclipse-java-2019-03-R-linux-gtk-x86_64.tar.gz

#Descomprimir utilizando el comando tar
tar xvf eclipse-java-2019-03-R-linux-gtk-x86_64.tar.gz

#ejecutar
cd eclipse
./eclipse

P.D: Tutorial completamente citado de nuestro profesor de programaci�n avanzada, Fabio Esteban Duran Verdugo.

Detalles:

El programa es funcional, sin embargo, no hasta el punto que me gustar�a, el problema m�s grande que he tenido han sido sin duda, que valores ot�rgales a los aumentos de aceleraciones y/o velocidad, con tal de hacer que no aparezcan valores absurdamente grandes, aunque en la primera parte del proyecto esto no era para nada malo, en esta si lo es, debido a que no se logra expresar de buena forma la selectividad de comentarios a decir para el relator, haciendo que siempre diga una frase repetida lo cual le quita la veracidad al programa a la hora de pensar si es que de verdad hay variedad en ellas, aunque solo bastar�a con ver el c�digo para dar en cuenta que no es as�. 

Construido con:
Para la elaboraci�n del programa se utiliz�:
-Editor de texto Eclipse
-Constructor de diagrama UML, Dia



Desarrolladores:
-----------------------------------Pedro Salinas Soto------------------------------------
