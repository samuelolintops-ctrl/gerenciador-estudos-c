# gerenciador-estudos-c
Projeto de manipulação de arquivos em C para fixar aprendizado da faculdade.

Projeto desenvolvido para a disciplina de Linguagem de Programação II. 
O sistema permite registrar matérias, assuntos e o tempo dedicado a cada estudo, salvando tudo em arquivos de texto.

## Funcionalidades
- Cadastro de novos registros de estudo (Append).
- Leitura e exibição de relatório formatado.
- Interface limpa via terminal com suporte a cores ANSI.

## Compilar e Rodar
No Linux Mint, use o GCC:
```bash
gcc main.c prog_estudo.c util.c -o programa
./programa
