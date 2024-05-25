#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

// Función para crear el tablero de acuerdo al tipo de triángulo y tamaño especificados
vector<vector<char>> crearTablero(const string& tipo, int tamaño) {
    vector<vector<char>> tablero;
    if (tipo == "equilatero") {
        for (int i = 0; i < tamaño; ++i) {
            tablero.push_back(vector<char>(i + 1, 'O'));
        }
    } else if (tipo == "isosceles") {
        for (int i = 0; i < tamaño; ++i) {
            tablero.push_back(vector<char>(tamaño - i, 'O'));
        }
    } else if (tipo == "escaleno") {
        srand(time(nullptr));
        for (int i = 0; i < tamaño; ++i) {
            tablero.push_back(vector<char>(1 + rand() % tamaño, 'O'));
        }
    }
    return tablero;
}

// Función para colocar minas aleatoriamente en el tablero
vector<vector<char>> colocarMinas(vector<vector<char>>& tablero, int numMinas) {
    int filas = tablero.size();
    for (int i = 0; i < numMinas; ++i) {
        int fila = rand() % filas;
        int columna = rand() % tablero[fila].size();
        while (tablero[fila][columna] == 'X') {
            fila = rand() % filas;
            columna = rand() % tablero[fila].size();
        }
        tablero[fila][columna] = 'X';
    }
    return tablero;
}

// Función para imprimir el tablero
void imprimirTablero(const vector<vector<char>>& tablero) {
    for (const auto& fila : tablero) {
        for (char c : fila) {
            cout << c << " ";
        }
        cout << endl;
    }
}

int main() {
    // Solicitar al usuario el tipo de triángulo, tamaño y número de minas
    string tipoTriangulo;
    cout << "Elige el tipo de triángulo (equilatero, isosceles, escaleno): ";
    cin >> tipoTriangulo;
    int tamaño;
    cout << "Elige el tamaño del triángulo: ";
    cin >> tamaño;
    int numMinas;
    cout << "Elige el número de minas: ";
    cin >> numMinas;

    // Crear el tablero y colocar minas
    vector<vector<char>> tablero = crearTablero(tipoTriangulo, tamaño);
    vector<vector<char>> tableroConMinas = colocarMinas(tablero, numMinas);

    // Imprimir el tablero con minas
    imprimirTablero(tableroConMinas);

    return 0;
}
