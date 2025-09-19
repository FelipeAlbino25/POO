/*
gerenciamento dinamico de memória:

-new e delete

Foram feitos para trabalhar com objetos, exemplo: Task *t1 = new Task(att1,att2 ... );
alocamos um endereço de memoria que guarda o nosso objeto, e depois podemos liberar esta memória
usando delete t1;
*/

using namespace std;
#include <iostream>

class Vetor{
    private:
        int size;
        int* pointer;

    public:
        Vetor(){
            this->size = 10;
        }
        Vetor(int size){
            setSize(size);
            pointer =  new int[size];
        }
        ~Vetor(){
            delete [] pointer;
        }
        void setSize(int size){
            if(size<=0){
                throw invalid_argument("size cannot be lower or equal than 0");
            }
            else{
                this->size =size;
            }
        }
        bool getAt(int index, int &val)const{
            if(index>this->size || index<0){
                return false;
            }
            else{
                val = pointer[index];
                return true;
            }
        }
        bool push(int index, int value){
           if(index>size || index<0){
            return false;
           }
           else{
            pointer[index] = value;
            return true;
           }
        }
        
        int getSize()const{
            return this->size;
        }

        void print()const{
            for(int i=0; i<=size;i++){
                cout << "\n"<< pointer[i];
            }
        }
};

int main(){

    Vetor *v1 = new Vetor(12);
    bool result1 =v1->push(0,10);
    bool result2 = v1->push(1,20);

    v1->print();
}