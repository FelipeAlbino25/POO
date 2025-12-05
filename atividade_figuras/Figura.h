#ifndef FIGURA_H
#define FIGURA_H

#include <iostream>

class Figura {
protected:
    int x, y; // Canto superior esquerdo

public:
    Figura(int x_inicial, int y_inicial) : x(x_inicial), y(y_inicial) {}
    virtual ~Figura() {}

    void SetPosicao(int novo_x, int novo_y) {
        x = novo_x;
        y = novo_y;
    }

    int getX() const { return x; }
    int getY() const { return y; }

    virtual void Desenha() = 0;
};

#endif