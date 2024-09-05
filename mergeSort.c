/*
  Merge Sort é um algoritmo de ordenação baseado em comparação que utiliza a técnica de "dividir e conquistar". 
  Ele funciona da seguinte maneira:

  1. ***Dividir (Divide)***:
    O array é recursivamente dividido em duas metades, com base em índices, sem criar novos arrays fisicamente.
    Em vez disso, apenas os índices são usados para referenciar as partes do array. Esse processo continua até que 
    cada subarray tenha apenas um elemento, pois um array com um único elemento já está ordenado por definição.
       
    A divisão é feita calculando o índice do meio em cada passo da recursão, usando a fórmula:
    `middle = left + (right - left) / 2`. Esse cálculo é feito dessa forma para evitar problemas de overflow 
    quando os valores de `left` e `right` são grandes.

  2. ***Conquistar (Conquer)***:
    Quando a divisão atinge subarrays com apenas um elemento, o processo de mesclagem começa. 
    O Merge Sort mescla dois subarrays ordenados comparando os elementos e reconstruindo o array em ordem.
    A cada passo de mesclagem, os menores elementos de cada subarray são comparados e adicionados à nova sequência.
    Esse processo garante que após cada mesclagem, o array resultante esteja ordenado. 
    A mesclagem continua até que todas as partes sejam combinadas novamente em um único array ordenado.

    Pontos importantes:
    - A divisão é feita com base no cálculo do índice do meio em cada nível da recursão.
    - O processo de mesclagem envolve comparar os elementos de dois subarrays e reconstruir um array maior ordenado 
    	em cada passo.
    - A mesclagem é a parte principal do algoritmo, onde dois subarrays ordenados se juntam para formar um array completo e ordenado.

  Complexidade:
    Caso Médio: O(n log n) – o algoritmo sempre segue a mesma estrutura de divisão e mesclagem, independentemente da entrada.
*/

#include <stdio.h>
#include <stdlib.h>

void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void printArray(int arr[], int n);

int main(void) {
    int arr[] = {100, 2, 77, 32, 41, 19};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("before merge sort:\n");
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);

    printf("after merge sort:\n");
    printArray(arr, n);

    return 0;
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n = right - left + 1;
    int *aux = (int *)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        aux[i] = arr[left + i];
    }

    int i = 0;
    int j = mid - left + 1;

    for (int k = left; k <= right; k++) {
        if (i <= mid - left && (j > right - left || aux[i] <= aux[j])) {
            arr[k] = aux[i];
            i++;
        } else {
            arr[k] = aux[j];
            j++;
        }
    }

    free(aux);
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("arr[%d]: %d\n", i, arr[i]);
    }
    printf("\n");
}
