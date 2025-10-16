#include <stdio.h>
#include <stdlib.h>

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

        int j, k, min, temp;
        for (j =0; j < N-1; j++) {   
            min = j;        
            for (k = j+1; k <N; k++) {
                if (vetor[k] < vetor[min]) {
                    min = j;
                }
            temp = vetor[j];
            vetor[j] = vetor[min];
            vetor[min] = temp;
            }

        }

        for (int j = 0; j < N; j++) {
            if (j > 0) printf(" ");
            printf("%d", vetor[j]);
        }
        printf("\n");
        
        free(vetor);
    }
    
    return 0;
}