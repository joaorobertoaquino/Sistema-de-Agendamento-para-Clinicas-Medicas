#include <stdio.h>
#include <stdlib.h>
#include "relatorio.h"


void tela_relatorio(void){
  int opcao;
  do{
    system("clear||cls");
    printf("\n");
    printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                            Relatório Geral                                  ║\n");
    printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                                                                             ║\n");
    printf("║                       1. Relatório Módulo Paciente                          ║\n");
    printf("║                       2. Relatório Módulo Médico                            ║\n");
    printf("║                       3. Relatório Módulo Procedimento                      ║\n");
    printf("║                       4. Relatório Módulo Agendamento                       ║\n");
    printf("║                                                                             ║\n");
    printf("║                       0. Sair                                               ║\n");
    printf("║                                                                             ║\n");
    printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║  ↪Escolha a opção desejada: ");
    scanf("%d",&opcao);
    getchar();
    switch (opcao)
    {
    case 1:
      tela_relatorio_paciente();
      break;
    case 2:
      tela_relatorio_medico();
      break;
    case 3:
      tela_relatorio_procedimento();
      break;
    case 4:
      tela_relatorio_agendamento();
      break;
    case 0:
      break;
    default:
      break;
    }
  }while(opcao != 0);
}
void tela_relatorio_medico() {
  system("clear||cls");
  printf("\n");
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                          RELATÓRIO MÉDICO                                   ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                                                                             ║\n");
  printf("║    CRE:                                                                     ║\n");
  printf("║    Nome:                                                                    ║\n");
  printf("║    Especialização:                                                          ║\n");
  printf("║                                                                             ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");

  printf("\n");
  printf("Pressione a tecla <ENTER> para continuar...\n");
  getchar();
}
void tela_relatorio_paciente() {
  system("clear||cls");
  printf("\n");
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                          RELATÓRIO PACIENTE                                 ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                                                                             ║\n");
  printf("║    Nome:                                                                    ║\n");
  printf("║    CPF:                                                                     ║\n");
  printf("║    Data de nascimento:                                                      ║\n");
  printf("║    Celular:                                                                 ║\n");
  printf("║    Email:                                                                   ║\n");
  printf("║    Endereço:                                                                ║\n");
  printf("║                                                                             ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
  printf("\n");
  printf("Pressione a tecla <ENTER> para continuar...\n");
  getchar();
}
void tela_relatorio_procedimento() {
  system("clear||cls");
  printf("\n");
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                         RELATÓRIO PROCEDIMENTO                              ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                                                                             ║\n");
  printf("║    ID Procedimento:                                                         ║\n");
  printf("║    Nome:                                                                    ║\n");
  printf("║    Duração:                                                                 ║\n");
  printf("║    CRE:                                                                     ║\n");
  printf("║                                                                             ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
  printf("\n");
  printf("Pressione a tecla <ENTER> para continuar...\n");
  getchar();
}
void tela_relatorio_agendamento() {
  system("clear||cls");
  printf("\n");
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                          RELATÓRIO AGENDAMENTO                              ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                                                                             ║\n");
  printf("║    Data:                                                                    ║\n");
  printf("║    Hora:                                                                    ║\n");
  printf("║    ID do agendamento:                                                       ║\n");
  printf("║    CPF paciente:                                                            ║\n");
  printf("║    CRE do médico:                                                           ║\n");
  printf("║                                                                             ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
  printf("\n");
  printf("Pressione a tecla <ENTER> para continuar...\n");
  getchar();
}
