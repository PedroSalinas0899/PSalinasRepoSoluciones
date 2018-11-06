from time import sleep
import random
import copy
import os
import json
BLOQUE = '█'
x = 15
y = 35

def cargar_json_ensenanza():

    try:
        with open('ensenanza.json',"r") as file:
            data2 = json.load(file)

    except IOError:
        data2 = {}

    return data2

def cargar_json_matriz():

    try:
        with open('matriz.json',"r") as file:
            data1 = json.load(file)

    except IOError:
        data1 = []

    return data1

def revision_matriz_repetida(data1, matriz):
    indice = 0

    #Si, la lista data1 no tiene elementos se agrega el primer laberinto y se nombra como 0.
    if (len(data1) == 0):
        data1.append(matriz)
        with open('matriz.json',"w") as file:
            json.dump(data1,file, indent = 4)
    
    #Cuando data1 ya tiene varios labertintos procede a compararlos, si no encuentra una copia procede a identificar al laberinto.
    elif (len(data1) != 0):

        for i in range(len(data1)):
            if(matriz == data1[i]):
                indice = i
                break
                
            elif (matriz != data1[i]):
                if(i == (len(data1)- 1)):
                    data1.append(matriz)
                    indice = len(data1) - 1
                    
        with open('matriz.json',"w") as file:
            json.dump(data1,file, indent = 4)
    
    return indice

def subir_coordenadas(data2, coordenadas, indice):

    #Si existe al menos 1 ensenanza aux es true, por lo contrario false
    if ('laberinto'+str(indice) in data2):
        aux = True
    else:
        aux = False

    if(aux == False):
        data2['laberinto'+str(indice)] = []
        ensenanza = len(data2['laberinto'+str(indice)])
        data2['laberinto'+str(indice)].append({'ensenanza'+str(ensenanza): coordenadas})
        with open('ensenanza.json',"w") as file:
            json.dump(data2,file, indent = 4)

    elif(aux == True):
        ensenanza = len(data2['laberinto'+str(indice)])
        data2['laberinto'+str(indice)].append({'ensenanza'+str(ensenanza): coordenadas})
        with open('ensenanza.json',"w") as file:
            json.dump(data2,file, indent = 4)

def revision(matriz,k,a):
    #revision para saber donde detenerse en la creacion de caminos
    contador = 0
    if k == 0:
        k = k+1
    if k == x-1:
        k = k-1
    if a == 0:
        a = a+1
    if a == y-2:
        a = a-1

    for i in range(-1,2):
        for j in range(-1,2):
            if matriz[k+i][a+j] == ' ':
                contador = contador+1

    c = matriz[k-1][a-1]
    v = matriz[k-1][a+1]
    b = matriz[k+1][a-1]
    n = matriz[k+1][a+1]


    if c == ' ' and v == ' ':
        contador = 10
    if c == ' ' and b == ' ':
        contador = 10
    if c == ' ' and n == ' ':
        contador = 10
    if v == ' ' and c == ' ':
        contador = 10
    if v == ' ' and b == ' ':
        contador = 10
    if v == ' ' and n == ' ':
        contador = 10
    if n == ' ' and c == ' ':
        contador = 10
    if n == ' ' and v == ' ':
        contador = 10
    if n == ' ' and b == ' ':
        contador = 10

    return contador

def laberinto(matriz, k):
    #despejar camino que si o si empiece desde el inicio hasta donde llegue
    a = 1
    b = y-3
    matriz[k][a] = ' '

    pausa = 1000
    while pausa >= 1:
        comodin_1 = k
        comodin_2 = a
        movimiento = random.randint(1,5)
        #derecha
        if movimiento == 1:
            a = a+1
            revisar = revision(matriz,k,a)
            if a != b-1 and revisar <= 2:
                matriz[k][a] = ' '
            else:
                a = a-1
        #arriba
        elif movimiento == 2:
            k = k-1
            revisar = revision(matriz,k,a)
            if k != 0 and revisar <= 2:
                matriz[k][a] = ' '
            else:
                k = k+1
        #abajo
        elif movimiento == 3:
            k = k+1
            revisar = revision(matriz,k,a)
            if k != x-1 and revisar <= 2:
                matriz[k][a]=' '
            else:
                k = k-1
        #izquierda
        elif movimiento == 4:
            a = a-1
            revisar = revision(matriz,k,a)
            if a != 0 and revisar <= 2:
                matriz[k][a] = ' '
            else:
                a = a+1
        if comodin_1 == k and comodin_2 == a:
            pausa = pausa-1

