/*
  Linear Search é um algoritmo de busca simples que percorre cada elemento de uma lista ou array de forma sequencial 
  até encontrar o elemento desejado ou atingir o final da lista.

  1. ***Percorrer (Iterate)***:
    O algoritmo começa no primeiro elemento da lista e verifica se ele corresponde ao valor procurado. 
    Se houver correspondência, o índice do elemento é retornado. Caso contrário, ele continua verificando os próximos elementos.
    O processo continua até encontrar o valor ou percorrer todos os elementos da lista.
    
  Pontos importantes:
    - A busca é realizada de forma linear, um elemento após o outro.
    - Não exige que os dados estejam ordenados.
    - No pior caso, pode ser necessário percorrer toda a lista.

  Complexidade:
    Melhor Caso: O(1) – ocorre se o elemento procurado for o primeiro.
    Pior Caso: O(n) – ocorre se o elemento estiver no final da lista ou não estiver presente.
    Caso Médio: O(n) – em média, o elemento estará na metade da lista.
*/

#include <stdio.h>

int linearSearch(int arr[], int n, int target);

int main(void) {
  int arr[] = {10, 530, 20, 330, 50, 75, 1040, 48, 150, 200};
  int n = sizeof(arr) / sizeof(arr[0]);
  int target;

  printf("Search for a number in the array: ");
  scanf("%d", &target);

  int result = linearSearch(arr, n, target);

  if (result == -1)
    printf("Number not found.\n");
  else
    printf("Number found at index %d.", result);
}

int linearSearch(int arr[], int n, int target) {

  for (int i = 0; i < n; i++) {
    if (arr[i] == target) {
      return i;
    }
  }    

  return -1;
}