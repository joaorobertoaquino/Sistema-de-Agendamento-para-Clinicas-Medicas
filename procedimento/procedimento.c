#include <stdio.h>
#include <stdlib.h>
#include "procedimento.h"
#include "../validacoes/validacoes.h"
#include "../util/util.h"

void tela_procedimentos(void) {
  Procedimento* pro;
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
        pro = preencheProcedimento();
        gravaArquivo("procedimentos.dat", pro, sizeof(Procedimento));
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

Procedimento* preencheProcedimento(void) {
  Procedimento* pro;
  pro = (Procedimento*) malloc(sizeof(Procedimento));
  if (pro == NULL) {
    printf("Erro ao alocar memória para o procedimento.\n");
    exit(1);
  }
  system("clear||cls");
  printf("\n");
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                          CADASTRAR PROCEDIMENTO                             ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  const char* arquivoProcedimentos = "procedimentos.dat";
  pro->ID_procedimento = obterProximoID(arquivoProcedimentos, sizeof(Procedimento));
  solicitar_nome_procedimento(pro->nome);
  solicitar_tempo(pro->duracao);
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                          PROCEDIMENTO  CADASTRADO                           ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                                                                             ║\n");
  printf("║    ID:%d                                                                    ║\n",pro->ID_procedimento);
  printf("║    Nome:%s                                                                  ║\n",pro->nome);
  printf("║    Duração:%s                                                               ║\n",pro->duracao);
  printf("║    CRM:                                                                     ║\n");
  printf("║                                                                             ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
  printf("\n");
  printf("Pressione a tecla <ENTER> para continuar...\n");
  getchar();
  free(pro);
  return pro;
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


void solicitar_nome_procedimento(char *nome) {
    int valido = 0; // Inicializando como não válido
    do {
        printf("║ ↪Nome do Procedimento:");
        scanf(" %[^\n]", nome);
        getchar();
        if (validarNome_procedimento(nome)==1) { 
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