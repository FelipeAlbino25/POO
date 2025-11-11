/*
Em relação a sobrecarga de operadores podemos definir em tipos de operações, como por exemplo na classe Fracoes:

Unários(++, --, etc)
-são membros da classe


Fracao e Fracao
-são membros da classe


Fracao e Int
-são membros da classe

Int e Fracao
-não são membros da classe ( são declarados como friend )

Fluxo de entrada e saida
-não são membros da classe ( são declarados como friend )
        
        friend ostream &operator<<(ostream &saida, const MeuInt &num);
        friend istream &operator>>(istream &entrada, MeuInt &num); 

*/

using namespace std;
#include <iostream>
class Fracao{

    private:
        int num;
        int den;
    public:
        Fracao();
        Fracao(int num, int den){
            this->num = num;
            this->den = den;
        }
        //unários
        Fracao& operator++(){
            this->num = this->num + this->den;

            return *this;
        }
        Fracao operator++(int useless){
            Fracao copy(this->num,this->den);
            this->num = this->num + this->den;
            return copy;
        }
        Fracao& operator--(){
            this->num = this->num - this->den;
            return *this;
        }
        Fracao operator--(int useless){
            Fracao copy(this->num, this->den);
            this->num = this->num - this->den;
            return copy;
        }
        //Fracao-Fracao
        Fracao operator+(const Fracao &f)const{
            int commonDen = f.den * this->den;
            int commonNum = f.num * this->den + this->num * f.den;
            Fracao f(commonNum, commonDen);
            return f;
        }
        Fracao operator-(const Fracao &f)const{

        }

        //Fracao-int
        //int-Fracao
        friend Fracao operator+(int number,const Fracao &f1);
        //input-output
};