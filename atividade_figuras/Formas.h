/**
 * @file Formas.h
 * @brief Implementação das classes concretas de figuras geométricas.
 * * Este arquivo contém a definição das classes que herdam de 'Figura'.
 * Cada classe implementa o método 'Desenha' de maneira única, utilizando
 * caracteres ASCII para formar a imagem no terminal.
 */

#ifndef FORMAS_H
#define FORMAS_H

#include "Figura.h"
#include <iostream>

/**
 * @brief Move o cursor do terminal para uma coordenada específica.
 * * Utiliza códigos de escape ANSI (padrão Linux/Unix) para posicionamento.
 * * @param x Posição horizontal (coluna). Mínimo 1.
 * @param y Posição vertical (linha). Mínimo 1.
 */
void gotoxy(int x, int y) {
    // Proteção para não tentar desenhar fora da área visível (negativos)
    if(x < 1) x = 1;
    if(y < 1) y = 1;
    // Código ANSI: \033[<linha>;<coluna>H
    std::cout << "\033[" << y << ";" << x << "H";
}

// ==========================================================
// CLASSE TRIÂNGULO
// ==========================================================

/**
 * @class Triangulo
 * @brief Representa um triângulo preenchido (pirâmide).
 * Caractere utilizado: '$'
 */
class Triangulo : public Figura {
public:
    /**
     * @brief Construtor do Triângulo.
     * @param x Coordenada X do topo (ou referência superior esquerda).
     * @param y Coordenada Y do topo.
     */
    Triangulo(int x, int y) : Figura(x, y) {}

    /**
     * @brief Desenha um triângulo isósceles preenchido.
     * A lógica desenha linha por linha, calculando o espaçamento
     * à esquerda para garantir a centralização (formato de pirâmide).
     */
    void Desenha() override {
        int altura = 5; 
        for (int i = 0; i < altura; i++) {
            // Posiciona o cursor ajustando o X para criar a inclinação da pirâmide
            gotoxy(x + (altura - i), y + i);
            
            // Desenha os caracteres da linha atual (número ímpar: 1, 3, 5...)
            for (int j = 0; j < (2 * i + 1); j++) {
                std::cout << "$";
            }
        }
    }
};

// ==========================================================
// CLASSE QUADRADO
// ==========================================================

/**
 * @class Quadrado
 * @brief Representa uma forma retangular sólida (preenchida).
 * Apesar do nome, as dimensões (11x5) visam compensar a altura da linha
 * do terminal para parecer um quadrado visualmente.
 * Caractere utilizado: '*'
 */
class Quadrado : public Figura {
public:
    Quadrado(int x, int y) : Figura(x, y) {}

    /**
     * @brief Desenha o quadrado preenchido linha por linha.
     */
    void Desenha() override {
        int largura = 11;
        int altura = 5;

        for (int i = 0; i < altura; i++) {
            gotoxy(x, y + i); // Vai para a linha correta
            for (int j = 0; j < largura; j++) {
                std::cout << "*"; // Preenche tudo com asterisco
            }
        }
    }
};

// ==========================================================
// CLASSE RETÂNGULO
// ==========================================================

/**
 * @class Retangulo
 * @brief Representa uma caixa alta e vazia (apenas bordas).
 * Caractere utilizado: '#' para bordas, ' ' (espaço) para o centro.
 */
class Retangulo : public Figura {
public:
    Retangulo(int x, int y) : Figura(x, y) {}

    /**
     * @brief Desenha as bordas do retângulo.
     * Verifica se a posição atual é uma borda (primeira/última linha ou coluna)
     * para decidir se imprime '#' ou espaço.
     */
    void Desenha() override {
        int largura = 6;
        int altura = 14; 

        for (int i = 0; i < altura; i++) {
            gotoxy(x, y + i);
            for (int j = 0; j < largura; j++) {
                // Lógica de Borda: Se for topo, fundo, esquerda ou direita -> desenha #
                if (i == 0 || i == altura - 1 || j == 0 || j == largura - 1) {
                    std::cout << "#";
                } else {
                    std::cout << " "; // Centro vazio
                }
            }
        }
    }
};

/**
 * Como implementar um novo tipo de forma
 * 
 * 1. Entenda a Regra

A nova classe deve herdar de Figura e deve implementar o método Desenha().

 * 2. Código da nova classe

Utilizar o gotoxy(...) e cout para posicionar os caracteres que montam a forma

 * 3. Uso na main.cpp

EXEMPLO
fila.push_back(new Losango(60, 10)); // Adiciona o Losango na posição X=60
 */

#endif // Fim de FORMAS_H