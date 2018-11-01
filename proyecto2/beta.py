from time import sleep
import random
import copy
import os
import json
BLOQUE = '█'
x = 20
y = 40

def revision(matriz,k,a):
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
    a = 1
    b = y-3
    matriz[k][a] = ' '

    pausa = 1000
    while pausa >= 1:
        comodin_1 = k
        comodin_2 = a
        movimiento = random.randint(1,5)
        #right
        if movimiento == 1:
            a = a+1
            revisar = revision(matriz,k,a)
            if a != b-1 and revisar <= 2:
                matriz[k][a] = ' '
            else:
                a = a-1
        #up
        elif movimiento == 2:
            k = k-1
            revisar = revision(matriz,k,a)
            if k != 0 and revisar <= 2:
                matriz[k][a] = ' '
            else:
                k = k+1
        #down
        elif movimiento == 3:
            k = k+1
            revisar = revision(matriz,k,a)
            if k != x-1 and revisar <= 2:
                matriz[k][a]=' '
            else:
                k = k-1
        #left
        elif movimiento == 4:
            a = a-1
            revisar = revision(matriz,k,a)
            if a != 0 and revisar <= 2:
                matriz[k][a] = ' '
            else:
                a = a+1
        if comodin_1 == k and comodin_2 == a:
            pausa = pausa-1

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
        #right
        if movimiento == 1:
            a = a+1
            revisar = revision(matriz,k,a)
            if a != b-1 and revisar <= 2:
                matriz[k][a] = ' '
            else:
                a = a-1
        #up
        elif movimiento == 2:
            k = k-1
            revisar = revision(matriz,k,a)
            if k != 0 and revisar <= 2:
                matriz[k][a] = ' '
            else:
                k = k+1
        #down
        elif movimiento == 3:
            k = k+1
            revisar = revision(matriz,k,a)
            if k != x-1 and revisar <= 2:
                matriz[k][a]=' '
            else:
                k = k-1
        #left
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

def rellenar(matriz, k ,l):
    detenerse = 1000
    while detenerse > 0:
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
        detenerse = detenerse-1
    rellenar_2(matriz, k ,l)

def rellenar_2(matriz, k ,l):
    detenerse = 1000
    while detenerse > 0:
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

        detenerse = detenerse-1

    for i in range(-1,2):
        for w in range(1,4):
            matriz[k+i][w] = ' '
        for i in range(1,8):
            matriz[l][y-i] = ' '

    for i in range(0,y-1):
        matriz[0][i] = BLOQUE
    for i in range(0,y-1):
        matriz[x-1][i] = BLOQUE

def imprimir(matriz):

    for i in range (0,x):
        for k in range(0,y):
            print(matriz[i][k],end="")
        print()

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

def crear_base_de_datos():

    archivo = open ('data.json',"w")
    archivo.close()

def base_de_datos(matriz_resuelta, arreglo):

    arreglo.append(matriz_resuelta)
    with open ('data.json',"a") as file:
        json.dump(arreglo, file, indent = 4)

def abrir_base_de_datos(arreglo, i):

    x = arreglo[i]

    imprimir(x)

def start(matriz, k, l, i, arreglo):
    k1 = k
    l1 = l
    salir = 0
    mov = 0
    b = 0
    matriz[k][0] = 'X'
    matriz[l][y-1] = ' '
    matriz_igual = matriz
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
                    movimiento(matriz, k, b, mov)
                    matriz2[k][b] = 'X'

        elif(mov == 'S'):
            k = k + 1

            if(matriz[k][b] == BLOQUE):
                k = k - 1
                print("CHOCASTE CON MURALLA")

            elif(matriz[k][b] == ' '):
                movimiento(matriz, k, b, mov)
                matriz2[k][b] = 'X'

        elif(mov == 'D'):
            b = b + 1

            if(matriz[k][b] == BLOQUE):
                b = b - 1
                print("CHOCASTE CON MURALLA")

            elif(matriz[k][b] == ' '):
                movimiento(matriz, k, b, mov)
                matriz2[k][b] = 'X'

        elif(mov == 'W'):
            k = k - 1

            if(matriz[k][b] == BLOQUE):
                k = k + 1
                print("CHOCASTE CON MURALLA")

            elif(matriz[k][b] == ' '):
                movimiento(matriz, k, b, mov)
                matriz2[k][b] = 'X'

        elif(mov == 'R'):
            matriz[l][y-1] = 'X'

        elif(mov != 'A' or mov != 'D' or mov != 'S' or mov != 'W' or mov != 'R'):
            print("SOLO INGRESAR LETRA A,S,W,D EN MAYÚS ")

        #COORDENADAS DE SALIDA
        if(matriz[l][y-1] == 'X'):
            salir = 1

    matriz_resuelta = matriz2
    base_de_datos(matriz_resuelta, arreglo)

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
            for i in range(x):
                for j in range(y):
                    matriz[i][j] = BLOQUE
            armazon(matriz)
        elif(opc == '2'):
            abrir_base_de_datos(arreglo, i)
            i = i + 1
            k = k1
            l = l1
            start(matriz_igual, k , l, i , arreglo)

        elif(opc == '3'):
            for i in range (0,x):
                for j in range(0,y):
                    if(matriz2[i][j] == 'X'):
                        print("\033[4;35;47m"+matriz2[i][j],end = "" +"\033[0;m")
                    elif(matriz2[i][j] != 'X'):
                        print(matriz2[i][j],end = "")
                print()

        elif(opc == '4'):
            salir = 1
        elif(opc != '1' or opc != '2' or opc != '3' or opc !='4'):
            print("\033[4;35;47m"+"ERROR: NUMERO INCORRECTO"+"\033[0;m")


def armazon(matriz):
    print("\033[4;35;47m"+"        --------------------------------------------- "+"\033[0;m")
    print("\033[4;35;47m"+"        --------------------------------------------- "+"\033[0;m")
    print("\033[4;35;47m"+"        -------------BIENVENIDO LABERINTO------------ "+"\033[0;m")
    print("\033[4;35;47m"+"        --------------------------------------------- "+"\033[0;m")
    print("\033[4;35;47m"+"        --------------------------------------------- "+"\033[0;m")
    #FIJAR LA ENTRADA Y LA SALIDA.
    k = random.randint(1,x-2)
    l = random.randint(1,x-2)
    #COLUMNA INVISIBLE
    for i in range(0,x):
        matriz[i][y-1] = ' '
    laberinto(matriz, k)
    laberinto_parte_2(matriz, l)
    rellenar(matriz, k, l)
    crear_base_de_datos()
    arreglo = []
    i = 0
    start(matriz, k, l, i, arreglo)

def creacionmatriz():
    matriz = [x] * x
    for i in range(x):
        matriz[i] = [BLOQUE] * y

    armazon(matriz)

creacionmatriz()
