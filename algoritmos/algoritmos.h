// ============================================================
// Arquivo: algoritmos.h
// Descrição: declaração dos algoritmos de busca e ordenação
// Autor 1: Leonardo Alencar de Aquino
// Autor 2: Arthur Victor Vieira Almeida
// Data: abril de 2026
// Disciplina: Estruturas de Dados Básicas I
// ============================================================

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

#endif