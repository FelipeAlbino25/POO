/**
 * TEMPLATES
 * são usados qnd múltiplas 'cópias' de código são necessárias para implementar uma mesma função
 * com diferentes tipos de dados:
 * 
 * pilha de int, string, double, bool, etc ...
 *
 */
 #include <iostream>
using namespace std;

 template <typename Tgenerico>
 
 Tgenerico Maior (Tgenerico x, Tgenerico y){
        if(x > y){
            return x;
        }
        else return y;
 }

 int main(){

    int i1 =2;
    int i2 = 5;
    double d1 = 4.3;
    double d2 = 5.4;
    char c1 = 'a';
    char c2 = 'b';

    cout << "maior int: "<< Maior(i1,i2)<<endl;
    cout<< "maior double: "<< Maior(d1,d2)<<endl;
    cout << "maior char: "<< Maior(c1,c2)<<endl;
 }