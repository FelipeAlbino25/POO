using namespace std;
#include <iostream>

class Pedido{


    private:
        static int contadorPedidos;
        static int contadorItens;
        static int nextId;
        const int id;
        string nome;
        int quantidade;
        string* pointer;

    public:
       
        Pedido(string nome, int quantidade):id(nextId++){
            this->nome = nome;
            this->quantidade = quantidade;
            
            contadorItens = contadorItens+ quantidade;
            contadorPedidos = contadorPedidos+1;

            pointer = new string[quantidade];
        }
        ~Pedido(){
            contadorPedidos= contadorPedidos -1;
            contadorItens=  contadorItens - quantidade;
            delete [] pointer;
        }

        static int totalPedidos(){
            return contadorPedidos;
        }
        static int totalItens(){
           return contadorItens;
        }
        int  getQtd() const{
            return this->quantidade;
        }
        string getNome() const{
            return this->nome;
        }

        bool pushItem(int posicao,string item){
            if(posicao<0 || posicao >=quantidade){
                return false;
            }
            else{
                pointer[posicao] = item;
                return true;
            }
        }

        bool getItem(int posicao, string &valor){
            if(posicao<0 || posicao >=quantidade){
                return false;
            }
            else{
                valor = pointer[posicao];
                return true;
            }
        }

};

int Pedido::contadorPedidos = 0;
int Pedido::contadorItens = 0;
int Pedido::nextId = 1;

int main(){
    Pedido *p1 = new Pedido("pedro",3);
    p1->pushItem(1,"carrinho");
    string result;
    p1->getItem(1,result);
    cout << "\n\n"<<result << "\n\n";
    cout << "\n\n"<<Pedido::totalItens << "\n\n";
        cout << "\n\n"<<Pedido::totalPedidos << "\n\n";

          Pedido *p2 = new Pedido("pedro",5);
   
          Pedido *p3 = new Pedido("pedro",6);
   
    cout << "\n\n"<<Pedido::totalItens() << "\n\n";
        cout << "\n\n"<<Pedido::totalPedidos() << "\n\n";

    



    
}