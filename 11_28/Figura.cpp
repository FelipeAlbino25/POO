#include "Figura.h"

Figura::Figura() : x(0), y(0) {}

Figura::Figura(int x, int y) : x(x), y(y) {}

std::string Figura::desenhar() {
    return "figura genérica";
}