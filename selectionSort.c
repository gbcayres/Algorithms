/*
  Selection Sort é um algoritmo de ordenação simples, baseado na ideia de encontrar o menor (ou maior) elemento da lista 
  e colocá-lo em sua posição correta.

  1. ***Selecionar o menor elemento (Select)***:
    O algoritmo percorre a lista procurando o menor elemento e o troca com o primeiro elemento. 
    Depois, ele repete o processo para os elementos restantes, colocando o segundo menor elemento na segunda posição, 
    e assim por diante até que a lista esteja ordenada.
    
  Pontos importantes:
    - O algoritmo realiza trocas apenas quando o menor elemento é encontrado, o que o diferencia de outros métodos.
    - Não é um algoritmo estável, pois pode alterar a ordem de elementos iguais durante as trocas.
    - É fácil de implementar, mas ineficiente para grandes listas.

  Complexidade:
    Melhor Caso: O(n²) – mesmo com a lista já ordenada, o algoritmo percorre todos os elementos para encontrar o menor.
    Pior Caso: O(n²) – no pior cenário, o número de comparações e trocas permanece quadrático.
    Caso Médio: O(n²) – o algoritmo sempre faz aproximadamente n²/2 comparações e n trocas.
*/

#include <stdio.h>
#include <stdlib.h>

void selectionSort(int arr[], int n);
void swap(int *a, int *b);
void printArray(int arr[], int n);

int main(void) {
  int arr[] = {6, 3, 10, 25, 56, 20, 100};
  int n = sizeof(arr) / sizeof(arr[0]);

  printf("Before selection sort\n");
  printArray(arr, n);

  selectionSort(arr, n);

  printf("After selection sort\n");
  printArray(arr, n);

  return 0;
}

void selectionSort(int arr[], int n) {
  for (int i = 0; i < n - 1; i++) {
    int minIndex = i;

    for (int j = i + 1; j < n; j++) {
      if (arr[j] < arr[minIndex]) {
        minIndex = j;
      }
    }

    if (minIndex != i) {
      swap(&arr[i], &arr[minIndex]);
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