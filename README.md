# Análise Empírica de Complexidade de Algoritmos

Trabalho prático da disciplina de Estruturas de Dados Básicos I.
O programa mede e compara empiricamente o tempo de execução de algoritmos de busca e ordenação.

## Algoritmos analisados

- Bubble Sort - O(n²)
- Merge Sort - O(n log n)
- Linear Search - O(n)
- Binary Search - O(log n)

## Estrutura do projeto

+ trabalho-edb
  + algoritmos
    + algoritmos.cpp
    + algoritmos.h
  + funcoes
    + funcoes.cpp
    + funcoes.h
  + main
    + main.cpp
    + graficos.gp

  + relatorio
    + grafico_binary_search.png
    + grafico_bubble_sort.png
    + grafico_linear_search.png
    + grafico_merge_sort.png
    + tempos.csv
+ README.md

## Dependências

- g++
- gnuplot

## Como compilar

- cd main
- g++ main.cpp ../algoritmos/algoritmos.cpp ../funcoes/funcoes.cpp -o programa

## Como executar

- ./programa
