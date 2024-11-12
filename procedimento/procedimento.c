#include <stdio.h>
#include <stdlib.h>
#include "procedimento.h"
#include "../validacoes/validacoes.h"

void tela_procedimentos(void) {
  int opcao;

  do {
    system("clear||cls");
    printf("\n");
    printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                        ------ PROCEDIMENTOS ------                          ║\n");
    printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                                                                             ║\n");
    printf("║                         1. Cadastrar Procedimento                           ║\n");
    printf("║                         2. Pesquisar Procedimento                           ║\n");
    printf("║                         3. Atualizar Procedimento                           ║\n");
    printf("║                         4. Remover Procedimento                             ║\n");
    printf("║                                                                             ║\n");
    printf("║                         0. Cancelar e sair                                  ║\n");
    printf("║                                                                             ║\n");
    printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║  ↪Escolha a opção desejada: ");
    scanf("%d", &opcao);
    getchar();
    switch (opcao) {
      case 1:
        tela_cadastrar_procedimento();
        break;
      case 2:
        tela_ver_procedimento();
        break;
      case 3:
        tela_atualizar_procedimento();
        break;
      case 4:
        tela_deletar_procedimento();
        break;
      default:
        printf("Valor invalido");
        break;
    }
  } while(opcao != 0);

}

void tela_cadastrar_procedimento() {
  int ID_procedimento;
  char nome[52];
  char duracao[6];
  solicitar_ID(ID_procedimento);
  solicitar_nome(nome);
  solicitar_tempo(duracao);

  system("clear||cls");
  printf("\n");
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                         CADASTRAR PROCEDIMENTO                              ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                                                                             ║\n");
  printf("║    ID Procedimento:                                                         ║\n");
  printf("║    Nome:                                                                    ║\n");
  printf("║    Duração:                                                                 ║\n");
  printf("║    CRM:                                                                     ║\n");
  printf("║                                                                             ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
  printf("\n");
  printf("Pressione a tecla <ENTER> para continuar...\n");
  getchar();
}
void tela_atualizar_procedimento() {
  system("clear||cls");
  printf("\n");
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                         ATUALIZAR PROCEDIMENTO                              ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                                                                             ║\n");
  printf("║    Informe o ID do procedimento que deseja atualizar:                       ║\n");
  printf("║                                                                             ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
  printf("\n");
  printf("Pressione a tecla <ENTER> para continuar...\n");
  getchar();
}
void tela_deletar_procedimento() {
  system("clear||cls");
  printf("\n");
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                            DELETAR PROCEDIMENTO                             ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                                                                             ║\n");
  printf("║    Informe o ID do procedimento que deseja deletar:                         ║\n");
  printf("║                                                                             ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
  printf("\n");
  printf("Pressione a tecla <ENTER> para continuar...\n");
  getchar();
}
void tela_ver_procedimento() {
  system("clear||cls");
  printf("\n");
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                              VER PROCEDIMENTO                               ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                                                                             ║\n");
  printf("║    Informe o ID do procedimento que deseja ver informações:                 ║\n");
  printf("║                                                                             ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
  printf("\n");
  printf("Pressione a tecla <ENTER> para continuar...\n");
  getchar();
}
void solicitar_ID(int *id){
  int valido = 0; // Inicializando como não válido
  do {
      printf("║ ↪ID do procedimento:");
      scanf(" %[^\n]", id); 
      getchar();
      if (verificar_(id)==1) { 
          valido = 1; // Marca como válido
      } else {
          printf("==⊳ Entrada inválida, digite um número maior que 0                            ║\n");
          printf("==⊳ DIGITE ENTER para continuar                                            ═══╝\n");
          valido = 0; // Marca como não válido
          while (getchar() != '\n'); // Limpar o buffer
      }
  } while (!valido); // até ser valido

}
void solicitar_nome(char *nome) {
    int valido = 0; // Inicializando como não válido
    do {
        printf("║ ↪Nome Completo:");
        scanf(" %[^\n]", nome);
        getchar();
        if (validarNome(nome)==1) { 
            valido = 1; // Marca como válido
        } else {
            printf("==⊳ Entrada inválida, digite apenas letras e espaços                          ║\n");
            printf("==⊳ DIGITE ENTER para continuar                                            ═══╝\n");
            valido = 0; // Marca como não válido
            while (getchar() != '\n'); // Limpar o buffer
        }
    } while (!valido); // até ser valido
}
void solicitar_tempo(char *duracao) {
    int valido = 0; // Inicializando como não válido
    do {
        printf("║ ↪Digite Duração em HH:MM:");
        scanf(" %[^\n]", duracao);
        getchar();
        if (validar_tempo(duracao)==1) { 
            valido = 1; // Marca como válido
        } else {
            printf("==⊳ Entrada inválida, digite a duração no formato HH:MM                       ║\n");
            printf("==⊳ DIGITE ENTER para continuar                                            ═══╝\n");
            valido = 0; // Marca como não válido
            while (getchar() != '\n'); // Limpar o buffer
        }
    } while (!valido); // até ser valido
}