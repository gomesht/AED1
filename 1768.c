#include <stdio.h>

int main() {
    int tamanho;

    while (scanf("%d", &tamanho) == 1) {
        // Parte superior da árvore (triângulo)
        for (int i = 1; i <= tamanho; i += 2) {
            // Imprimir espaços à esquerda
            int espacos = (tamanho - i) / 2;
            for (int j = 0; j < espacos; j++) {
                printf(" ");
            }
            
            // Imprimir asteriscos
            for (int z = 0; z < i; z++) {
                printf("*");
            }
            
            printf("\n");
        }

        // Primeira linha do tronco (1 asterisco)
        int espacos_tronco1 = (tamanho - 1) / 2;
        for (int j = 0; j < espacos_tronco1; j++) {
            printf(" ");
        }
        printf("*\n");

        // Segunda linha do tronco (3 asteriscos)
        int espacos_tronco2 = (tamanho - 3) / 2;
        for (int j = 0; j < espacos_tronco2; j++) {
            printf(" ");
        }
        printf("***\n");
        
        printf("\n");
    }

    return 0;
}