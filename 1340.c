#include <stdio.h>
#include <stdlib.h>

typedef struct cel {
  int valor;
  struct cel *seg;  
} celula;

int queue(celula** queueI, celula** queueF, int comando, int x);
int priorityQueue (celula** priorityQueue, int comando, int x);
int stack(celula** stack, int comando, int x);
int main() {
  int n, comando, x;
  
  while (scanf("%d", &n) != EOF) {
    // Inicializar estruturas
    celula *queueI = malloc(sizeof(celula));  
    queueI->seg = NULL; 
    celula *queueF = queueI;     
    celula *priorityQueueI = malloc(sizeof(celula)); 
    priorityQueueI->seg = NULL;
    celula *stackI = malloc(sizeof(celula));   
    stackI->seg = NULL;     
    
    int stack_ok = 1, queue_ok = 1, priority_ok = 1;
    
    for( int i = 0; i < n; i++){
      scanf("%d", &comando);
      if (comando == 1) {
        scanf("%d", &x);
        stack(&stackI, comando, x);
        queue(&queueI, &queueF, comando, x);
        priorityQueue(&priorityQueueI, comando, x);
      } else {
        scanf("%d", &x);
        if (stack(&stackI, comando, x) != x) stack_ok = 0;
        if (queue(&queueI, &queueF, comando, x) != x) queue_ok = 0;
        if (priorityQueue(&priorityQueueI, comando, x) != x) priority_ok = 0;
      }
    }
    
    // Resultado
    int count = stack_ok + queue_ok + priority_ok;
    if (count == 0) printf("impossible\n");
    else if (count > 1) printf("not sure\n");
    else if (stack_ok) printf("stack\n");
    else if (queue_ok) printf("queue\n");
    else printf("priority queue\n");
  }
  
  return 0;
}
int queue(celula** queueI, celula** queueF, int comando, int x){
  switch (comando){
  //push  
  case 1: {
    celula *nova = malloc (sizeof (celula));
    nova->valor = x;
    nova->seg = NULL;
    (*queueF)->seg = nova;
    *queueF = nova;
    break;
  }
  //pop
  case 2: {
    if ((*queueI)->seg == NULL) return -1;
    celula *p = (*queueI)->seg;
    (*queueI)->seg = p->seg;
    if(p == *queueF){
      *queueF = *queueI;
    }
    int valor = p->valor;
    free(p);
    return valor;
  }
  default:
    break;
  }
}
int priorityQueue (celula** priorityQueue, int comando, int x){
  switch (comando){
    //push 
    case 1: {
      celula *nova = malloc(sizeof(celula));
      nova->valor = x;
      celula *atual = *priorityQueue;
      while (atual->seg != NULL && atual->seg->valor > x) {
        atual = atual->seg;
      }
      nova->seg = atual->seg;
      atual->seg = nova;
      break;
    }
    //pop 
    case 2: {
      if ((*priorityQueue)->seg == NULL) return -1;
      celula *primeiro = (*priorityQueue)->seg;
      (*priorityQueue)->seg = primeiro->seg;
      int valor = primeiro->valor;
      free(primeiro);
      return valor;
    }
    default:
      break;
  }
  return 0;
}
int stack(celula** stack, int comando, int x){
  switch (comando){
    //push
    case 1: {
      celula *nova = malloc(sizeof(celula));
      nova->valor = x;
      nova->seg = (*stack)->seg;
      (*stack)->seg = nova;
      break;
    }
    //pop 
    case 2: {
      if ((*stack)->seg == NULL) return -1;
      celula *topo = (*stack)->seg;
      (*stack)->seg = topo->seg;
      int valor = topo->valor;
      free(topo);
      return valor;
    }
    default:
      break;
  }
  return 0;
}