#include <iostream>
#include <chrono>
using namespace std::chrono;

// função da busca sequencial
int linearSearch(int v[], int size, int key)
{
    // implementação da busca sequencial
    for (int i = 0; i < size; i++)
    {
        // se a chave foi encontrada, irá retornar em qual índice ela se encontra
        if (v[i] == key)
        {
            return i;
        }
    }
    // se a chave NÃO foi encontrada, então não retornará nenhum índice.
    return -1;
}

// função do bubble sort
void bubbleSort(int v[], int size)
{
    // implementação do bubble sort
    int temp = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (v[j] > v[j + 1])
            {
                temp = v[j];
                v[j] = v[j + 1];
                v[j + 1] = temp;
            }
        }
    }
}

// função de medição de tempo da busca sequencial
void measureTimeLSearch(int v[], int size, int key)
{
    auto iniLin = high_resolution_clock::now();
    int resLin = linearSearch(v, size, key);
    auto endLin = high_resolution_clock::now();
    auto durationLin = duration_cast<microseconds>(endLin - iniLin).count();
    std::cout << "Busca sequencial: índice " << resLin << " | Tempo: " << durationLin << " microssegundos" << std::endl;
}

// função de medição de tempo do bubble sort
void measureTimeBSort(int v[], int size)
{
    auto iniBub = high_resolution_clock::now();
    bubbleSort(v, size);
    auto endBub = high_resolution_clock::now();
    auto durationBub = duration_cast<microseconds>(endBub - iniBub).count();
    std::cout << "Bubble sort: tempo de execução - " << durationBub << " microssegundos." << std::endl;
}