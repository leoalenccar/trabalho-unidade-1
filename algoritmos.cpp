#include <iostream>
#include <cstdlib> //rand()
#include <chrono>
using namespace std;
using namespace std::chrono;


//função da busca sequencial
int linear_search (int array[], int tamanho, int chave)
{
    //implementação da busca sequencial
    for (int i = 0; i < tamanho; i++)
    {
        //compara cada elemento do array com a chave
        if (array[i] == chave)
        {
            //se a chave foi encontrada, retorna o índice onde ela está
            return i;
        }
    }

    //se a chave NÂO foi encontrada retorna -1
    return -1;
}


//função de busca binária
int binary_search (int array[], int inicio, int fim, int chave)
{
    //implementação da busca binária

    //condição de parada: se a chave NÂO foi encontrada retorna -1
    if (inicio > fim)
    {
        return -1;
    }

    //índice central
    int meio = (inicio + fim) / 2;


    //compara o elemento que está no índice central com a chave, se a chave foi encontrada, retorna o índice onde ela está
    if (array[meio] == chave)
    {
        return meio;
    }

    //se a chave for maior que o elemento central, procura a chave na metade direita do array
    else if (array[meio] < chave)
    {
        return binary_search(array, meio + 1, fim, chave);
    }
    //se a chave for menor que o elemento central, procura a chave na metade esquerda do array
    else
    {
        return binary_search(array, inicio, meio - 1, chave);
    }
}


//função do bubble sort
void bubble_sort (int array[], int tamanho)
{
    //implementação do bubble sort
    int temp;
    for (int i = 0; i < tamanho; i++)
    {
        for (int j = 0; j < tamanho - i - 1; j++)
        {
            if (array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}


//função de intercalação de dois arrays
void merge (int array[], int inicio, int meio, int fim)
{
    //tamanho
    int n = fim - inicio + 1;
    //índice do inicio da metade esquerda
    int i = inicio;
    //índice do início da metade direita
    int j = meio + 1;
    //índice do array temporário
    int k = 0;

    //array temporário que armazena os elementos da intercalação
    int temp[n];

    //percorre as duas metades enquanto ambas tiverem elementos
    while (i <= meio && j <= fim)
    {
        //se o elemento da esquerda for menor ou igual, copia ele para o array temporário temp
        if (array[i] <= array[j])
        {
            temp[k] = array[i];
            i++, k++;
        }
        //se o elemento da direita for menor, copia ele para o vetor temporário temp
        else
        {
            temp[k] = array[j];
            j++;
            k++;
        }
    }

    //copia os elementos restantes da metade esquerda
    while (i <= meio)
    {
        temp[k] = array[i];
        i++;
        k++;
    }

    //copia os elementos restantes da metade direita
    while (j <= fim)
    {
        temp[k] = array[j];
        j++;
        k++;
    }

    //copia o array temporário de volta para o array original
    for (int m = 0; m < k; m++)
    {
        array[inicio + m] = temp[m];
    }
}

//função de ordenação por intercalação
void merge_sort (int array[], int inicio, int fim)
{
    //condição de parada: vetor com um único elemento já está ordenado
    if (inicio < fim)
    {
        //índice central
        int meio = (inicio + fim) / 2;
        //ordena a metade esquerda
        merge_sort(array, inicio, meio);
        //ordena a metade direita
        merge_sort(array, meio + 1, fim);
        //intercala as duas metades ordenadas
        merge(array, inicio, meio, fim);
    }
}


void criar_lista_ordenada (int n, int ordenada[])
{
    for (int i = 0; i < n; i++)
    {
        ordenada[i] = i;
    }
}

void criar_lista_aleatoria (int n, int aleatoria[])
{
    for (int i = 0; i < n; i++)
    {
        aleatoria[i] = rand() % 100;
    }
}



int main ()
{
/*
    int tamanho;
    cout << "Qual o tamanho do vetor? (> 0): ";
    cin >> tamanho;

    while (tamanho <= 0)
    {
        cout << "\nDigite um valor válido (> 0): ";
        cin >> tamanho;
    }

    int tipo;
    cout << "\nQual algorítimo você deseja testar?\n\n";
    cout << "1 - Linear search\n";
    cout << "2 - Binary search\n";
    cout << "3 - Bubble sort\n";
    cout << "4 - Merge sort\n";
    cin >> tipo;

    while (tipo < 1 || tipo > 4)
    {
        cout << "\nDigite um valor válido (1 <= tipo <= 4): ";
        cin >> tipo;
    }

    int vetor[tamanho];

    if (tipo < 3)
    {
        int chave = rand() % 100;
        criar_lista_ordenada(tamanho, vetor);
        switch (tipo)
        {
            case 1:
                linear_search(vetor, tamanho, chave);
                break;
            case 2:
                binary_search(vetor, 0, tamanho - 1, chave);
                break
        }
    }
    else
    {
        criar_lista_aleatoria(tamanho, vetor);
        switch (tipo)
        {
            case 3:
                bubble_sort(vetor, tamanho);
                break;
            case 4:
                merge_sort(vetor, 0, tamanho - 1);
                break;
        }
    }
*/



    int n = 100;
    int lista[n];

    criar_lista_aleatoria(n, lista);

    cout << "Lista original: ";
    for (int i = 0; i < n; i++)
    {
        cout << lista[i] << " ";
    }
    cout << endl;

    auto inicioSeq = high_resolution_clock::now();
    /*
    merge_sort(lista, 0, n - 1);
    */
   bubble_sort(lista, n);
    auto fimSeq = high_resolution_clock::now();
    auto duracaoSeq = duration_cast<microseconds> (fimSeq - inicioSeq).count();

    cout << "Lista ordenada com merge sort: ";
    for (int i = 0; i < n; i++)
    {
        cout << lista[i] << " ";
    }
    cout << endl << endl;

    cout << "Para n = " << n << ", Tempo: " << duracaoSeq << " Microsegundos." << endl;

    return 0;
}