/*
Herança e composição

composição: quando você usa um objeto X como atributo de outra classe Y

herança: reutilização de software, absorver os atributos e métodos da classe herdada
*/
#include <iostream>
using namespace std;

class Ponto{

    private:
        int x;
        int y;
    public:
        void print();
        int getX() const;
        int getY() const;
        void setX(int num);
        void setY(int num);
        Ponto();
        ~Ponto();
        Ponto(int x, int y);

        
      
      
};

int main(){
    Ponto *p =new Ponto(1,2);

    p->print();
}

        void Ponto:: print(){
            cout << "| X: " << this->x << " | Y: " << this->y <<" |"<< endl;
        };

        int Ponto:: getX() const{
            return this->x;
        };
        int Ponto:: getY() const {
            return this->y;
        };
        void Ponto:: setX(int num) {
            this->x = num;
        }
        void Ponto:: setY(int num){
            this->y = num;
        }
        Ponto:: Ponto(){
            this->setX(0);
            this->setY(0);
        };
        Ponto::Ponto(int x, int y){
            this->setX(x);
            this->setY(y);
        }