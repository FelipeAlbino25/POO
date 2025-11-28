#include <iostream>
using namespace std;


class Funcionario{
    private:
        string nome;
        string codigo;
        double salario;

    public:
        string getNome()const;
        string getCodigo() const;
        double getSalario() const;
        virtual double remuneracao() const;
        virtual void print() const;

        Funcionario();
        Funcionario(string nome, string codigo, double salario);
};

string Funcionario:: getNome()const{
    return this->nome;
}

string Funcionario:: getCodigo()const{
    return this->codigo;
}
double Funcionario:: getSalario() const{
    return this->salario;
}

Funcionario:: Funcionario(string nome, string codigo, double salario){
    this->nome = nome;
    this->codigo = codigo;
    this->salario = salario;
}
double Funcionario:: remuneracao()const{
    return this->salario;
}
void Funcionario:: print()const{
    cout << "Funcionario: " << this->nome <<", codigo: "<< this->codigo << ", salario: "<< this->salario;
}

class Gerente : public Funcionario {
    private:
        int nFuncionarios;
    public:
        Gerente();
        Gerente(string nome, string codigo, double salario, int nFuncionarios);
        double remuneracao()const;
        void print() const;

};

Gerente:: Gerente(string nome, string codigo, double salario, int nFuncionarios): Funcionario(nome,codigo,salario){
    this->nFuncionarios = nFuncionarios;
}

double Gerente:: remuneracao() const{
    return this->getSalario() * (1+this->nFuncionarios * 0.01);
}

void Gerente:: print() const{
    cout << "Gerente: " << this->getNome() <<", codigo: "<< this->getCodigo()<< ", salario: "<< this->getSalario()<<", funcionarios: "<< this->nFuncionarios;

}

int main(){

    Funcionario f("felipe","1234",1000);
    f.print();
    cout << endl;
    cout << f.remuneracao() << endl;

    Gerente g("felipe2","4321",2000,10);
    g.print();
    cout << endl;
    cout << g.remuneracao() << endl;
}