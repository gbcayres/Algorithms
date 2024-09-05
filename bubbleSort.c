/*
  Bubble Sort é um algoritmo de ordenação simples que compara repetidamente pares de elementos adjacentes 
  e os troca de posição se estiverem na ordem errada.

  1. ***Comparar e Trocar (Compare and Swap)***:
    O algoritmo percorre a lista várias vezes, comparando pares adjacentes de elementos. Se um par está na ordem errada 
    (por exemplo, o elemento da esquerda é maior que o da direita), os elementos são trocados.
    Esse processo é repetido até que a lista esteja completamente ordenada, e nenhum par precise ser trocado.
    
  Pontos importantes:
    - O algoritmo é simples, mas ineficiente para grandes listas, pois faz muitas trocas.
    - O nome "bubble" vem do fato de que os maiores elementos vão "flutuando" para o final da lista em cada iteração.
    - É um algoritmo estável, pois não altera a ordem relativa de elementos iguais.
    
  Complexidade:
    Melhor Caso: O(n) – ocorre se a lista já estiver ordenada, pois uma passagem confirmará que não há trocas necessárias.
    Pior Caso: O(n²) – quando a lista está completamente desordenada, o algoritmo precisará fazer o máximo de trocas.
    Caso Médio: O(n²) – em média, o algoritmo faz cerca de n²/2 comparações.
*/


#include <stdio.h>
#include <stdbool.h>

void bubbleSort(int arr[], int n);
void swap(int *a, int *b);
void printArray(int arr[], int n);

int main(void) {
  int arr[] = {1, 3, 21, 18, 72, 100, 99};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Before bubble sort\n");
  printArray(arr, n);

  bubbleSort(arr, n);

  printf("After bubble sort\n");
  printArray(arr, n);

  return 0;
}

void bubbleSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    bool swapped = false;

    for (int j = 0; j < n - 1 - i; j++) {
      if (arr[j] > arr[j + 1]) { 
        swap(&arr[j], &arr[j + 1]);
        swapped = true;
      }
    }

    if (!swapped) {
      break;
    }
  }
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void printArray(int arr[], int n) {
  for (int i = 0; i < n; i++) {
    printf("arr[%d]: %d\n", i, arr[i]);
  }
  printf("\n");
}