#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
    // Verificar que se proporcionen suficientes argumentos
    if (argc < 4) {
        cerr << "Uso: " << argv[0] << " archivo s1 s2" << endl;
        return 1;
    }

    // Obtener los argumentos del archivo y los strings s1 y s2
    string archivo = argv[1];
    string s1 = argv[2];
    string s2 = argv[3];

    // Abrir el archivo
    ifstream entrada(archivo);
    if (!entrada) {
        cerr << "No se pudo abrir el archivo: " << archivo << endl;
        return 1;
    }

    // Leer el contenido del archivo línea por línea
    string linea;
    while (getline(entrada, linea)) {
        // Reemplazar todas las ocurrencias de s1 por s2 en la línea
        size_t pos = 0;
        while ((pos = linea.find(s1, pos)) != string::npos) {
            linea.replace(pos, s1.length(), s2);
            pos += s2.length(); // Mover la posición después de la sustitución
        }
        // Imprimir la línea modificada
        cout << linea << endl;
    }

    // Cerrar el archivo
    entrada.close();

    return 0;
}
