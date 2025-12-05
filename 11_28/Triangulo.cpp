#include "Triangulo.h"

Triangulo::Triangulo() : Figura() {}

Triangulo::Triangulo(int x, int y) : Figura(x, y) {}

std::string Triangulo::desenhar() {
    return "triangulo";
}