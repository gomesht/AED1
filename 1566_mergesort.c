#include <stdio.h>
#include <stdlib.h>

void merge(int *vetor, int inicio, int meio, int fim);
void mergeSort(int *vetor, int inicio, int fim);

int main() {
    int NC;
    scanf("%d", &NC);

    for (int i = 0; i < NC; i++) {
        int N;
        scanf("%d", &N);

        int *vetor = malloc(N * sizeof(int)); 

        for (int j = 0; j < N; j++) {
            scanf("%d", &vetor[j]);
        }

        mergeSort(vetor, 0, N - 1);

        for (int j = 0; j < N; j++) {
            if (j > 0) printf(" ");
            printf("%d", vetor[j]);
        }
        printf("\n");
        
        free(vetor);
    }
    
    return 0;
}

void merge(int *vetor, int inicio, int meio, int fim) {
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;
    
    int *esq = malloc(n1 * sizeof(int));
    int *dir = malloc(n2 * sizeof(int));
    
    for (int i = 0; i < n1; i++)
        esq[i] = vetor[inicio + i];
    for (int j = 0; j < n2; j++)
        dir[j] = vetor[meio + 1 + j];
    
    int i = 0, j = 0, k = inicio;
    
    while (i < n1 && j < n2) {
        if (esq[i] <= dir[j]) {
            vetor[k] = esq[i];
            i++;
        } else {
            vetor[k] = dir[j];
            j++;
        }
        k++;
    }
    
    while (i < n1) {
        vetor[k] = esq[i];
        i++;
        k++;
    }
    
    while (j < n2) {
        vetor[k] = dir[j];
        j++;
        k++;
    }
    
    free(esq);
    free(dir);
}

void mergeSort(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int meio = inicio + (fim - inicio) / 2;
        
        mergeSort(vetor, inicio, meio);
        mergeSort(vetor, meio + 1, fim);
        
        merge(vetor, inicio, meio, fim);
    }
}