#despejar si o si un camino que vaya desde el final hasta donde llegue
def laberinto_parte_2(matriz, l):
    
    matriz[l][y-2] = ' '
    k = l
    a = y-7
    b = y-3
    pausa = 1000
    while pausa >= 1:
        comodin_1 = k
        comodin_2 = a
        movimiento = random.randint(1,5)
        #derecha
        if movimiento == 1:
            a = a+1
            revisar = revision(matriz,k,a)
            if a != b-1 and revisar <= 2:
                matriz[k][a] = ' '
            else:
                a = a-1
        #arriba
        elif movimiento == 2:
            k = k-1
            revisar = revision(matriz,k,a)
            if k != 0 and revisar <= 2:
                matriz[k][a] = ' '
            else:
                k = k+1
        #abajo
        elif movimiento == 3:
            k = k+1
            revisar = revision(matriz,k,a)
            if k != x-1 and revisar <= 2:
                matriz[k][a]=' '
            else:
                k = k-1
        #izquierda
        elif movimiento == 4:
            a = a-1
            revisar = revision(matriz,k,a)
            if a != 0 and revisar <= 2:
                matriz[k][a] = ' '
            else:
                a = a+1
        if comodin_1 == k and comodin_2 == a:
            pausa = pausa-1
    completar_laberinto(matriz)

#realizar un despeje total de el laberinto, creando muchos caminos hasta donde lleguen
def completar_laberinto(matriz):
    
    b = y-3
    detenerse = 1000
    while detenerse >= 1:
        random_x = random.randint(1,x-1)
        random_y = random.randint(1,y-5)
        if matriz[random_x][random_y] == ' ':
            pausa = 100
            while pausa >= 1:
                comodin_1 = random_x
                comodin_2 = random_y
                movimiento = random.randint(1,5)
                if movimiento == 1:
                    random_y = random_y+1
                    revisar = revision(matriz,random_x,random_y)
                    if random_y != b-1 and revisar <= 2:
                        matriz[random_x][random_y] = ' '
                    else:
                        random_y = random_y-1

                elif movimiento == 2:
                    random_x = random_x-1
                    revisar = revision(matriz,random_x,random_y)
                    if random_x != 0 and revisar <= 2:
                        matriz[random_x][random_y] = ' '
                    else:
                        random_x = random_x+1

                elif movimiento == 3:
                    random_x = random_x+1
                    revisar = revision(matriz,random_x,random_y)
                    if random_x != x-1 and revisar <= 2:
                        matriz[random_x][random_y]=' '
                    else:
                        random_x = random_x-1

                elif movimiento == 4:
                    random_y = random_y-1
                    revisar = revision(matriz,random_x,random_y)
                    if random_y != 0 and revisar <= 2:
                        matriz[random_x][random_y] = ' '

                    else:
                        random_y = random_y+1
                if comodin_1 == random_x and comodin_2 == random_y:
                    pausa = pausa-1
            detenerse = detenerse-1
            
            
