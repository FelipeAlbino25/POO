/*
continuação da aula de sobrecarga de operadores
*/

/*
sobrecarga de operadores

-uso de operadores (*, -, + etc) da linguagem para manipular objetos
exemplo: o caso abaixo f3 = f1 * f2;
não se pode mudar como os operadores funcionam com os tipos pré-definidos
não se pode criar novos operadores

funções: membros x friends

-membro (objeto é dono deste método):
use 'this' para obter argumentos implicitamente
obtem operando à esquerda para operador binário ( como * por exemplo)
objeto mais a esquerda deve ser da mesma classe que o operador

friend (função global):
necessitam de parâmetros para AMBOS os operandos
podem ter objeto de classe diferente da do operador
tem que ser 'friend' para acessar dados private/protected
*/
using namespace std;
#include <iostream>




class Fracao{
    private:
        int num;
        int den;
    public:
        void setNum(int n){
            this->num = n;
        }
        void setDen(int n){
            if(n == 0){
                return;
            }
            else this->den = n;
        }
        int getNum(){
            return this->num;
        }
        int getDen(){
            return this->den;
        }
        Fracao(){}
        Fracao(int num,int den){
            this->num = num;
            this->den = den;
        }
        ~Fracao(){
        }
        void mostra(){
            cout<<"Num:" <<this->num << "| Den:" << this->den << endl;
        }
        Fracao mult(Fracao f1, int num){
            Fracao resultado;
            resultado.setDen(this->den);
            resultado.setNum(this->num * num);
            return resultado;
        }

        //altera e manda
        Fracao & operator++(){
           setNum(this->getNum()+this->getDen());

            return *this;
        }
        //manda e depois altera
        Fracao operator++(int n){
           Fracao f1(this->getNum(),this->getDen());

            this->setNum(this->getNum()+ this->getDen());
            return f1;
        }

        friend ostream &operator<<(ostream &output, const Fracao &f);
        friend istream &operator>>(istream &input, Fracao &f);

};

ostream &operator<<(ostream &output, const Fracao &f){
    output << f.num <<"/" <<f.den;
    return output;
}

istream &operator>>(istream &input, Fracao &f){

    int num;
    int dem;
    input >> num;
    input.ignore();
    input >> dem;

    f.setDen(dem);
    f.setNum(num);
    return input;
}


Fracao operator*(Fracao f1, Fracao f2){

    Fracao resultado;
    resultado.setNum(f1.getNum() * f2.getNum());
    resultado.setDen(f1.getDen() * f2.getDen());

    return resultado;
}   

Fracao operator*(Fracao f1, int num){
    Fracao resultado;
    resultado.setDen(f1.getDen());
    resultado.setNum(f1.getNum() * num);
    return resultado;
}

int main(){

    Fracao *f1 = new Fracao(1,4);
    Fracao *f2 = new Fracao();

    cout <<endl<< *f1 << endl;

    cin >> *f2;
    cout<<*f2;
    return 0;
}