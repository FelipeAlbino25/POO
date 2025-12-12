#include <iostream>
#include <vector>
#include <thread>
#include <chrono>
#include "Figura.h"
#include "Formas.h"

using namespace std;

const int LARGURA_TELA = 160;

void DisplayRefresh(const vector<Figura*>& figuras) {
    // Limpa tela e esconde cursor
    cout << "\033[2J\033[?25l"; 
    
    for (Figura* fig : figuras) {
        // Só desenha se estiver visível (x > 0) para evitar quebra de linha feia
        if (fig->getX() > 0 && fig->getX() < LARGURA_TELA) {
            fig->Desenha();
        }
    }
    cout << flush;
}

int main() {
    vector<Figura*> fila;

    int yBase = 2;

    fila.push_back(new Triangulo(5, yBase));
    
    fila.push_back(new Quadrado(20, yBase)); 
 
    fila.push_back(new Retangulo(40, yBase));

    cout << "Iniciando simulacao... (Ctrl+C para parar)" << endl;
    this_thread::sleep_for(chrono::seconds(1));

    while (true) {
        DisplayRefresh(fila);

        // Movimentação da Fila
        for (Figura* fig : fila) {
            int novoX = fig->getX() + 1;

            // Reset para o lado esquerdo (loop)
            if (novoX > LARGURA_TELA) {
                novoX = -10; // Começa antes da tela para entrar suave
            }
            
            fig->SetPosicao(novoX, fig->getY());
        }

        // Velocidade da animação
        this_thread::sleep_for(chrono::milliseconds(15));
    }

    // Limpeza de memória
    cout << "\033[?25h"; 
    for (Figura* f : fila) delete f;
    
    return 0;
}