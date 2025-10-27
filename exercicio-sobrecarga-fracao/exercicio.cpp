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

uma referência constante, por exemplo:

        friend ostream &operator<<(ostream &output, const Fracao &f);

    const Fracao &f, serve para impedirmos que haja mudança em um objeto, mesmo que esteja sendo passado
    o endereço de memória em que está localizado
*/

#include <iostream>
using namespace std;

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
                this->den = 1; 
            }
            else this->den = n;
        }
        int getNum() const{
            return this->num;
        }
        int getDen() const {
            return this->den;
        }
        Fracao(): num(0), den(1) {}
        Fracao(int num,int den){
            this->num = num;
            this->setDen(den); 
        }
        ~Fracao(){
        }
        
        void mostra() const {
            cout<<"Num:" <<this->num << "| Den:" << this->den << endl;
        }

        /**
         * operadores de auto-soma
         * pré e pós fixados
         */

        //altera e manda
        Fracao & operator++(){
           setNum(this->num + this->den);
            return *this;
        }
        
        //manda e depois altera
        Fracao operator++(int n){
           Fracao temp(this->num, this->den); 
           this->setNum(this->num + this->den); 
            return temp; 
        }

        /**
         * operadores de auto-subtração
         * pré e pós fixados
         */
        Fracao & operator--(){
            setNum(this->num - this->den);
            return *this;
        }

        Fracao operator--(int n){
            Fracao temp(this->num, this->den);
            this->setNum(this->num - this->den); 
            return temp; 
        }

        friend ostream &operator<<(ostream &output, const Fracao &f);
        
        friend istream &operator>>(istream &input, Fracao &f);

};

/**
 * operadores de input/output
 */

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

/**
 * Operador de Multiplicação

 */

Fracao operator*(const Fracao &f1, const Fracao &f2){
    Fracao resultado; 
    resultado.setNum(f1.getNum() * f2.getNum());
    resultado.setDen(f1.getDen() * f2.getDen());
    return resultado; 
}   

Fracao operator*(const Fracao &f1, int num){
    Fracao resultado;
    resultado.setDen(f1.getDen());
    resultado.setNum(f1.getNum() * num);
    return resultado;
}

Fracao operator*(int num, const Fracao &f1){
    return f1 * num; 
}

/**
 * operador de adição
 */

 Fracao operator+(const Fracao &f1, const Fracao &f2){
    Fracao resultado; 
    resultado.setDen(f1.getDen() * f2.getDen());
    resultado.setNum(f1.getNum() * f2.getDen() + f2.getNum() * f1.getDen()); 
    return resultado;
 }

 Fracao operator+(const Fracao &f1, int num){
    Fracao resultado(f1.getNum(), f1.getDen()); 
    resultado.setNum(f1.getNum() + num * f1.getDen());
    return resultado;
 }

 Fracao operator+(int num, const Fracao &f1){
    return f1 + num;
 }

 /**
  * operador de subtração
  */

Fracao operator-(const Fracao &f1, const Fracao &f2){
    Fracao resultado; 
    resultado.setDen(f1.getDen() * f2.getDen());
    resultado.setNum(f1.getNum() * f2.getDen() - f2.getNum() * f1.getDen());
    return resultado;
}

Fracao operator-(const Fracao &f1, int num){
    Fracao resultado; 
    resultado.setDen(f1.getDen());
    resultado.setNum(f1.getNum() - num * f1.getDen());
    return resultado;
}

Fracao operator-(int num, const Fracao &f1){
    Fracao derivada(num, 1); 
    Fracao resultado; 

    resultado.setDen(derivada.getDen() * f1.getDen());
    resultado.setNum(derivada.getNum() * f1.getDen() - f1.getNum() * derivada.getDen());

    return resultado;
}

