#include <iostream>
#include "Figura.h"     // Apenas headers
#include "Triangulo.h"
#include "Circulo.h"

using namespace std;

int main() {
    // Exemplo real de polimorfismo: Ponteiro da classe Pai recebendo classe Filho
    Figura *minhaForma = new Triangulo(10, 20);

    // Agora imprimimos o resultado com cout
    cout << minhaForma->desenhar() << endl; 
    // Saída esperada: "triangulo" (graças ao virtual)

    delete minhaForma;
    return 0;
}