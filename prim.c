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