#include <stdio.h>

struct celula{
  int conteudo;
  struct celula *seg ; 
};
typedef struct celula cel;
void menu();
void insere (int y, cel *p);
void remove (cel *p);
void imprima (cel *lst);

int main () {
  int op;
  do {
    menu();
    scanf("%d", &op);
  } while (op != 0)
 
  

}
void menu () {
  printf("LISTA:\n");
  printf("1- Ver lista\n");
  printf("2- Add item\n");
  printf("3- Remover item\n");  
  printf("0- Sair\n");  
}
void insere (int y, cel *p){
  cel *nova;
  nova = malloc (sizeof (cel));
  nova->conteudo = y;
  nova->seg = p->seg;
  p->seg = nova;
}
void remove (cel *p){
  cel *lixo;
  lixo = p->seg;
  p->seg = lixo->seg;
  free (lixo);
}
void imprima (cel *lst){
  cel *p;
  for(p = lst->seg; p != NULL; p = p->seg){
    printf("%d\n", p->conteudo);
  }
}