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

// função para criar lista aleatória, números podem ir de 0 à 99
void criar_lista_aleatoria(int n, int aleatoria[])
{
    for (int i = 0; i < n; i++)
    {
        aleatoria[i] = rand() % 100;
    }
}

// função para salvar arquivo
void salvar_arquivo(int tamanho, long long duracao_BS, long long duracao_MS, long long duracao_BL, long long duracao_BB)
{
    std::ofstream file("tempos.csv", std::ios::app);

    if (file.tellp() == 0)
    {
        file << "n,bubble_sort,merge_sort,linear_search,binary_search\n";
    }

    file << tamanho << ","
         << duracao_BS << ","
         << duracao_MS << ","
         << duracao_BL << ","
         << duracao_BB << std::endl;

    file.close();
}

// função para gerar gráficos
void gerar_graficos()
{
    // usa gnuplot
    system("gnuplot graficos.gp");
    std::cout << "Graficos gerados!" << std::endl;
}