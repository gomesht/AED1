#include <stdio.h>
 
int main() { 
    int n, posicao, numero, menor;
    scanf("%d", &n);
    scanf("%d", &numero);
    menor = numero;
    posicao = 0;
    for(int i = 1; i < n; i++){
        scanf("%d", &numero);
        if (numero < menor){
            menor = numero;
            posicao = i;
        }
    }
    printf("Menor valor: %d\n", menor);
    printf("Posicao: %d\n", ++posicao);
    return 0;
}