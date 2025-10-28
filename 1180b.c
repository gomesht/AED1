 
int main() { 
    int n, *vetor, numero, menor, posicao;
    scanf("%d", &n);
    vetor = malloc(n*(sizeof(int)));
    scanf("%d", &numero);
    for(int i = 0; i < n; i++){
      scanf("%d", &numero);
      vetor[i] = numero;
    }
    menor = vetor[0];
    posicao = 0;
    for (int i = 1; i < n; i++){
      if(vetor[i] < menor){
        menor = vetor[i];
        posicao = i;
      }
    }
    printf("Menor valor: %d\n ", menor);
    printf("Posicao: %d\n", posicao+1);
    return 0;
}