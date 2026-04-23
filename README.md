# Análise Empírica de Complexidade de Algoritmos

Trabalho prático da disciplina de Estruturas de Dados Básicos I.
O programa mede e compara empiricamente o tempo de execução de algoritmos de busca e ordenação.

## Algoritmos analisados

- Bubble Sort — O(n²)
- Merge Sort — O(n log n)
- Linear Search — O(n)
- Binary Search — O(log n)

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

O programa irá:
1. Executar cada algoritmo para entradas de tamanho 1.000, 5.000, 10.000, 50.000 e 100.000
2. Calcular a média de 10 execuções para cada tamanho
3. Salvar os resultados em `tempos.csv`
4. Gerar os gráficos automaticamente com gnuplot

## Saída

- `tempos.csv` — tempos de execução de cada algoritmo
- `grafico_bubble_sort.png`
- `grafico_merge_sort.png`
- `grafico_linear_search.png`
- `grafico_binary_search.png`