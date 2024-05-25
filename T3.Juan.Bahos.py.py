import random

def crear_tablero(tipo, tamaño):
    tablero = []
    if tipo == "equilatero":
        for i in range(tamaño):
            tablero.append(["O"] * (i+1))
    elif tipo == "isosceles":
        for i in range(tamaño):
            tablero.append(["O"] * (tamaño - i))
    elif tipo == "escaleno":
        for i in range(tamaño):
            tablero.append(["O"] * (random.randint(1, tamaño)))
    return tablero

def colocar_minas(tablero, num_minas):
    filas = len(tablero)
    for _ in range(num_minas):
        fila = random.randint(0, filas-1)
        columna = random.randint(0, len(tablero[fila])-1)
        while tablero[fila][columna] == "X":
            fila = random.randint(0, filas-1)
            columna = random.randint(0, len(tablero[fila])-1)
        tablero[fila][columna] = "X"
    return tablero

def imprimir_tablero(tablero):
    for fila in tablero:
        print(" ".join(fila))

# Solicitar al usuario el tipo de triángulo y el tamaño
tipo_triangulo = input("Elige el tipo de triángulo (equilatero, isosceles, escaleno): ").lower()
tamaño = int(input("Elige el tamaño del triángulo: "))
num_minas = int(input("Elige el número de minas: "))

# Crear y mostrar el tablero
tablero = crear_tablero(tipo_triangulo, tamaño)
tablero_con_minas = colocar_minas(tablero, num_minas)
imprimir_tablero(tablero_con_minas)

