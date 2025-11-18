#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int dest;
    struct Node* next;
} Node;

typedef struct Graph {
    int V;
    Node** adj;
} Graph;

#define NAO_VISITADO 0
#define EM_PROCESSAMENTO 1
#define PROCESSADO 2

Node* createNode(int dest) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

Graph* createGraph(int V) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->V = V;
    graph->adj = (Node**)calloc((V + 1), sizeof(Node*));
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    Node* newNode = createNode(dest);
    newNode->next = graph->adj[src];
    graph->adj[src] = newNode;
}

void freeGraph(Graph* graph) {
    for (int i = 1; i <= graph->V; i++) {
        Node* current = graph->adj[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(graph->adj);
    free(graph);
}

int dfs(Graph* graph, int u, int visited[]) {
    visited[u] = EM_PROCESSAMENTO;

    Node* current = graph->adj[u];
    while (current != NULL) {
        int v = current->dest;

        if (visited[v] == EM_PROCESSAMENTO) {
            return 1; // Ciclo encontrado
        }

        if (visited[v] == NAO_VISITADO && dfs(graph, v, visited)) {
            return 1;
        }
        
        current = current->next;
    }

    visited[u] = PROCESSADO;
    return 0;
}

void solve() {
    int N, M;
    
    scanf("%d %d", &N, &M);

    Graph* graph = createGraph(N);
    int* visited = (int*)calloc(N + 1, sizeof(int));

    for (int i = 0; i < M; i++) {
        int A, B;
        scanf("%d %d", &A, &B);
        addEdge(graph, A, B);
    }

    int ciclo_encontrado = 0;

    for (int i = 1; i <= N; i++) {
        if (visited[i] == NAO_VISITADO) {
            if (dfs(graph, i, visited)) {
                ciclo_encontrado = 1;
                break;
            }
        }
    }

    if (ciclo_encontrado) {
        printf("SIM\n");
    } else {
        printf("NAO\n");
    }
    
    free(visited);
    freeGraph(graph);
}

int main() {
    int T;
    scanf("%d", &T);
    
    while (T--) {
        solve();
    }

    return 0;
}