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

        int j, k, x;
        for (j = 1; j < N; j++) {
            x = vetor[j];
            for (k = j-1; k >= 0 && vetor[k] > x; k--) {
                vetor[k+1]=vetor[k];
            }
            vetor[k+1] = x;
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