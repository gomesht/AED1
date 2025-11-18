#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int adj[30][30];
int visited[30];
int presente[30];
int n_vertices;

void dfs(int v, int component[], int *size) {
    visited[v] = 1;
    component[*size] = v;
    (*size)++;
    
    for (int i = 0; i < n_vertices; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i, component, size);
        }
    }
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int v, e;
    int caso = 1;
    
    while (scanf("%d %d", &v, &e)) {
        if (v == 0 && e == 0) break;
        
        printf("Case #%d:\n", caso++);
        
        // Inicializar
        memset(adj, 0, sizeof(adj));
        memset(visited, 0, sizeof(visited));
        n_vertices = v;
        
        // Ler as arestas
        for (int i = 0; i < e; i++) {
            char u, w;
            scanf(" %c %c", &u, &w);
            int iu = u - 'a';
            int iw = w - 'a';
            adj[iu][iw] = 1;
            adj[iw][iu] = 1;  // grafo não direcionado
        }
        
        int num_components = 0;
        
        // Encontrar componentes conexos
        for (int i = 0; i < v; i++) {
            if (!visited[i]) {
                int component[30];
                int size = 0;
                
                dfs(i, component, &size);
                
                // Ordenar os vértices do componente
                qsort(component, size, sizeof(int), compare);
                
                // Imprimir o componente
                for (int j = 0; j < size; j++) {
                    printf("%c,", 'a' + component[j]);
                }
                printf("\n");
                
                num_components++;
            }
        }
        
        printf("%d connected components\n\n");
    }
    
    return 0;
}
