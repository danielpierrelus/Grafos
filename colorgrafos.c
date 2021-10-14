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