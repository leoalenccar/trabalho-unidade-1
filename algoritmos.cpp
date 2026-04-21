#include "algoritmos.h"
using namespace std::chrono;

int main ()
{
    int tamanho;
    cout << "Qual o tamanho do vetor? (> 0): ";
    cin >> tamanho;

    while (tamanho <= 0)
    {
        cout << "\nDigite um valor válido (> 0): ";
        cin >> tamanho;
    }

    int *lista_aleatorio = new int[tamanho];

    criar_lista_aleatoria(tamanho, lista_aleatorio);

    int *ordenado_bubble = new int[tamanho];
    int *ordenado_merge = new int[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        ordenado_bubble[i] = lista_aleatorio[i];
        ordenado_merge[i] = lista_aleatorio[i];
    }


//SORT======================================================================================================

    //tempo bubble sort
    auto inicioBS = high_resolution_clock::now();

    bubble_sort(ordenado_bubble, tamanho);

    auto fimBS = high_resolution_clock::now();
    auto duracaoBS = duration_cast<microseconds>(fimBS- inicioBS).count();


    //tempo merge sort
    auto inicioMS = high_resolution_clock::now();

    merge_sort(ordenado_merge, 0, tamanho - 1);

    auto fimMS = high_resolution_clock::now();
    auto duracaoMS = duration_cast<microseconds>(fimMS - inicioMS).count();


    int chave_pior_linear = -1;
    int chave_melhor_linear = lista_aleatorio[0];
    int chave_pior_binary = -1;
    int chave_melhor_binary = ordenado_merge[tamanho / 2];

    // BUSCA LINEAR=============================================================================================

    //tempo busca linear em lista desordenada no pior caso
    auto inicio_BLPC = high_resolution_clock::now();

    linear_search(lista_aleatorio, tamanho, chave_pior_linear);

    auto fim_BLPC = high_resolution_clock::now();
    auto duracao_BLPC = duration_cast<microseconds>(fim_BLPC - inicio_BLPC).count();


    //tempo busca linear em lista desordenada no melhor caso
    auto inicio_BLMC = high_resolution_clock::now();

    linear_search(lista_aleatorio, tamanho, chave_melhor_linear);

    auto fim_BLMC = high_resolution_clock::now();
    auto duracao_BLMC = duration_cast<microseconds>(fim_BLMC - inicio_BLMC).count();


//BUSCA-BINARIA============================================================================================

    //tempo busca binária no pior caso
    auto inicio_BBPC = high_resolution_clock::now();

    binary_search(ordenado_merge, 0, tamanho - 1, chave_pior_binary);

    auto fim_BBPC = high_resolution_clock::now();
    auto duracao_BBPC = duration_cast<microseconds>(fim_BBPC - inicio_BBPC).count();


    //tempo busca binária no melhor caso
    auto inicio_BBMC = high_resolution_clock::now();

    binary_search(ordenado_merge, 0, tamanho - 1, chave_melhor_binary);

    auto fim_BBMC = high_resolution_clock::now();
    auto duracao_BBMC = duration_cast<microseconds>(fim_BBMC - inicio_BBMC).count();


//=========================================================================================================

    cout << "\n================ Tempos de execução ================\n\n";
    cout << "Algorítmos de ordenação para arrays de tamanho " << tamanho << ":\n";
    cout << "Bubble sort: " << duracaoBS << " microssegundos.\n";
    cout << "Merge sort:  " << duracaoMS << " microssegundos.\n\n";
    cout << "Algorítmos de busca para arrays de tamanho " << tamanho << " no pior caso:\n";
    cout << "Linear search: " << duracao_BLPC << " microssegundos.\n";
    cout << "Binary search: " << duracao_BBPC << " microssegundos.\n\n";
    cout << "Algorítmos de busca para arrays de tamanho " << tamanho << " no melhor caso:\n";
    cout << "Linear search: " << duracao_BLMC << " microssegundos.\n";
    cout << "Binary search: " << duracao_BBMC << " microssegundos.\n\n";


    delete[] lista_aleatorio;
    delete[] ordenado_bubble;
    delete[] ordenado_merge;

    return 0;
}