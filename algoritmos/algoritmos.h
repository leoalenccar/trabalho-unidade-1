#ifndef ALGORITMOS_H
#define ALGORITMOS_H

// função da busca sequencial
int linear_search(int array[], int tamanho, int chave);

// função de busca binária
int binary_search(int array[], int inicio, int fim, int chave);


// função do bubble sort
void bubble_sort(int array[], int tamanho);

// função de intercalação de dois arrays
void merge(int array[], int inicio, int meio, int fim);

// função de ordenação por intercalação
void merge_sort(int array[], int inicio, int fim);

// função para criar lista ordenada, 0 à n
void criar_lista_ordenada(int n, int ordenada[]);

// função para criar lista aleatória, números podem ir de 0 à 99
void criar_lista_aleatoria(int n, int aleatoria[]);


void salvar_arquivo (int tamanho, long long duracao_BS, long long duracao_MS, long long duracao_BLPC, long long duracao_BBPC);

#endif