#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
    int valor;
    struct cel *seg;
} celula;

void inserir_fim(celula** inicio, celula** fim, int valor);
int remover_inicio(celula** inicio, celula** fim);
int esta_vazia(celula* inicio);

int main() {
    int n;
    
    while (scanf("%d", &n) && n != 0) {
        celula *inicio = NULL;
        celula *fim = NULL;
        int descartadas[50];
        int num_descartadas = 0;
        
        for (int i = 1; i <= n; i++) {
            inserir_fim(&inicio, &fim, i);
        }
        
        while (inicio != fim) {
            descartadas[num_descartadas++] = remover_inicio(&inicio, &fim);
            
            if (!esta_vazia(inicio)) {
                int carta_topo = remover_inicio(&inicio, &fim);
                inserir_fim(&inicio, &fim, carta_topo);
            }
        }
        
        printf("Discarded cards:");
        for (int i = 0; i < num_descartadas; i++) {
            if (i == 0) {
                printf(" %d", descartadas[i]);
            } else {
                printf(", %d", descartadas[i]);
            }
        }
        printf("\n");
        
        printf("Remaining card: %d\n", inicio->valor);
        
        free(inicio);
    }
    
    return 0;
}

void inserir_fim(celula** inicio, celula** fim, int valor) {
    celula *nova = malloc(sizeof(celula));
    nova->valor = valor;
    nova->seg = NULL;
    
    if (*inicio == NULL) {
        *inicio = *fim = nova;
        nova->seg = nova;
    } else {
        nova->seg = *inicio;
        (*fim)->seg = nova;
        *fim = nova;
    }
}

int remover_inicio(celula** inicio, celula** fim) {
    if (*inicio == NULL) return -1;
    
    celula *temp = *inicio;
    int valor = temp->valor;
    
    if (*inicio == *fim) {
        *inicio = *fim = NULL;
    } else {
        *inicio = (*inicio)->seg;
        (*fim)->seg = *inicio;
    }
    
    free(temp);
    return valor;
}

int esta_vazia(celula* inicio) {
    return inicio == NULL;
}
