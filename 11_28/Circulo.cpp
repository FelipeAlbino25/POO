#include "Figura.h"
#include <string>
class Circulo : public Figura{

    public:
        
        Circulo() : Figura(){}
        Circulo(int x, int y) : Figura(x,y){}
};