#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct no {
    char valor;
    struct no *esq, *dir;
} No;

No* inserir(No* raiz, char valor);
No* buscar(No* raiz, char valor);
void infixa(No* raiz);
void prefixa(No* raiz);
void posfixa(No* raiz);
void infixa_aux(No* raiz, int* primeiro);
void prefixa_aux(No* raiz, int* primeiro);
void posfixa_aux(No* raiz, int* primeiro);

int main() {
    char operacao[10];
    char valor;
    No* raiz = NULL;
    
    while (scanf("%s", operacao) != EOF) {
        if (strcmp(operacao, "I") == 0) {
            scanf(" %c", &valor);
            raiz = inserir(raiz, valor);
        }
        else if (strcmp(operacao, "P") == 0) {
            scanf(" %c", &valor);
            if (buscar(raiz, valor)) {
                printf("%c existe\n", valor);
            } else {
                printf("%c nao existe\n", valor);
            }
        }
        else if (strcmp(operacao, "INFIXA") == 0) {
            int primeiro = 1;
            infixa_aux(raiz, &primeiro);
            printf("\n");
        }
        else if (strcmp(operacao, "PREFIXA") == 0) {
            int primeiro = 1;
            prefixa_aux(raiz, &primeiro);
            printf("\n");
        }
        else if (strcmp(operacao, "POSFIXA") == 0) {
            int primeiro = 1;
            posfixa_aux(raiz, &primeiro);
            printf("\n");
        }
    }
    
    return 0;
}

No* inserir(No* raiz, char valor) {
    if (raiz == NULL) {
        No* novo = malloc(sizeof(No));
        novo->valor = valor;
        novo->esq = novo->dir = NULL;
        return novo;
    }
    
    if (valor < raiz->valor) {
        raiz->esq = inserir(raiz->esq, valor);
    }
    else if (valor > raiz->valor) {
        raiz->dir = inserir(raiz->dir, valor);
    }
    
    return raiz;
}

No* buscar(No* raiz, char valor) {
    if (raiz == NULL || raiz->valor == valor) {
        return raiz;
    }
    
    if (valor < raiz->valor) {
        return buscar(raiz->esq, valor);
    }
    
    return buscar(raiz->dir, valor);
}

void infixa(No* raiz) {
    if (raiz != NULL) {
        infixa(raiz->esq);
        printf("%c", raiz->valor);
        infixa(raiz->dir);
    }
}

void prefixa(No* raiz) {
    if (raiz != NULL) {
        printf("%c", raiz->valor);
        prefixa(raiz->esq);
        prefixa(raiz->dir);
    }
}

void posfixa(No* raiz) {
    if (raiz != NULL) {
        posfixa(raiz->esq);
        posfixa(raiz->dir);
        printf("%c", raiz->valor);
    }
}

void infixa_aux(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        infixa_aux(raiz->esq, primeiro);
        if (*primeiro) {
            printf("%c", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %c", raiz->valor);
        }
        infixa_aux(raiz->dir, primeiro);
    }
}

void prefixa_aux(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        if (*primeiro) {
            printf("%c", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %c", raiz->valor);
        }
        prefixa_aux(raiz->esq, primeiro);
        prefixa_aux(raiz->dir, primeiro);
    }
}

void posfixa_aux(No* raiz, int* primeiro) {
    if (raiz != NULL) {
        posfixa_aux(raiz->esq, primeiro);
        posfixa_aux(raiz->dir, primeiro);
        if (*primeiro) {
            printf("%c", raiz->valor);
            *primeiro = 0;
        } else {
            printf(" %c", raiz->valor);
        }
    }
}
