#include <iostream>
using namespace std;

void merge (int array[], int inicio, int meio, int fim)
{
    int n = fim - inicio + 1;
    int i = inicio;
    int j = meio + 1;
    int k = 0;

    int temp[n];

    while (i <= meio && j <= fim)
    {
        if (array[i] <= array[j])
        {
            temp[k] = array[i];
            i++, k++;
        }
        else
        {
            temp[k] = array[j];
            j++;
            k++;
        }
    }

    while (i <= meio)
    {
        temp[k] = array[i];
        i++;
        k++;
    }

    while (j <= fim)
    {
        temp[k] = array[j];
        j++;
        k++;
    }

    for (int m = 0; m < k; m++)
    {
        array[inicio + m] = temp[m];
    }
}

void merge_sort (int array[], int inicio, int fim)
{
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;
        merge_sort(array, inicio, meio);
        merge_sort(array, meio + 1, fim);
        merge(array, inicio, meio, fim);
    }
}

int binary_search (int array[], int inicio, int fim, int chave)
{
    if (inicio > fim)
    {
        return -1;
    }

    int meio = (inicio + fim) / 2;

    if (array[meio] == chave)
    {
        return meio;
    }

    else if (array[meio] < chave)
    {
        return binary_search(array, meio + 1, fim, chave);
    }
    else
    {
        return binary_search(array, inicio, meio - 1, chave);
    }
}

int main ()
{
/*
    int tamanho;
    cin >> tamanho;

    int lista[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
        cin >> lista[i];
    }

    int chave;
    cin >> chave;

    int indice = binary_search (lista, 0, tamanho -1, chave);
*/

    int n = 8;
    int lista[8] = {1,3,6,4,1,9,2,7};

    for (int i = 0; i < 8; i++)
    {
        cout << lista[i] << " ";
    }
    cout << endl;

    merge_sort(lista, 0, 8 - 1);

    for (int i = 0; i < 8; i++)
    {
        cout << lista[i] << " ";
    }
    cout << endl;

    return 0;
}