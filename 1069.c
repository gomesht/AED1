#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 1001

int main() {
    int N;
    char mina[MAX_SIZE];
    char pilha[MAX_SIZE];
    int topo = 0;

    if (scanf("%d", &N) != 1) return 1;
    getchar();

    while (N--) {
        if (fgets(mina, MAX_SIZE, stdin) == NULL) break;
        
        mina[strcspn(mina, "\n")] = 0;

        int diamantes = 0;
        topo = 0;

        for (int i = 0; mina[i] != '\0'; i++) {
            char caractere = mina[i];

            if (caractere == '<') {
                pilha[topo] = caractere;
                topo++;
            } else if (caractere == '>') {
                if (topo > 0) {
                    diamantes++;
                    topo--;
                }
            }
        }

        printf("%d\n", diamantes);
    }

    return 0;
}