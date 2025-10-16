#include <stdio.h>
#include <stdlib.h>

int verificaLinhas(int **sudoku);
int verificaColunas(int **sudoku);
int verificaBlocos(int **sudoku);

int main() {
    int n, i;
    scanf("%d", &n);
    
    for (i = 0; i < n; i++) {
        int **sudoku = (int **)malloc(9 * sizeof(int *));
        for (int j = 0; j < 9; j++) {
            sudoku[j] = (int *)malloc(9 * sizeof(int));
        }

        for (int j = 0; j < 9; j++) {
            for (int k = 0; k < 9; k++) {
                scanf("%d", &sudoku[j][k]);
            }
        }
        
        printf("Instancia %d\n", i + 1);
        if (verificaLinhas(sudoku) && verificaColunas(sudoku) && verificaBlocos(sudoku)) {
            printf("SIM\n");
        } else {
            printf("NAO\n");
        }
        printf("\n");
        
        for (int j = 0; j < 9; j++) {
            free(sudoku[j]);
        }
        free(sudoku);
    }
    
    return 0;
}

int verificaLinhas(int **sudoku) {
    for (int i = 0; i < 9; i++){
        int gabarito[9] = {0};
        for (int j = 0; j < 9; j++){
            int elemento = sudoku[i][j];
            if (elemento < 1 || elemento > 9 || gabarito[elemento - 1] != 0){
                return 0;
            }
            gabarito[elemento - 1] = 1;
        }
    }
    
    return 1;
}

int verificaColunas(int **sudoku) {
    for (int i = 0; i < 9; i++){
        int gabarito[9] = {0};
        for (int j = 0; j < 9; j++){
            int elemento = sudoku[j][i];
            if (elemento < 1 || elemento > 9 || gabarito[elemento - 1] != 0){
                return 0;
            }
            gabarito[elemento - 1] = 1;
        }
    }
    
    return 1;
}

int verificaBlocos(int **sudoku){
    for(int blocoLinha = 0; blocoLinha < 3; blocoLinha++){
        for(int blocoColuna = 0; blocoColuna < 3; blocoColuna++){
            int gabarito[9] = {0};
            for (int i = 0; i < 3; i++){
                for (int j = 0; j < 3; j++){
                    int linha = blocoLinha * 3 + i;
                    int coluna = blocoColuna * 3 + j;
                    int elemento = sudoku[linha][coluna];
                    if (elemento < 1 || elemento > 9 || gabarito[elemento - 1] != 0){
                        return 0;
                    }
                    gabarito[elemento - 1] = 1;
                }
            }
        }
    }
    return 1;
}