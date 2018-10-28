import random
bloque = '█'
x = 20
y = 40

def victoria(matriz,l,b):
    for j in range(y-8,b+1):
        matriz[l][j] = ' '

def rellenar(matriz):
    detenerse = 100
    while detenerse >= 1:
        for i in range(1,x-1):
            for j in range(2,y-7):
                rand = random.randint(0,2)
                if matriz[i][j] == ' ' and matriz[i+1][j-1] == ' ' and matriz[i][j-1] == bloque and matriz[i+1][j] == bloque:
                    if rand == 0:
                        matriz[i][j-1] = ' '
                    elif rand == 1:
                        matriz[i+1][j] = ' '
                elif matriz[i][j-1] == ' ' and matriz[i+1][j] == ' ' and matriz[i][j] == bloque and matriz[i+1][j-1] == bloque:
                    if rand == 0:
                        matriz[i][j] = ' '
                    elif rand == 1:
                        matriz[i+1][j-1] = ' '
        detenerse = detenerse-1


def rellenar_2(matriz):
    detenerse = 100
    while detenerse >= 100:
        for i in range(4,x-4):
            for j in range(1,y-7):
                if matriz[i][j] == bloque:
                    if matriz[i][j-1] == bloque:
                        if matriz[i][j+1] == bloque:
                         if matriz[i-1][j-1] == ' ':
                            if matriz[i][j-1] == ' ':
                                if matriz[i+1][j-1] == ' ':
                                    if matriz[i-1][j+1] == ' ':
                                        if matriz[i][j+1] == ' ':
                                            if matriz[i+1][j+1] == ' ':
                                                matriz[i][j] = ' '
        detenerse = detenerse-1

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

matriz = [x] * x
for i in range(x):
	matriz[i] = [bloque] * y

#inicio
k = random.randint(1,x-2)
l = random.randint(1,x-2)
matriz[k][0] = 'x'
#final
matriz[l][y-2] = 'f'
for i in range(3,8):
    matriz[l][y-i] = ' '

#columna no usada
for i in range(0,x):
	matriz[i][y-1] = ' '

#estructuraanterior
a = 1
b = y-3
matriz[k][a] = ' '

pausa = 1000
while pausa >= 1:
    comodin_1 = k
    comodin_2 = a
    movimiento = random.randint(1,5)
    #derechap
    if movimiento == 1:
        a = a+1
        revisar = revision(matriz,k,a)
        if a != b-1 and revisar <= 2:
            matriz[k][a] = ' '
        else:
            a = a-1
    #arribap
    elif movimiento == 2:
        k = k-1
        revisar = revision(matriz,k,a)
        if k != 0 and revisar <= 2:
            matriz[k][a] = ' '
        else:
            k = k+1
    #abajop
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


k = l
a = y-7
pausa = 1000
while pausa >= 1:
    comodin_1 = k
    comodin_2 = a
    movimiento = random.randint(1,5)
    #derechap
    if movimiento == 1:
        a = a+1
        revisar = revision(matriz,k,a)
        if a != b-1 and revisar <= 2:
            matriz[k][a] = ' '
        else:
            a = a-1
    #arribap
    elif movimiento == 2:
        k = k-1
        revisar = revision(matriz,k,a)
        if k != 0 and revisar <= 2:
            matriz[k][a] = ' '
        else:
            k = k+1
    #abajop
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



rellenar(matriz)
rellenar_2(matriz)
victoria(matriz,l,b)

for i in range(0,x):
    for j in range(0,y):
        print(matriz[i][j],end="")
    print()

