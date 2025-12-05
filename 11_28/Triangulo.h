#ifndef TRIANGULO_H
#define TRIANGULO_H
#include "Figura.h" // Inclui o .h, NUNCA o .cpp

class Triangulo : public Figura {
    public:
        Triangulo();
        Triangulo(int x, int y);
        std::string desenhar() override; // override confirma que estamos sobrescrevendo
};
#endif