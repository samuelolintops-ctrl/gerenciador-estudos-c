#include <stdio.h>
#include <stdlib.h>
#include "util.h"

void limpa_buffer(){
    int c;
    while((c = getchar()) != '\n' && c != EOF);
}

void limpa_tela(){
    #ifdef _WIN32
        system("cls"); // Windows
    #else
        system("clear"); // Linux/Unix/macOS
    #endif
}

void espera_enter(){
    printf("\nAperte \033[33mENTER\033[m para continuar...");
    limpa_buffer();
    getchar();
}

int mostra_menu(char **lista_opc, int tam){
    /*
    Função que exibe na tela a lista num formato sequencial
    param lista_opc: lista com as opcoes do menu
    param tam: quantidade de elementos na lista
    return: retorna a opcao que o usuario deseja operar
    */
    int opc;
    while(1){
        limpa_tela();
        for(int i = 0; i < tam; i++){
            printf("%d. %s\n", i + 1, lista_opc[i]);
        }
        printf("Digite sua opcao: ");
        scanf("%d", &opc);
        if(opc > 0 && opc <= tam) break;
        printf("\n\033[31mOpcao invalida, digite novamente!\033[m\n");
        espera_enter();
    }
    return opc;
}