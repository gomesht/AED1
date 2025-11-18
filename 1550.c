#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_VAL 10000

int reverseNumber(int num) {
    int reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return reversed;
}

int bfs(int start, int target) {
    if (start == target) return 0;
    
    int visited[MAX_VAL];
    int queue[MAX_VAL];
    int distance[MAX_VAL];
    int front = 0, rear = 0;
    
    memset(visited, 0, sizeof(visited));
    memset(distance, 0, sizeof(distance));
    
    queue[rear++] = start;
    visited[start] = 1;
    distance[start] = 0;
    
    while (front < rear) {
        int current = queue[front++];
        
        // Operação 1: adicionar 1
        int next1 = current + 1;
        if (next1 < MAX_VAL && !visited[next1]) {
            visited[next1] = 1;
            distance[next1] = distance[current] + 1;
            queue[rear++] = next1;
            
            if (next1 == target) {
                return distance[next1];
            }
        }
        
        // Operação 2: inverter dígitos
        int next2 = reverseNumber(current);
        if (next2 < MAX_VAL && !visited[next2]) {
            visited[next2] = 1;
            distance[next2] = distance[current] + 1;
            queue[rear++] = next2;
            
            if (next2 == target) {
                return distance[next2];
            }
        }
    }
    
    return -1; // Não encontrado (não deveria acontecer)
}

int main() {
    int t;
    scanf("%d", &t);
    
    while (t--) {
        int a, b;
        scanf("%d %d", &a, &b);
        
        int result = bfs(a, b);
        printf("%d\n", result);
    }
    
    return 0;
}
