#include "Ponto.h"
#include <iostream>
using namespace std;

class Circulo:public Ponto{

    private:
        int raio;
    public:
        void setRaio(int num){
            this->raio = raio;
        }
        int getRaio() const{
            return this->raio;
        }
        void print() const{
            Ponto:print();
            cout << "blablabla";
        }
        Circulo(int x, int y, int raio): Ponto(x,y){
           this->setRaio(raio);
        }
        Circulo(): Ponto(0,0){
           this->setRaio(0);
        }
};

int main(){

}