#eliminacion de estructuras, las cuales forman diagonales que bloquean caminos
def rellenar(matriz, k ,l):
    
    for i in range(1,x-1):
        for j in range(2,y-7):
            w = random.randint(0,2)
            if matriz[i][j] == ' ':
                if matriz[i+1][j-1] == ' ':
                    if matriz[i][j-1] == BLOQUE:
                        if matriz[i+1][j] == BLOQUE:
                            if w == 0:
                                matriz[i+1][j] = ' '
                            elif w == 1:
                                matriz[i][j-1] = ' '
            elif matriz[i][j-1] == ' ':
                if matriz[i+1][j] == ' ':
                    if matriz[i][j] == BLOQUE:
                        if matriz[i+1][j-1] == BLOQUE:
                            if w == 0:
                                matriz[i][j] = ' '
                            elif w == 1:
                                matriz[i+1][j-1] = ' '
    rellenar_2(matriz, k ,l)
    
    
#eliminacion de estructuras, las cuales forman 3 cuadrados negro verticales/horizontales
#y bloquean caminos hacia la victoria    
def rellenar_2(matriz, k ,l):
    for i in range(1,x-1):
        for j in range(2,y-2):
            if matriz[i][j] == BLOQUE:
                if matriz[i+1][j] == BLOQUE:
                    if matriz[i-1][j] == BLOQUE:
                        if matriz[i-1][j-1] == ' ':
                            if matriz[i][j-1] == ' ':
                                if matriz[i+1][j-1] == ' ':
                                    if matriz[i-1][j+1] == ' ':
                                        if matriz[i][j+1] == ' ':
                                            if matriz[i+1][j+1] == ' ':
                                                matriz[i][j] = ' '

    for i in range(1,x-1):
        for j in range(2,y-2):
            if matriz[i][j] == BLOQUE:
                if matriz[i][j-1] == BLOQUE:
                    if matriz[i][j+1] == BLOQUE:
                        if matriz[i-1][j-1] == ' ':
                            if matriz[i-1][j] == ' ':
                                if matriz[i-1][j+1] == ' ':
                                    if matriz[i+1][j-1] == ' ':
                                        if matriz[i+1][j] == ' ':
                                            if matriz[i+1][j+1] == ' ':
                                                matriz[i][j] = ' '

    for i in range(-1,2):
        for w in range(1,4):
            matriz[k+i][w] = ' '
        for i in range(1,8):
            matriz[l][y-i] = ' '

    for i in range(0,y-1):
        matriz[0][i] = BLOQUE
    for i in range(0,y-1):
        matriz[x-1][i] = BLOQUE


#Imprimir una matriz sin movimientos
def imprimir(matriz):

    for i in range (0,x):
        for k in range(0,y):
            print(matriz[i][k],end="")
        print()
        
#Imprimir caminos largo/corto
def imprimircaminos(matriz, coordenadas, k, b):

    for i in range (len(coordenadas)):
        if(i == 0 or i %2 == 0):
            fila = coordenadas[i]
            columna = coordenadas[i+1]
            if(fila == k and columna == b):
                indice_eliminar= i+1

    for v in range (0, indice_eliminar+1):
        j=0
        coordenadas.pop(j)

    for i in range (len(coordenadas)):
        if(i == 0 or i %2 == 0):
            fila = coordenadas[i]
            columna = coordenadas[i+1]
            matriz[fila][columna] = 'X'

    for i in range (0,x):
        for j in range(0,y):
            print(matriz[i][j],end="")
        print()
        
        
# Imprime solo un camino con forma de circulo en el mapa.
def imprimir_circulo(matriz, t, primeraX, segundaY, indice):

    with open('ensenanza.json',"r") as file:
            data2 = json.load(file)

    coordenadas = data2['laberinto'+str(indice)][t]['ensenanza'+str(t)]

    for i in range(primeraX, segundaY+1):

        if(i == 0 or i %2 == 0):
            fila = coordenadas[i]
            columna = coordenadas[i+1]
            matriz[fila][columna]= 'X'

    imprimir(matriz)


