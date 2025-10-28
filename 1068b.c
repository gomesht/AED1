#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct cel {
    char valor;
    struct cel *seg;
} celula;

void push(celula** pilha, char valor);
int pop(celula** pilha);
int isEmpty(celula* pilha);

int main() {
    char expressao[1001];
    
    while (scanf("%s", expressao) != EOF) {
        celula *pilha = NULL;
        int correto = 1;
        int tamanho = strlen(expressao);
        
        for (int i = 0; i < tamanho; i++) {
            if (expressao[i] == '(') {
                push(&pilha, '(');
            } else if (expressao[i] == ')') {
                if (isEmpty(pilha)) {
                    correto = 0;
                    break;
                } else {
                    pop(&pilha);
                }
            }
        }
        
        if (!isEmpty(pilha)) {
            correto = 0;
        }
        
        while (!isEmpty(pilha)) {
            pop(&pilha);
        }
        
        if (correto) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    
    return 0;
}

void push(celula** pilha, char valor) {
    celula *nova = malloc(sizeof(celula));
    nova->valor = valor;
    nova->seg = *pilha;
    *pilha = nova;
}

int pop(celula** pilha) {
    if (*pilha == NULL) {
        return 0;
    }
    
    celula *temp = *pilha;
    *pilha = (*pilha)->seg;
    free(temp);
    return 1;
}

int isEmpty(celula* pilha) {
    return pilha == NULL;
}
