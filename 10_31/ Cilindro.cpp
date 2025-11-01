#include <iostream>
#include "Circulo.h"
using namespace std;

class Cilindro : public Circulo {

    private:
        int altura;
    public:
        int getAltura() const {
            return this->altura;
        }
        void setAltura(int num) {
            this->altura = num;
        }
        void print() const{
            Circulo:print();
            cout <<"blabla";
        }
        Cilindro(int x, int y, int raio, int altura) : Circulo(x,y,raio){
            this->setAltura(altura);
        }

};