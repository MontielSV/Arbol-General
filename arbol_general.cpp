#include <iostream>
#include <vector>
using namespace std;

// Estructura del nodo
struct Nodo {
    int dato;
    vector<Nodo*> hijos;

    Nodo(int valor) {
        dato = valor;
    }
};

// Recorrido Preorden
void preOrden(Nodo* raiz) {
    if (raiz == nullptr) return;

    cout << raiz->dato << " ";

    for (Nodo* hijo : raiz->hijos) {
        preOrden(hijo);
    }
}

// Recorrido Postorden
void postOrden(Nodo* raiz) {
    if (raiz == nullptr) return;

    for (Nodo* hijo : raiz->hijos) {
        postOrden(hijo);
    }

    cout << raiz->dato << " ";
}

int main() {
    // Construir el arbol general
    Nodo* raiz = new Nodo(1);

    Nodo* nodo2 = new Nodo(2);
    Nodo* nodo3 = new Nodo(3);
    Nodo* nodo4 = new Nodo(4);

    // Agregar hijos a la raiz
    raiz->hijos.push_back(nodo2);
    raiz->hijos.push_back(nodo3);
    raiz->hijos.push_back(nodo4);

    // Agregar hijos a otros nodos
    nodo2->hijos.push_back(new Nodo(5));
    nodo2->hijos.push_back(new Nodo(6));
    nodo3->hijos.push_back(new Nodo(7));

    cout << "================================\n";
    cout << "           ARBOL GENERAL\n";
    cout << "================================\n\n";

    cout << "             1\n";
    cout << "         /   |   \\\\\n";
    cout << "        2    3    4\n";
    cout << "       / \\\\   |\n";
    cout << "      5   6  7\n\n";

    cout << "================================\n";
    cout << "            RECORRIDOS\n";
    cout << "================================\n\n";

    cout << "Preorden:  ";
    preOrden(raiz);

    cout << "\nPostorden: ";
    postOrden(raiz);

    cout << "\n\n================================\n";
    cout << "         FIN DEL PROGRAMA\n";
    cout << "================================\n";

    return 0;
}
