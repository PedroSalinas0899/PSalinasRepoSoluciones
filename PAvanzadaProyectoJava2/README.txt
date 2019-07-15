Proyecto Java 2: F-Zero continuacion 

El proyecto es un programa hecho en java, el cual intenta simular un famoso videojuego de carreras el cual se llama F-Zero, sin embargo, lo que se pretende lograr ahora es la implementacion de un relator dentro de la carrera, al igual que elimninar la herencia de las naves usando interfaces en lugar de esta.

El juego consta con un solo modo de juego en donde se correrá una pista completamente lineal contra cierta cantidad de bots que escoja el jugador. La nave del jugador tendrá para equiparse con x cantidad de turbinas y seleccionar uno de los 3 combustibles, los cuales tienen características específicas.

Las naves de los bots serán equipadas de manera aleatoria, (si, pueden salir naves iguales para los bots o incluso naves bots que sean iguales a las del usuario).
Las naves tendrán la facultad de estropearse, lo cual está asociado a la cantidad de turbinas y combustible que lleven, y de este modo se quedarán quitas en la pista a la espera de un mecánico personal que reparara la nave.

Cada 2 segundos se imprimirá un tablero en pantalla el cual nos indicará de manera gráfica en que tramo de la pista se encuentra cada nave, utilizando pipes, las cuales irán desde el 1 al 100 y representara de manera porcentual (%) donde se encuentra situada cada nave. Al realizarse la carrera habrá un locutor el cual estará diciendo comentario acerca de los sucesos más importantes que ocurran cada 2 segundos en la carrera. La carrera no termina hasta que el ultimo competidor llegue a la meta. Al finalizar la carrera se imprimirán las posiciones en las que quedo cada uno, de haber empates uno se dará cuenta por que más de 1 competidor comparte determinada posición, lo que significa que ambas naves llegaron a la meta en el mismo intervalo de tiempo.

Para la realización de este proyecto se usó el lenguaje de programación Java 11, donde el objetivo principal era hacer uso de clases y/o objetos con la finalidad de entender cómo trabajan y operan este tipo de herramientas, las cuales son el enfoque principal de lo que es la POO.

Para la elaboración del programa, se utilizó el lenguaje de programación Java 11, donde la escritura de código estuvo limitada por conocimientos de la PEP-8 (la utilizada en Python, pero que sirve para darle más estilo al programa), donde podemos encontrar reglas como:

-El código del programa usa 4 (cuatro) espacios por indotación
-Usar espacios inmediatamente después de una coma, un punto y coma o dos puntos
-Usar espacios inmediatamente después de un operador de asignación
-Las funciones deben ser en minúscula, con las palabras separadas por un guion bajo, aplicándose éstos tanto como sea necesario para mejorar la legibilidad

Pre-requisitos:

-Tener instalada cualquier distribución de Linux, no inferior a 14.x.x, debido a la posible ausencia en la obtención de los paquetes requeridos para hacer un programa de este estilo.

Instalación:

-(Para el entorno linux)Ir al siguiente link https://www.linux.org/ y dirigirse a la pestaña de download donde se podrán encontrar todas las distribuciones de este sistema operativo, con guías incluidas y de manera completamente gratuita.

-Para poder instalar java es necesario seguir los siguientes pasos en la consola:

apt install openjdk-11-jre

apt-cache search openjdk jre

El IDE a utilizar será: Eclipse IDE for Java Developers, para instalar lo pueden realizar directamente desde la terminal utilizando los siguientes comandos:

#Descargar desde icb.utalca.cl usando wget

wget https://icb.utalca.cl/~fduran/eclipse-java-2019-03-R-linux-gtk-x86_64.tar.gz

#Descomprimir utilizando el comando tar
tar xvf eclipse-java-2019-03-R-linux-gtk-x86_64.tar.gz

#ejecutar
cd eclipse
./eclipse

P.D: Tutorial completamente citado de nuestro profesor de programación avanzada, Fabio Esteban Duran Verdugo.

Detalles:

El programa es funcional, sin embargo, no hasta el punto que me gustaría, el problema más grande que he tenido han sido sin duda, que valores otórgales a los aumentos de aceleraciones y/o velocidad, con tal de hacer que no aparezcan valores absurdamente grandes, aunque en la primera parte del proyecto esto no era para nada malo, en esta si lo es, debido a que no se logra expresar de buena forma la selectividad de comentarios a decir para el relator, haciendo que siempre diga una frase repetida lo cual le quita la veracidad al programa a la hora de pensar si es que de verdad hay variedad en ellas, aunque solo bastaría con ver el código para dar en cuenta que no es así. 

Construido con:
Para la elaboración del programa se utilizó:
-Editor de texto Eclipse
-Constructor de diagrama UML, Dia



Desarrolladores:
-----------------------------------Pedro Salinas Soto------------------------------------
