#include <stdio.h>

int main() {
    int v, t;
    
    while (scanf("%d %d", &v, &t) == 2) {
        // Deslocamento no dobro do tempo é 2 * v * t
        int deslocamento = 2 * v * t;
        printf("%d\n", deslocamento);
    }
    
    return 0;
}
