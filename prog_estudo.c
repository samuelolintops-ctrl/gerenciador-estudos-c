#include <stdio.h>
#include <stdlib.h>
#include "util.h"
#include "prog_estudo.h"

int verifica_arquivo(FILE *pont_arq){
    /*
    Função de verificação de sucesso ou não na abertura do arquivo
    param pont_arq: ponteiro do arquivo a se verificar
    return: 1 em caso de falha ou 0 em caso de sucesso
    */
    if(pont_arq == NULL){
        printf("\n\033[31mERRO: Falha ao abrir arquivo.\033[m\n");
        return 1;
    }
    printf("\033[32mConexão com o arquivo estabelecida com sucesso!\033[m");
    return 0;
}

void relat_estudo(){
    limpa_tela();
    printf("\033[1mOPERANDO MODULO DE RELATORIO DE ESTUDOS\033[m\n");
    char materia[20];
    char assunto[20];
    int minutos_estudo;
    char nome_arquivo[] = "projeto.txt";
    FILE *arquivo;
    arquivo = fopen(nome_arquivo, "r");
    int verifica = verifica_arquivo(arquivo);
    if(verifica == 1){
        printf("\nArquivo inexistente, adicione um conteudo e tente novamente.\n");
        espera_enter();
        return;
    }
    while(fscanf(arquivo, "%s %s %d", materia, assunto, &minutos_estudo) == 3){
        printf("\nMateria: %s\nAssunto: %s\nMinutos estudados: %d\n", materia, assunto, minutos_estudo);
        printf("-------------------------");
    }
    fclose(arquivo);
    espera_enter();
}

void add_estudo(){
    limpa_tela();
    printf("\033[1mOPERANDO MODULO DE ADICIONAR ESTUDO\033[m\n");
    char materia[20];
    char assunto[20];
    int minutos_estudo;
    char nome_arquivo[] = "projeto.txt";
    printf("\nMateria estudada: ");
    scanf("%s", materia);
    limpa_buffer();
    printf("\nAssunto estudado: ");
    scanf("%s", assunto);
    limpa_buffer();
    printf("\nMinutos estudados: ");
    scanf("%d", &minutos_estudo);
    limpa_buffer();

    FILE *arquivo;
    arquivo = fopen(nome_arquivo, "a");
    int verifica = verifica_arquivo(arquivo);
    if(verifica == 1) return;
    fprintf(arquivo, "%s %s %d\n", materia, assunto, minutos_estudo);
    fclose(arquivo);
    printf("\n\033[32mEstudo gravado!\033[m");
    espera_enter();
}
