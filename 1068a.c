#include <stdio.h>
#include <string.h>

int main() {
    char expressao[1001];
    
    while (scanf("%s", expressao) != EOF) {
        int pilha[1000];
        int topo = -1;
        int correto = 1;
        int tamanho = strlen(expressao);
        
        for (int i = 0; i < tamanho; i++) {
            if (expressao[i] == '(') {
                topo++;
                pilha[topo] = 1;
            } else if (expressao[i] == ')') {
                if (topo == -1) {
                    correto = 0;
                    break;
                } else {
                    topo--;
                }
            }
        }
        
        if (topo != -1) {
            correto = 0;
        }
        
        if (correto) {
            printf("correct\n");
        } else {
            printf("incorrect\n");
        }
    }
    
    return 0;
}
