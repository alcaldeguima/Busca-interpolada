#include <stdio.h>
#include <stdlib.h>

int busca_interpolada(int *arr, int tamanho, int valor)
{
  int inicio = 0;
  int final = tamanho - 1;
  while (inicio <= final)
  {

    int meio = inicio + ((final - inicio) * (valor - arr[inicio])) / (arr[final] - arr[inicio]);

    if (valor < arr[meio])
      final = meio - 1;

    else if (valor > arr[meio])
      inicio = meio + 1;
    else
      return meio;
  }
  return -1;
}

int main()
{

  int i, achar, arr[10] = {4, 10, 16, 21, 22, 30, 34, 37, 45, 54};

  for (i = 0; i < 10; i++)
  {
    printf("[%d]  ", arr[i]);
  }

  printf("\nQual valor deseja procurar: ");
  scanf("%d", &achar);

  int ret_interpolation = busca_interpolada(arr, 10, achar);

  if (ret_interpolation != -1)
  {
    printf("\nO valor se encontra no vetor na posicao %d", ret_interpolation);
  }
  else
    printf("\nO valor não se encontra no vetor!");
}
