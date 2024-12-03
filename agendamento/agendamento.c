#include <stdio.h>
#include <stdlib.h>
#include "agendamento.h"
#include "../paciente/paciente.h"
#include "../validacoes/validacoes.h"

typedef struct agendamentos Agendamentos;
Agendamentos agendamentos1;

void tela_agendamento(void) {
  int opcao;
  do {
    system("clear||cls");
    printf("\n");
    printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                         ------ AGENDAMENTO ------                           ║\n");
    printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                                                                             ║\n");
    printf("║                          1. Cadastrar Agendamento                           ║\n");
    printf("║                          2. Pesquisar Agendamento                           ║\n");
    printf("║                          3. Atualizar Agendamento                           ║\n");
    printf("║                          4. Remover Agendamento                             ║\n");
    printf("║                                                                             ║\n");
    printf("║                          0. Cancelar e sair                                 ║\n");
    printf("║                                                                             ║\n");
    printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║  ↪Escolha a opção desejada: ");
    
    scanf("%d", &opcao);
    getchar();
    switch (opcao) {
      case 1:
        tela_cadastrar_agendamento();
        break;
      case 2:
        tela_ver_agendamento();
        break;
      case 3:
        tela_atualizar_agendamento();
        break;
      case 4:
        tela_deletar_agendamento();
        break;
      default:
        printf("Valor invalido");
        break;
    }
  } while(opcao != 0);
}


void tela_cadastrar_agendamento() {
<<<<<<< HEAD

  char CPF[13];
  char CRM[10];

  system("clear||cls");
  printf("\n");

  solicitar_data(agendamento1.data);
  solicitar_hora(agendamento1.hora);
  //solicitar_CPF(CPF); //"../paciente/paciente.h"
  //solicitar_CRM(CRM); //"../medico/medico.h"
  
=======
  system("clear||cls");
  printf("\n");
  solicitar_data(agendamentos1.data);
  solicitar_hora(agendamentos1.hora);
  solicitar_CPF(agendamentos1.CPF); //"../paciente/paciente.h"
  solicitar_CRM(agendamentos1.CRM);
>>>>>>> ef53351 (feat: criando o struct para o módulo "agendamentos".)
  printf("\n");
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                         CADASTRAR AGENDAMENTO                               ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                                                                             ║\n");
<<<<<<< HEAD
  printf("║    Data: %-67s║\n", agendamento1.data);
  printf("║    Hora: %-67s║\n", agendamento1.hora);
=======
  printf("║    Data: %-67s║\n", agendamentos1.data);
  printf("║    Hora: %-67s║\n", agendamentos1.hora);
>>>>>>> ef53351 (feat: criando o struct para o módulo "agendamentos".)
  printf("║    ID do agendamento: (sem informação no momento)                           ║\n");
  printf("║    CPF paciente: %-59s║\n", agendamentos1.CPF);
  printf("║    CRE do médico: %-58s║\n", agendamentos1.CRM);
  printf("║                                                                             ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
  printf("AGENDAMENTO cadastrado com sucesso.\n");
  printf("Pressione a tecla <ENTER> para continuar...\n");
  getchar();
}

void tela_atualizar_agendamento() {
  system("clear||cls");
  printf("\n");
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                         ATUALIZAR AGENDAMENTO                               ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                                                                             ║\n");
  printf("║     Informe o ID do agendamento                                             ║\n");
  printf("║                                                                             ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
  printf("\n");
  printf("Pressione a tecla <ENTER> para continuar...\n");
  getchar();
}

void tela_deletar_agendamento() {
  system("clear||cls");
  printf("\n");
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                            DELETAR AGENDAMENTO                              ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                                                                             ║\n");
  printf("║    Informe o ID do agendamento:                                             ║\n");
  printf("║                                                                             ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
  printf("\n");
  printf("Pressione a tecla <ENTER> para continuar...\n");
  getchar();
}

void tela_ver_agendamento() {
  system("clear||cls");
  printf("\n");
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                              VER AGENDAMENTO                                ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                                                                             ║\n");
  printf("║    Informe o ID do agendamento:                                             ║\n");
  printf("║                                                                             ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
  printf("\n");
  printf("Pressione a tecla <ENTER> para continuar...\n");
  getchar();
}

void solicitar_data(char *data_cadastro) {
    int valido = 0; // Inicializando como não válido
    do {
        printf("║ ↪Data de Cadastro da Consulta: ");
        scanf(" %[^\n]", data_cadastro); 
        getchar();

        if (validar_data_cadastro(data_cadastro) == 1) { 
            valido = 1; // Marca como válido
        } else {
            printf("==⊳ Entrada inválida, digite uma data válida (DD/MM/AAAA)                    ║\n");
            printf("==⊳ Pressione ENTER para tentar novamente                                    ═══╝\n");
            valido = 0; // Marca como não válido
            while (getchar() != '\n'); // Limpar o buffer
        }
    } while (!valido); // Repete até que seja válido
}

void solicitar_hora(char *hora) {
    int valido = 0; // Inicializando como não válido
    do {
        printf("║ ↪Hora (HH:MM): ");
        scanf(" %[^\n]", hora);
        getchar(); // Limpar o buffer

        // Verifica se a hora é válida
        if (validar_hora(hora)) { 
            valido = 1; // Marca como válido
        } else {
            printf("==⊳ Entrada inválida, digite uma hora válida (HH:MM)                    ║\n");
            printf("==⊳ Pressione ENTER para tentar novamente                                    ═══╝\n");
            valido = 0; // Marca como não válido
        }
    } while (!valido); // até ser válido
}