#Luego de hacer un movimiento el espacio de atras se vuelve en blanco
def movimiento(matriz, k, b, mov):

    matriz[k][b] = 'X'

    if(mov=='A'):
        matriz[k][b+1]= ' '
    elif(mov == 'S'):
        matriz[k-1][b] = ' '
    elif(mov == 'D'):
        matriz[k][b-1] = ' '
    elif(mov == 'W'):
        matriz[k+1][b] = ' '
        
        
#Limpia la matriz, de manera que no existan movimientos
def limpiarmatriz(matriz,k ,b):

    for i in range (0,x):
        for j in range(0,y):
            if(matriz[i][j] == 'X'):
                matriz[i][j] = ' '
    matriz[k][b] = 'X'

#Busca camino más largo y corto
def revision_camino(indice, buscar_camino, k, b):

    coordenadas = 0
    retornar = 0
    contador = 0

    with open('ensenanza.json',"r") as file:
        data2 = json.load(file)

    aux1 = 1000
    aux2 = 0

    for t in range(len(data2['laberinto'+str(indice)])):
        coordenadas = data2['laberinto'+str(indice)][t]['ensenanza'+str(t)]
        for i in range (len(coordenadas)):
                if(i == 0 or i %2 == 0):
                    fila = coordenadas[i]
                    columna = coordenadas[i+1]
                    #revisar si la coordenada actual se encuentra en la ensenanza
                    if(fila == k and columna == b):
                        if(buscar_camino == 'corto'):
                            if(aux1 > len(data2['laberinto'+str(indice)][t]['ensenanza'+str(t)])):
                                aux1 = len(data2['laberinto'+str(indice)][t]['ensenanza'+str(t)])
                                retornar = t
                        elif(buscar_camino == 'largo'):
                            if(aux2 < len(data2['laberinto'+str(indice)][t]['ensenanza'+str(t)])):
                                aux2 = len(data2['laberinto'+str(indice)][t]['ensenanza'+str(t)])
                                retornar = t
                        contador = 1
    if(contador == 0):
        print('no existe aprendizaje')
        retornar = 'False'

    return retornar

def buscarcirculo(matriz, k, b, indice):

    aux = 'False'

    with open('ensenanza.json',"r") as file:
                data2 = json.load(file)


    for t in range(len(data2['laberinto'+str(indice)])):
        coordenadas = data2['laberinto'+str(indice)][t]['ensenanza'+str(t)]
        for i in range (len(coordenadas)):
                if(i == 0 or i %2 == 0):
                    fila = coordenadas[i]
                    columna = coordenadas[i+1]
                    if(fila == k and columna == b):
                        primeraX = i
                        primeraY = i+1
                        for j in range (primeraY+1, len(coordenadas)):
                            if(j == 0 or j %2 == 0):
                                fila = coordenadas[j]
                                columna = coordenadas[j+1]
                                if(fila == k and columna == b):
                                    segundaX = j
                                    segundaY = j+1
                                    if(segundaX - primeraX >= 16 and segundaY - primeraY >= 16):
                                        imprimir_circulo(matriz, t, primeraX, segundaY, indice)
                                        aux = 'True'
    if (aux == 'False'):
        print("En esta cordenada no existe camino en circulo, o no hay aprendizaje")

