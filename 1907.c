#include <stdio.h>

int N, M;
char matriz[1025][1025];
int visitado[1025][1025];

// Direções: cima, baixo, esquerda, direita
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void dfs(int x, int y) {
    if (x < 0 || x >= N || y < 0 || y >= M) return;
    if (visitado[x][y] || matriz[x][y] == 'o') return;
    
    visitado[x][y] = 1;
    
    // Visitar todas as células adjacentes
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        dfs(nx, ny);
    }
}

int main() {
    scanf("%d %d", &N, &M);
    
    // Ler a matriz
    for (int i = 0; i < N; i++) {
        scanf("%s", matriz[i]);
    }
    
    // Inicializar matriz de visitados
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            visitado[i][j] = 0;
        }
    }
    
    int componentes = 0;
    
    // Contar componentes conexos de células brancas ('.')
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (matriz[i][j] == '.' && !visitado[i][j]) {
                dfs(i, j);
                componentes++;
            }
        }
    }
    
    printf("%d\n", componentes);
    
    return 0;
}
