/*
  Binary Search é um algoritmo de busca eficiente que funciona em listas ordenadas. Ele divide a lista repetidamente 
  em duas metades para localizar o elemento procurado.

  1. ***Dividir e Conquistar (Divide and Conquer)***:
    O algoritmo começa verificando o elemento do meio da lista. Se o valor procurado for menor que o valor do meio, 
    o algoritmo foca na metade esquerda. Se o valor for maior, foca na metade direita. 
    Esse processo de divisão continua até encontrar o valor ou até que a lista seja reduzida a zero.
    
  Pontos importantes:
    - Funciona apenas com listas que já estão ordenadas.
    - Em cada passo, o algoritmo reduz o espaço de busca pela metade.
    - Usa o conceito de divisão e conquista para reduzir o tempo de busca.

  Complexidade:
    Melhor Caso: O(1) – ocorre se o elemento for o do meio na primeira tentativa.
    Pior Caso: O(log n) – em listas grandes, o número de passos cresce logaritmicamente.
    Caso Médio: O(log n) – em média, o algoritmo precisa de log(n) comparações.
*/

#include <stdio.h>

int binarySearch(int arr[], int target, int left, int right);

int main(void) {
  int arr[] = {1, 3, 18, 21, 72, 99, 100};  
  int n = sizeof(arr) / sizeof(arr[0]);
  int target;

  printf("Search for a number: ");
  scanf("%d", &target);

  int result = binarySearch(arr, target, 0, n - 1);
  
  if (result == -1)
    printf("Number not found.\n");
  else
    printf("Number found at index %d.\n", result);
  
  return 0;
}

int binarySearch(int arr[], int target, int left, int right) {
  if (right >= left) {
    int mid = (left + right) / 2;
    
    if (arr[mid] == target)
      return mid;

    if (target < arr[mid])
      return binarySearch(arr, target, left, mid - 1);
    
    return binarySearch(arr, target, mid + 1, right);
  } 
  
  return -1;
}