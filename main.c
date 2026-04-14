#include <stdio.h>
#include <stdlib.h>
#include "prog_estudo.h"
#include "util.h"

int main(){    
    char *opcoes_menu[] = {
        "Mostrar relatorio de estudos",
        "Adicionar estudo",
        "Sair",
    };
    int qtd_opcoes = sizeof(opcoes_menu) / sizeof(opcoes_menu[0]);
    int opcao;
    while(1){
        opcao = mostra_menu(opcoes_menu, qtd_opcoes);
        switch(opcao){
            case 1:
            relat_estudo();
            break;
            case 2:
            add_estudo();
            break;
            case 3:
            printf("Encerrando programa. Até a próxima!\n");
            return 0;
        }
    }
    printf("Sua escolha %d\n", opcao);
    return 0;
}