/**
 * operadores de comparação
 * FRACAO / FRACAO
 */

 bool operator<(const Fracao &f1, const Fracao &f2){
    return (f1.getNum() * f2.getDen()) < (f2.getNum() * f1.getDen());
 }

  bool operator>(const Fracao &f1, const Fracao &f2){
    return (f1.getNum() * f2.getDen()) > (f2.getNum() * f1.getDen());
 }

 bool operator==(const Fracao &f1, const Fracao &f2){
    return (f1.getNum() * f2.getDen()) == (f2.getNum() * f1.getDen());
 }

 bool operator!=(const Fracao &f1, const Fracao &f2){
    return !(f1 == f2); 
 }

 bool operator<=(const Fracao &f1, const Fracao &f2){
    return (f1 < f2) || (f1 == f2); 
 }

 bool operator>=(const Fracao &f1, const Fracao &f2){
    return (f1 > f2) || (f1 == f2); 
 }

/**
 * operadores de comparação
 * FRACAO / INTEIRO
 */

 bool operator<(const Fracao &f1, int num){
    Fracao derivada(num, 1); 
    return f1 < derivada; 
 }

 bool operator<(int num, const Fracao &f1){
    Fracao derivada(num, 1);
    return derivada < f1;
 }

 bool operator>(const Fracao &f1, int num){
    Fracao derivada(num, 1);
    return f1 > derivada;
 }

 bool operator>(int num, const Fracao &f1){
    Fracao derivada(num, 1);
    return derivada > f1;
 }

 bool operator<=(const Fracao &f1, int num){
    Fracao derivada(num, 1);
    return f1 <= derivada;
 }

 bool operator<=(int num, const Fracao &f1){
    Fracao derivada(num, 1);
    return derivada <= f1;
 }

 bool operator>=(const Fracao &f1, int num){
    Fracao derivada(num, 1);
    return f1 >= derivada;
 }

 bool operator>=(int num, const Fracao &f1){
    Fracao derivada(num, 1);
    return derivada >= f1;
 }

 bool operator==(const Fracao &f1, int num){
    Fracao derivada(num, 1);
    return f1 == derivada; 
 }
 
 bool operator==(int num, const Fracao &f1){
    Fracao derivada(num, 1);
    return derivada == f1;
 }

 bool operator!=(const Fracao &f1, int num){
    Fracao derivada(num, 1);
    return f1 != derivada;
 }
 
 bool operator!=(int num, const Fracao &f1){
    Fracao derivada(num, 1);
    return derivada != f1;
 }

