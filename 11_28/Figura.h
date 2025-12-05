#ifndef FIGURA_H
#define FIGURA_H
#include <string>

class Figura {
    protected: // Mudei para protected para os filhos acessarem se precisarem
        int x, y;
    public:
        Figura();
        Figura(int x, int y);
        virtual std::string desenhar(); // Virtual permite polimorfismo
        
        // Getters e Setters...
};
#endif