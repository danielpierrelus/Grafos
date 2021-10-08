#include <stdio.h>
#define INT_MAX 30

void Tabela(int tabela[8][4], int i) {
  
    printf("\n-------Estado atual-------\n");
    printf("vert|vis    |valor  |anterior\n");
    for (int linha = 0; linha < 8; linha++){
        if (tabela[linha][1] == 0 && tabela[linha][2] == INT_MAX)
            printf("%d\t|Falso\t|∞\t    |%d", tabela[linha][0], tabela[linha][3]);
        else if (tabela[linha][1] == 0 && tabela[linha][2] != INT_MAX)
            printf("%d\t|Falso\t|%d\t    |%d", tabela[linha][0], tabela[linha][2], tabela[linha][3]);

        if (tabela[linha][1] == 1 && tabela[linha][2] == INT_MAX)
            printf("%d\t|Verda\t|∞\t     |%d", tabela[linha][0], tabela[linha][3]);
        else if (tabela[linha][1] == 1 && tabela[linha][2] != INT_MAX)
            printf("%d\t|Verda\t|%d\t    |%d", tabela[linha][0], tabela[linha][2], tabela[linha][3]);
                
        if ((linha == i) && (i > -1) && (i < 8))
            printf("← Visitando este vertice");
        printf("\n");
    }   
}

void printResultado (int tabela[8][4]) {
    printf("\nResultado\n");
    int soma = 0;
    for (int i = 0; i < 8; i++){
        printf("(%d,%d,), ", tabela[i][0], tabela[i][3]);
        soma += tabela[i][2];

    }
    printf("\nSoma: %d\n", soma);
}

void grafos (int mat[8][8], int tabela[8][4], int origem) {
    int i = origem;
  
    tabela[i][2] = 0;
    while (i < 8){ 
        int menorCusto = INT_MAX;
        printf("\nVisitando vértice %d", i);
        tabela[i][1] = 1;
        for (int j = 0; j < 8; j++) {
            
            if (mat[i][j] != 0 && tabela[j][2] > mat[i][j] && tabela[j][1] == 0) {
                tabela[j][2] = mat[i][j];
                tabela[j][3] = i;
                
            }
        }

        Tabela(tabela, i);

        int count = 0;
        for (int j = 0; j < 8; j++) {
            if (tabela[j][1] != 0)
                count++;
            if (tabela[j][1] == 0){
                j = 8;
            }
            if (count >= 7) {
                i = 8;
            }
        }

        for (int j = 0; j < 8; j++) {
          
            if (tabela[j][2] < menorCusto && tabela[j][1] == 0) {
                menorCusto = tabela[j][2];
                i = tabela[j][0];
               
            }
        }
    }
    printResultado(tabela);
}

int main() {
    int matAdja[8][8] = {{2, 6, 0, 2, 0, 1, 6, 3},
                        {7, 0, 2, 0, 5, 3, 6, 4},
                        
                        {6, 0, 2, 1, 5, 6, 1, 4},
                        
                        {5, 7, 8, 0, 3, 3, 0, 6},
                        
                        {6, 0, 5, 0, 2, 0, 6, 7},
                        
                        {7, 3, 6, 3, 0, 0, 2, 0},
                         
                        {2, 6, 1, 0, 1, 2, 0, 0},
                        
                        {3, 0, 0, 5, 7, 6, 0, 6}
    };

     int tabela[8][4];
    for (int i = 0; i < 8; i++){
        tabela[i][0] = i;
        tabela[i][1] = 0;
        tabela[i][2] = INT_MAX;
        tabela[i][3] = -1;
    }