int main(){
    
    cout << boolalpha;

    cout << "--- Testes Iniciais ---" << endl;
    Fracao f1(3,4);
    Fracao f2(2,4); // (ou 1/2)
    Fracao f3;

    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;
    
    cout << "\n--- Teste Pós-Incremento (f1++) ---" << endl;
    //deve imprimir 3/4 (valor antigo)
    cout << "Valor de f1++: " << (f1++) << endl;
    //deve imprimir 7/4 (valor novo)
    cout << "Valor de f1 agora: " << f1 << endl;

    cout << "\n--- Teste Pré-Incremento (++f2) ---" << endl;
    //deve imprimir 6/4 (valor novo)
    cout << "Valor de ++f2: " << (++f2) << endl;
    //deve imprimir 6/4 (valor novo)
    cout << "Valor de f2 agora: " << f2 << endl;

    // Resetando f1 e f2 para testes
    f1 = Fracao(5, 2); // 5/2
    f2 = Fracao(1, 3); // 1/3
    cout << "\n--- Resetando f1 e f2 ---" << endl;
    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;

    cout << "\n--- Teste Pós-Decremento (f1--) ---" << endl;
    //deve imprimir 5/2 (valor antigo)
    cout << "Valor de f1--: " << (f1--) << endl;
    //deve imprimir 3/2 (valor novo)
    cout << "Valor de f1 agora: " << f1 << endl;

    cout << "\n--- Teste Pré-Decremento (--f2) ---" << endl;
    //deve imprimir -2/3 (valor novo)
    cout << "Valor de --f2: " << (--f2) << endl;
    //deve imprimir -2/3 (valor novo)
    cout << "Valor de f2 agora: " << f2 << endl;


    // Resetando f1 e f2
    f1 = Fracao(3, 4); // 3/4
    f2 = Fracao(1, 5); // 1/5
    cout << "\n--- Resetando f1 e f2 ---" << endl;
    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;

    cout << "\n--- Teste Operadores Aritméticos ---" << endl;
    //deve imprimir (3/4 + 1/5) = (15+4)/20 = 19/20
    cout << "f1 + f2: " << (f1 + f2) << endl;
    //deve imprimir (3/4 - 1/5) = (15-4)/20 = 11/20
    cout << "f1 - f2: " << (f1 - f2) << endl;
    //deve imprimir (3/4 * 1/5) = 3/20
    cout << "f1 * f2: " << (f1 * f2) << endl;

    cout << "\n--- Teste Aritméticos com Inteiro ---" << endl;
    int num = 2;
    //deve imprimir (3/4 + 2) = (3+8)/4 = 11/4
    cout << "f1 + " << num << ": " << (f1 + num) << endl;
    //deve imprimir (2 + 1/5) = (10+1)/5 = 11/5
    cout << num << " + f2: " << (num + f2) << endl;
    //deve imprimir (3/4 * 2) = 6/4
    cout << "f1 * " << num << ": " << (f1 * num) << endl;
    //deve imprimir (2 - 3/4) = (8-3)/4 = 5/4
    cout << num << " - f1: " << (num - f1) << endl;

    // Resetando f1 e f2
    f1 = Fracao(1, 2); // 1/2
    f2 = Fracao(3, 4); // 3/4
    Fracao f4(2, 4); // 2/4 (equivalente a 1/2)
    cout << "\n--- Resetando f1, f2, f4 ---" << endl;
    cout << "f1 = " << f1 << endl;
    cout << "f2 = " << f2 << endl;
    cout << "f4 = " << f4 << endl;

    cout << "\n--- Teste Operadores de Comparação (Fracao/Fracao) ---" << endl;
    //deve imprimir true
    cout << "f1 < f2 (1/2 < 3/4): " << (f1 < f2) << endl;
    //deve imprimir false
    cout << "f1 > f2 (1/2 > 3/4): " << (f1 > f2) << endl;
    //deve imprimir true (1/2 == 2/4)
    cout << "f1 == f4 (1/2 == 2/4): " << (f1 == f4) << endl;
    //deve imprimir false
    cout << "f1 == f2 (1/2 == 3/4): " << (f1 == f2) << endl;
    //deve imprimir true
    cout << "f1 != f2 (1/2 != 3/4): " << (f1 != f2) << endl;
    //deve imprimir true
    cout << "f1 <= f4 (1/2 <= 2/4): " << (f1 <= f4) << endl;
    //deve imprimir true
    cout << "f2 >= f1 (3/4 >= 1/2): " << (f2 >= f1) << endl;

    cout << "\n--- Teste Operadores de Comparação (Fracao/Inteiro) ---" << endl;
    // f1 é 1/2 (0.5)
    //deve imprimir true
    cout << "f1 < 3 (1/2 < 3): " << (f1 < 3) << endl;
    //deve imprimir false
    cout << "f1 > 1 (1/2 > 1): " << (f1 > 1) << endl;
    //deve imprimir true
    cout << "4 > f1 (4 > 1/2): " << (4 > f1) << endl;
    //deve imprimir true
    cout << "f1 <= 1 (1/2 <= 1): " << (f1 <= 1) << endl;
    // f2 é 3/4 (0.75)
    //deve imprimir false
    cout << "f2 == 1 (3/4 == 1): " << (f2 == 1) << endl;
    //deve imprimir true
    cout << "f2 != 1 (3/4 != 1): " << (f2 != 1) << endl;

    cout << "\n--- Teste Operador de Input (>>) ---" << endl;
    cout << "Digite uma nova fracao para f3:";
    cin >> f3;
    //deve imprimir a fração digitada pelo usuário
    cout << "Você digitou para f3: " << f3 << endl;

    return 0;
}