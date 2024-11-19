#include <stdio.h>
#include <stdlib.h>
#include "paciente/paciente.h"
#include "medico/medico.h"
#include "procedimento/procedimento.h"
#include "agendamento/agendamento.h"
#include "informacoes/informacoes.h"
#include "relatorio/relatorio.h"
#include "validacoes/validacoes.h"

void tela_menu_principal(void);

int main(void) {  
  int opcao;
  do{
    tela_menu_principal();
    scanf("%d", &opcao);
    getchar();
    switch (opcao) {
      case 1:
        modulo_paciente();
        break;
      case 2:
        tela_medico();  
        break;
      case 3:
        tela_procedimentos();
        break;
      case 4:
        tela_agendamento();
        break;
      case 5:
        tela_relatorio();
        break;
      case 6:
        tela_informacoes();
        break;
      case 7:
        tela_sobre();
        break;
      case 0:
      break;
      default:
      printf("Valor invalido");
      break;
    }
  }while(opcao != 0);
  return 0;
}

void tela_menu_principal(void) { 
  //system("clear||cls");
  printf("\n");
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║         ------ Sistema de Agendamento para Clínicas Médicas ------          ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                                                                             ║\n");
  printf("║                         🩺 1. Módulo Paciente                               ║\n");
  printf("║                         🏥 2. Módulo Médico                                 ║\n");
  printf("║                         📋 3. Módulo Procedimento                           ║\n");
  printf("║                         📅 4. Módulo Agendamento                            ║\n");
  printf("║                         📈 5. Módulo Relatórios                             ║\n");
  printf("║                         🔍 6. Módulo Informações                            ║\n");
  printf("║                         📖 7. Módulo Sobre                                  ║\n");
  printf("║                                                                             ║\n");
  printf("║                         ❌ 0. Sair                                          ║\n");
  printf("║                                                                             ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
  printf("║  ↪Escolha a opção desejada: "); 
}

