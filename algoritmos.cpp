#include "algoritmos.h"
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

        long long totalBS = 0, totalMS = 0;
        long long total_BLPC = 0, total_BBPC = 0;
        long long total_BLMC = 0, total_BBMC = 0;

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
            auto inicioBS = high_resolution_clock::now();
            bubble_sort(ordenado_bubble, tamanho);
            auto fimBS = high_resolution_clock::now();
            totalBS += duration_cast<microseconds>(fimBS - inicioBS).count();

            // merge sort
            auto inicioMS = high_resolution_clock::now();
            merge_sort(ordenado_merge, 0, tamanho - 1);
            auto fimMS = high_resolution_clock::now();
            totalMS += duration_cast<microseconds>(fimMS - inicioMS).count();

            // chaves de busca
            // pior caso linear:  chave não encontrada (-1), percorre tudo
            // melhor caso linear: primeiro elemento
            // pior caso binária:  chave não encontrada (-1), percorre tudo
            // melhor caso binária: elemento do meio
            int chave_pior_linear = -1;
            int chave_melhor_linear = lista_aleatoria[0];
            int chave_pior_binary = -1;
            int chave_melhor_binary = ordenado_merge[tamanho / 2];

            // BUSCA LINEAR==================================================================================

            // pior caso
            auto inicio_BLPC = high_resolution_clock::now();
            linear_search(lista_aleatoria, tamanho, chave_pior_linear);
            auto fim_BLPC = high_resolution_clock::now();
            total_BLPC += duration_cast<microseconds>(fim_BLPC - inicio_BLPC).count();

            // melhor caso
            auto inicio_BLMC = high_resolution_clock::now();
            linear_search(lista_aleatoria, tamanho, chave_melhor_linear);
            auto fim_BLMC = high_resolution_clock::now();
            total_BLMC += duration_cast<microseconds>(fim_BLMC - inicio_BLMC).count();

            // BUSCA BINÁRIA=================================================================================

            // pior caso
            auto inicio_BBPC = high_resolution_clock::now();
            binary_search(ordenado_merge, 0, tamanho - 1, chave_pior_binary);
            auto fim_BBPC = high_resolution_clock::now();
            total_BBPC += duration_cast<microseconds>(fim_BBPC - inicio_BBPC).count();

            // melhor caso
            auto inicio_BBMC = high_resolution_clock::now();
            binary_search(ordenado_merge, 0, tamanho - 1, chave_melhor_binary);
            auto fim_BBMC = high_resolution_clock::now();
            total_BBMC += duration_cast<microseconds>(fim_BBMC - inicio_BBMC).count();

            //==============================================================================================

            delete[] lista_aleatoria;
            delete[] ordenado_bubble;
            delete[] ordenado_merge;
        }

        // médias
        long long duracaoBS = totalBS / repeticoes;
        long long duracaoMS = totalMS / repeticoes;
        long long duracao_BLPC = total_BLPC / repeticoes;
        long long duracao_BBPC = total_BBPC / repeticoes;
        long long duracao_BLMC = total_BLMC / repeticoes;
        long long duracao_BBMC = total_BBMC / repeticoes;

        cout << "\n================ Tempos de execução (média de " << repeticoes << " repetições) ================\n\n";
        cout << "Algorítmos de ordenação para arrays de tamanho " << tamanho << ":\n";
        cout << "Bubble sort: " << duracaoBS << " microssegundos.\n";
        cout << "Merge sort:  " << duracaoMS << " microssegundos.\n\n";
        cout << "Algorítmos de busca no pior caso:\n";
        cout << "Linear search: " << duracao_BLPC << " microssegundos.\n";
        cout << "Binary search: " << duracao_BBPC << " microssegundos.\n\n";
        cout << "Algorítmos de busca no melhor caso:\n";
        cout << "Linear search: " << duracao_BLMC << " microssegundos.\n";
        cout << "Binary search: " << duracao_BBMC << " microssegundos.\n\n";

        salvar_arquivo(tamanho, duracaoBS, duracaoMS, duracao_BLPC, duracao_BBPC, duracao_BLMC, duracao_BBMC);
    }

    return 0;
}