#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int n, v, a;
        scanf("%d", &n);        // nodo de início/fim
        scanf("%d %d", &v, &a); // vértices e arestas
        
        // Array para contar o grau de cada vértice
        int grau[50] = {0};
        
        // Ler as arestas e contar graus
        for (int i = 0; i < a; i++) {
            int u, w;
            scanf("%d %d", &u, &w);
            grau[u]++;
            grau[w]++;
        }
        int impares = 0;
        for (int i = 0; i < v; i++) {
            if (grau[i] % 2 == 1) {
                impares++;
            }
        }
        int movimentos = a + (impares / 2);
        
        printf("%d\n", movimentos);
    }
    
    return 0;
}