def menu(matriz, matriz2, k, b, indice):
    opc = 0
    salir = 0
    coordenadas = 0

    while(salir != 1):
        print("\033[4;35;47m"+"----------- MENÚ ----------- "+"\033[0;m")
        print("\033[4;35;47m"+"1.- INDICAR CAMINO MÁS CORTO "+"\033[0;m")
        print("\033[4;35;47m"+"2.- INDICAR CAMINO MÁS LARGO"+"\033[0;m")
        print("\033[4;35;47m"+"3.- ¿DE DONDE VENGO?"+"\033[0;m")
        print("\033[4;35;47m"+"4.- BUSCAR UN CAMINO QUE SEA CIRCULO"+"\033[0;m")
        print("\033[4;35;47m"+"5.- SEGUIR JUGAN2 "+"\033[0;m")
        print("\033[4;35;47m"+"---------------------------- "+"\033[0;m")
        opc = input()

        if(opc == '1'):
            buscar_camino = 'corto'
            ensenanza = revision_camino(indice, buscar_camino, k, b)
            if (ensenanza == 'False'):
                break

            with open('ensenanza.json',"r") as file:
                data2 = json.load(file)
            #Ensenanza más corta
            coordenadas = data2['laberinto'+str(indice)][ensenanza]['ensenanza'+str(ensenanza)]
            imprimircaminos(matriz, coordenadas, k, b)
            limpiarmatriz(matriz, k, b)

        elif(opc == '2'):
            buscar_camino = 'largo'
            ensenanza = revision_camino(indice, buscar_camino, k, b)

            if (ensenanza == 'False'):
                break

            with open('ensenanza.json',"r") as file:
                data2 = json.load(file)

            #Ensenanza más larga
            coordenadas = data2['laberinto'+str(indice)][ensenanza]['ensenanza'+str(ensenanza)]
            imprimircaminos(matriz, coordenadas, k, b)
            limpiarmatriz(matriz, k, b)

        elif(opc == '3'):
            imprimir(matriz2)

        elif(opc == '4'):

            buscarcirculo(matriz, k, b, indice)
            limpiarmatriz(matriz, k, b)


        elif(opc == '5'):
            limpiarmatriz(matriz, k, b)
            salir = 1



def start(matriz, k, l, inicio, indice, coordenadas, data2):

    matriz[inicio][0] = 'X'
    matriz[l][y-2] = ' '
    matriz[l][y-1] = ' '

    salir = 0
    mov = 0
    b = 0
    matriz2 = copy.deepcopy(matriz)

    while(salir != 1):

        imprimir(matriz)

        print("INGRESE MOVIMIENTO (R PARA EL MENU):  ")
        mov = input()

        if(mov == 'A'):
            if(matriz[k][0] == 'X'):
                print("MOVIMIENTO IMPOSIBLE")

            elif(matriz[k][0] != 'X'):
                b = b - 1
                if(matriz[k][b] == BLOQUE):
                    b = b + 1
                    print("CHOCASTE CON MURALLA")

                elif(matriz[k][b] == ' '):
                    coordenadas.append(k)
                    coordenadas.append(b)
                    movimiento(matriz, k, b, mov)
                    matriz2[k][b] = 'X'

        elif(mov == 'S'):
            k = k + 1

            if(matriz[k][b] == BLOQUE):
                k = k - 1
                print("CHOCASTE CON MURALLA")

            elif(matriz[k][b] == ' '):
                coordenadas.append(k)
                coordenadas.append(b)
                movimiento(matriz, k, b, mov)
                matriz2[k][b] = 'X'

        elif(mov == 'D'):
            b = b + 1
            if(matriz[k][b] == BLOQUE):
                b = b - 1
                print("CHOCASTE CON MURALLA")

            elif(matriz[k][b] == ' '):
                coordenadas.append(k)
                coordenadas.append(b)
                movimiento(matriz, k, b, mov)
                matriz2[k][b] = 'X'

        elif(mov == 'W'):
            k = k - 1

            if(matriz[k][b] == BLOQUE):
                k = k + 1
                print("CHOCASTE CON MURALLA")

            elif(matriz[k][b] == ' '):
                coordenadas.append(k)
                coordenadas.append(b)
                movimiento(matriz, k, b, mov)
                matriz2[k][b] = 'X'

        elif(mov == 'R'):
            try:
                with open('ensenanza.json',"r") as file:
                    data2 = json.load(file)
                try:
                    menu(matriz, matriz2, k, b, indice)

                except KeyError:
                    print("No existe todavia aprendizaje, enseñe al menos 1 camino")

            #La primera vez que se inicie el juego no existira archivo json
            except IOError:
                print("No existe todavia aprendizaje")

        elif(mov != 'A' or mov != 'D' or mov != 'S' or mov != 'W' or mov != 'R'):
            print("SOLO INGRESAR LETRA A,S,W,D y R EN MAYÚS ")

        #Coordenadas de salida
        if(matriz[l][y-1] == 'X'):
            salir = 1
            imprimir(matriz)

    salir=0
    while(salir != 1):
        print("\033[4;35;47m"+"!!!! HAS LOGRADO ENCONTRAR LA SALIDA!!!!!! "+"\033[0;m")
        print("\033[4;35;47m"+"----------- MENÚ ----------- "+"\033[0;m")
        print("\033[4;35;47m"+"1.- REINICIAR JUEGO (NUEVO MAPA): "+"\033[0;m")
        print("\033[4;35;47m"+"2.- REINICIAR JUEGO (MISMO MAPA): "+"\033[0;m")
        print("\033[4;35;47m"+"3.- MOSTRAR MOVIMIENTOS: "+"\033[0;m")
        print("\033[4;35;47m"+"4.- SALIR: "+"\033[0;m")
        print("\033[4;35;47m"+"---------------------------- "+"\033[0;m")
        opc = input()


        if(opc == '1'):

            try:
                with open('ensenanza.json',"r") as file:
                    data2 = json.load(file)
                subir_coordenadas(data2, coordenadas, indice)
                creacionmatriz(data1, data2)

            except IOError:
                subir_coordenadas(data2, coordenadas, indice)
                creacionmatriz(data1, data2)
        elif(opc == '2'):

            try:
                with open('ensenanza.json',"r") as file:
                    data2 = json.load(file)

                subir_coordenadas(data2, coordenadas, indice)
                del coordenadas[:]
                k = inicio
                start(matriz, k, l, inicio, indice , coordenadas, data2)

            except IOError:
                subir_coordenadas(data2, coordenadas, indice)
                del coordenadas[:]
                k = inicio
                start(matriz, k, l, inicio, indice , coordenadas, data2)

        elif(opc == '3'):
            for i in range (0,x):
                for j in range(0,y):
                    if(matriz2[i][j] == 'X'):
                        print("\033[4;35;47m"+matriz2[i][j],end = "" +"\033[0;m")
                    elif(matriz2[i][j] != 'X'):
                        print(matriz2[i][j],end = "")
                print()

        elif(opc == '4'):
            subir_coordenadas(data2, coordenadas, indice)
            salir = 1
        elif(opc != '1' or opc != '2' or opc != '3' or opc !='4'):
            print("\033[4;35;47m"+"ERROR: NUMERO INCORRECTO"+"\033[0;m")

