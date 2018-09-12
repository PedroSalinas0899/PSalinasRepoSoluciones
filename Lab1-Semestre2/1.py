def romano_a_arabigo(romano, largo):
    for i in range(0, largo):
        M=1000
        D=500
        C=100
        L=50
        X=10
        V=5
        I=1
    if romano[i] >= romano[i+1]:
        numero_arabigo = numero_arabigo + romano[i] + romano[i+1]
    elif romano[i] < romano[i+1]:
        numero_arabigo = numero_arabigo + romano [i+1] - romano [i]


def introducir_romano():
    print("Introduzca un numero romano:")
    romano = input()
    largo = len(romano)
    romano_a_arabigo(romano, largo)


print("Introduzca un 1 para pasar de romano a arabigo o 2 para hacerlo alrevez")
menu = int (input())
if menu == 1:
    introducir_romano()






	
