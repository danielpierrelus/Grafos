#include <stdio.h>
//Coloração em Grafos
int maiorGrauNColorido (int tabela[7][3]);
void medeGrau (int mat[7][7], int tabela[7][3]);
void printTabela (int tabela[7][3]);

void coloreGrafo (int mat[7][7], int tabela[7][3]) {

    medeGrau(mat, tabela);
    for (int i; i < 7; i++){
        i = maiorGrauNColorido(tabela);
        tabela[i][1] = 1;
        for (int j = 0; j < 7; j++){
            if (mat[i][j] != 0) {
                if (tabela[j][1] == tabela[i][1]){
                    tabela[i][1]++;
                    j = 0;
                }
            }
        }
    }
    printTabela(tabela);
}

void printTabela (int tabela[7][3]) {
    int num[4] = {0,0,0,0};
    int contagem = 0;
    printf("Reultado:\n");
    printf("vert|  cor\n");
    for (int i = 0; i < 7; i++){
        if (tabela[i][1] == 1){
            printf("%d\t|\t🔴", tabela[i][0]);
            if (num[0] == 0){
                contagem++;
                num[0] = 1;
            }
        }
        
        if (tabela[i][1] == 2) {
            printf("%d\t|\t⚫", tabela[i][0]);
            if (num[1] == 0){
                contagem++;
                num[1] = 1;
            }
        }
        
        if (tabela[i][1] == 3) {
            printf("%d\t|\t🔵", tabela[i][0]);
            if (num[2] == 0){
                contagem++;
                num[2] = 1;
            }
        }

        if (tabela[i][1] == 4) {
            printf("%d\t|\t🟡", tabela[i][0]);
            if (num[3] == 0){
                contagem++;
                num[3] = 1;
            }
        }