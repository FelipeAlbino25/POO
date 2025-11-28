
#include <iostream>
using namespace std;

class Complexo{
    private:
        double real;
        double imag;

    public:
        Complexo(){
            real = imag =0;
        }
        Complexo(double real, double imag){
            this->imag=imag;
            this->real = real;
        }

        friend ostream &operator<<(ostream &out, const Complexo &c);
        Complexo operator+(const Complexo &c)const;
        friend Complexo operator+(double n, const Complexo &c);
        Complexo operator++(int useless);
        bool operator==(const Complexo &c)const;

};

ostream &operator<<(ostream &out, const Complexo &c){
    out << c.real << "+" << c.imag <<"i";
    return out;
}

Complexo Complexo:: operator+(const Complexo &c) const{
    return Complexo(c.real + this->real, c.imag + this->imag);
}

Complexo operator+(double n, const Complexo &c){
    return Complexo(n + c.real, c.imag);
}

Complexo Complexo::operator++(int useless){
    Complexo c(this->real, this->imag);
    this->real +=1;
    return c;
}

bool Complexo:: operator==(const Complexo &c) const{
    return (this->real == c.real && this->imag == c.imag);
}


int main () {
    Complexo A(3,4), B(5,0), C;
    cout << "A = " << A << endl << "B = " << B << endl;

    C = A + B;
    cout << "C = A + B = " << C << endl;

    A = 4.0 + A;
    cout << "A = 4.0 + A = " << A << endl;

    cout << "A++ (incrementa 1 na parte real): " << A++ << endl;

    if(C==A)
        cout << "C e A sao iguais" << endl;
    return 0;
}