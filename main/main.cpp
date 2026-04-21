// ============================================================
// Arquivo: main.cpp
// Descrição: programa principal — coleta tempos de execução
//            dos algoritmos e gera gráficos
// Autor 1: Leonardo Alencar de Aquino
// Autor 2: Arthur Victor Vieira Almeida
// Data: abril de 2026
// Disciplina: Estruturas de Dados Básicas I
// ============================================================

#include "../algoritmos/algoritmos.h"
#include "../funcoes/funcoes.h"
#include <iostream>
#include <chrono>
using namespace std::chrono;

int main()
{
    // tamanhos para análise
    int tamanhos[] = {1000, 5000, 10000, 50000, 100000};
    int num_tamanhos = 5;
    int repeticoes = 10;

    for (int t = 0; t < num_tamanhos; t++)
    {
        int tamanho = tamanhos[t];

        // sort
        long long total_BS = 0, total_MS = 0;
        // search
        long long total_BL = 0, total_BB = 0;

        for (int r = 0; r < repeticoes; r++)
        {
            // cria lista aleatória base
            int *lista_aleatoria = new int[tamanho];
            criar_lista_aleatoria(tamanho, lista_aleatoria);

            // cópias
            int *ordenado_bubble = new int[tamanho];
            int *ordenado_merge = new int[tamanho];
            for (int i = 0; i < tamanho; i++)
            {
                ordenado_bubble[i] = lista_aleatoria[i];
                ordenado_merge[i] = lista_aleatoria[i];
            }

            // SORT===========================================================================================

            // bubble sort
            auto inicio_BS = high_resolution_clock::now();
            bubble_sort(ordenado_bubble, tamanho);
            auto fim_BS = high_resolution_clock::now();
            total_BS += duration_cast<microseconds>(fim_BS - inicio_BS).count();

            // merge sort
            auto inicio_MS = high_resolution_clock::now();
            merge_sort(ordenado_merge, 0, tamanho - 1);
            auto fim_MS = high_resolution_clock::now();
            total_MS += duration_cast<microseconds>(fim_MS - inicio_MS).count();

            // chaves de busca
            // pior caso linear:  chave não encontrada (-1), percorre tudo
            // melhor caso linear: primeiro elemento
            // pior caso binária:  chave não encontrada (-1), percorre tudo
            // melhor caso binária: elemento do meio
            int chave_pior_linear = -1;
            int chave_melhor_linear = lista_aleatoria[0];
            int chave_pior_binary = -1;
            int chave_melhor_binary = ordenado_merge[tamanho / 2];

            // SEARCH==================================================================================

            // linear search
            auto inicio_BL = high_resolution_clock::now();
            linear_search(lista_aleatoria, tamanho, chave_pior_linear);
            auto fim_BL = high_resolution_clock::now();
            total_BL += duration_cast<microseconds>(fim_BL - inicio_BL).count();

            // binary search
            auto inicio_BB = high_resolution_clock::now();
            binary_search(ordenado_merge, 0, tamanho - 1, chave_pior_binary);
            auto fim_BB = high_resolution_clock::now();
            total_BB += duration_cast<microseconds>(fim_BB - inicio_BB).count();

            //==============================================================================================

            delete[] lista_aleatoria;
            delete[] ordenado_bubble;
            delete[] ordenado_merge;
        }

        // médias
        long long duracao_BS = total_BS / repeticoes;
        long long duracao_MS = total_MS / repeticoes;
        long long duracao_BL = total_BL / repeticoes;
        long long duracao_BB = total_BB / repeticoes;

        //mostrar no terminal
        std::cout << "Algorítmos de ordenação:\n";
        std::cout << "Bubble sort: " << duracao_BS << " microssegundos.\n";
        std::cout << "Merge sort:  " << duracao_MS << " microssegundos.\n\n";
        std::cout << "Algorítmos de busca:\n";
        std::cout << "Linear search: " << duracao_BL << " microssegundos.\n";
        std::cout << "Binary search: " << duracao_BB << " microssegundos.\n\n";

        salvar_arquivo(tamanho, duracao_BS, duracao_MS, duracao_BL, duracao_BB);
    }

    gerar_graficos();

    return 0;
}