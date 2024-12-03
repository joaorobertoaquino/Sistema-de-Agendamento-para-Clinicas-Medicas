#include <stdio.h>
#include <stdlib.h>
#include "medico.h"
#include "../paciente/paciente.h"
#include "../validacoes/validacoes.h"
#include "../agendamento/agendamento.h"
typedef struct medico Medico;
Medico medico1;

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
  solicitar_nome(medico1.nome);
  solicitar_CRM(medico1.CRM);
  solicitar_especializacao(medico1.especializacao);
  salvar_medico(&medico1);
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                           CADASTRAR MÉDICO                                  ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                                                                             ║\n");
  printf("║    CRM do médico: %-58s║\n", medico1.CRM);
  printf("║    Nome: %-67s║\n", medico1.nome);
  printf("║    Especialização: %-58s║\n", medico1.especializacao);
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
  char CRM_test[13];
  system("clear||cls");
  printf("Digite o CRM que seja buscar:\n");
  scanf("%s",CRM_test);
  getchar();
  buscar_medico(CRM_test,&medico1);
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
void solicitar_CRM(char *CRM) {
    int valido = 0; // Inicializando como não válido
    do {
        printf("║ ↪ CRM do médico (formato 0000000-UF): ");
        scanf(" %[^\n]", CRM);  // Lê até a nova linha
        getchar(); // Limpa o buffer

        // Verifica se o CRM é válido
        if (validar_CRM(CRM)) { 
            valido = 1; // Marca como válido
        } else {
            printf("==⊳ Entrada inválida, digite no formato 0000000-UF                          ║\n");
            printf("==⊳ Pressione ENTER para tentar novamente                                    ═══╝\n");
            valido = 0; // Marca como não válido
        }
    } while (!valido); // Continua até ser válido
}


void salvar_medico(Medico *medico1) {
    FILE *fp = fopen("medico/medico.dat", "ab"); // Abrir para adicionar binário
    if (fp == NULL) {
        printf("ERro na Abertura");
        exit(1);
    }
    fwrite(medico1, sizeof(Medico), 1, fp); // Grava o conteúdo do struct
    fclose(fp);
    //free(medico1);
}
void buscar_medico(const char *crm_busca, Medico *medica1) {
    FILE *fp = fopen("medico/medico.dat", "rb"); // Abrir para leitura binária
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    Medico medico;
    int encontrado = 0;

    // Ler cada registro do arquivo
    while (fread(&medico, sizeof(Medico), 1, fp)) {
        // Verificar se o CRM coincide
        if (strcmp(medico.CRM, crm_busca) == 0) {
            printf("Médico encontrado:\n");
            printf("CRM: %s\n", medico.CRM);
            printf("Nome: %s\n", medico.nome);
            printf("Especialização: %s\n", medico.especializacao);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Médico com CRM %s não encontrado.\n", crm_busca);
    }

    fclose(fp);
}