def armazon(matriz, data1, data2):
    print("\033[4;35;47m"+"--------------------------------------------- "+"\033[0;m")
    print("\033[4;35;47m"+"--------------------------------------------- "+"\033[0;m")
    print("\033[4;35;47m"+"-------------BIENVENIDO LABERINTO------------ "+"\033[0;m")
    print("\033[4;35;47m"+"--------------------------------------------- "+"\033[0;m")
    print("\033[4;35;47m"+"--------------------------------------------- "+"\033[0;m")

    #Fijas la entrada y salida del laberinto
    k = random.randint(1,x-2)
    l = random.randint(1,x-2)
    inicio = k

    coordenadas = []

    for i in range(3,8):
        matriz[l][y-i] = ' '
    #COLUMNA INVISIBLE
    for i in range(0,x):
        matriz[i][y-1] = ' '

    laberinto(matriz, k)
    laberinto_parte_2(matriz, l)
    rellenar(matriz, k ,l)
    indice = revision_matriz_repetida(data1, matriz)
    start(matriz, k, l, inicio, indice, coordenadas, data2)


def creacionmatriz(data1, data2):
    matriz = [x] * x
    for i in range(x):
        matriz[i] = [BLOQUE] * y

    armazon(matriz, data1, data2)

data1 = []
data2 = {}

data1 = cargar_json_matriz()
data2 = cargar_json_ensenanza()

creacionmatriz(data1, data2)

