#include <stdio.h>
#include <stdlib.h>
#include "medico.h"
#include "../paciente/controller.h"
#include "../validacoes/validacoes.h"
#include "../agendamento/agendamento.h"

//MEDICOS
void tela_medico(void) {
  int opcao;
  do{
    system("clear||cls");
    printf("\n");
    printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                          ------ MÉDICOS ------                              ║\n");
    printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                                                                             ║\n");
    printf("║                           1. Cadastrar Médico                               ║\n");
    printf("║                           2. Pesquisar Médico                               ║\n");
    printf("║                           3. Atualizar Médico                               ║\n");
    printf("║                           4. Remover Médico                                 ║\n");
    printf("║                                                                             ║\n");
    printf("║                           0. Cancelar e sair                                ║\n");
    printf("║                                                                             ║\n");
    printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║  ↪Escolha a opção desejada: ");
    scanf("%d", &opcao);
    getchar();
    switch (opcao) {
      case 1:
        tela_cadastrar_medico();
        break;
      case 2:
        tela_ver_medico();
        break;
      case 3:
        tela_atualizar_medico();
        break;
      case 4:
        tela_deletar_medico();
        break;
      case 0:
        break;
      default:
      printf("Valor invalido");
      break;
      
    }
  }while(opcao != 0);
}


void tela_cadastrar_medico() {
  system("clear||cls");
  printf("\n");
  char CRM[13];
  char nome[51];
  char especializacao[31];

  solicitar_nome(nome);
  solicitar_CRM(CRM);
  solicitar_especializacao(especializacao);
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                           CADASTRAR MÉDICO                                  ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                                                                             ║\n");
  printf("║    CRM do médico: %-58s║\n", CRM);
  printf("║    Nome: %-67s║\n", nome);
  printf("║    Especialização: %-58s║\n", especializacao);
  printf("║                                                                             ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
  printf("\n");
  printf("Pressione a tecla <ENTER> para continuar...\n");
  getchar();
}
void tela_atualizar_medico() {
  system("clear||cls");
  printf("\n");
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                           ATUALIZAR MÉDICO                                  ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                                                                             ║\n");
  printf("║    Informe o CRE do médico que deseja atualizar:                            ║\n");
  printf("║                                                                             ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
  printf("\n");
  printf("Pressione a tecla <ENTER> para continuar...\n");
  getchar();
}
void tela_deletar_medico() {
  system("clear||cls");
  printf("\n");
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                             DELETAR MÉDICO                                  ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                                                                             ║\n");
  printf("║    Informe o CRE do médico que deseja deletar:                              ║\n");
  printf("║                                                                             ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");

  printf("\n");
  printf("Pressione a tecla <ENTER> para continuar...\n");
  getchar();
}
void tela_ver_medico() {
  system("clear||cls");
  printf("\n");
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                               VER MÉDICO                                    ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                                                                             ║\n");
  printf("║    Informe o CRE do médico que deseja ver informações:                      ║\n");
  printf("║                                                                             ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
  printf("\n");
  printf("Pressione a tecla <ENTER> para continuar...\n");
  getchar();
}

void solicitar_especializacao(char *especializacao) {
    int valido = 0;  
    do {
        printf("║ ↪ Especialização: ");
        scanf(" %[^\n]", especializacao); 
        getchar();  

        if (validarEspecializacao(especializacao)) { 
            valido = 1;
        } else {
            printf("==⊳ Entrada inválida, digite apenas letras e espaços                    ║\n");
            printf("==⊳ Pressione ENTER para tentar novamente                                    ═══╝\n");
            valido = 0;
        }
    } while (!valido);
}
