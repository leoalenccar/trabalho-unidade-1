// ============================================================
// Arquivo: funcoes.cpp
// Descrição: implementação de funções auxiliares
// Autor 1: Leonardo Alencar de Aquino
// Autor 2: Arthur Victor Vieira Almeida
// Data: abril de 2026
// Disciplina: Estruturas de Dados Básicas I
// ============================================================

#include "funcoes.h"
#include <cstdlib> //rand()
#include <iostream>
#include <fstream>

// gera um vetor de tamanho n com valores aleatórios (0 a 99)
// usado como entrada para os testes de desempenho dos algoritmos
void criar_lista_aleatoria(int n, int aleatoria[])
{
    for (int i = 0; i < n; i++)
    {
        aleatoria[i] = rand() % 100;
    }
}

// salva os tempos médios no arquivo "tempos.csv"
// cada linha representa um tamanho de entrada (n)
// os dados serão usados posteriormente para gerar os gráficos
void salvar_arquivo(int tamanho, long long duracao_BS, long long duracao_MS, long long duracao_BL, long long duracao_BB)
{
    std::ofstream file("tempos.csv", std::ios::app);

    file << tamanho << ","
         << duracao_BS << ","
         << duracao_MS << ","
         << duracao_BL << ","
         << duracao_BB << std::endl;

    file.close();
}

/// executa um script do gnuplot (graficos.gp) para gerar os gráficos
// a partir do arquivo tempos.csv
void gerar_graficos()
{
    system("gnuplot graficos.gp");
    std::cout << "Graficos gerados!" << std::endl;
}