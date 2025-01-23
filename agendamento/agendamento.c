#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "agendamento.h"
#include "../paciente/paciente.h"
#include "../medico/medico.h"
#include "../validacoes/validacoes.h"
#include "../procedimento/procedimento.h"


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
    system("clear||cls");
    printf("\n");
    printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                         CADASTRAR AGENDAMENTO                               ║\n");
    printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");

    Agendamentos agendamento;
    const char* arquivoAgendamentos = "agendamentos.dat";
    // Preenche agendamento
    agendamento.id = obterProximoIDAgendamento(arquivoAgendamentos);
    solicitar_data(agendamento.data);
    solicitar_hora(agendamento.hora);
    solicitar_CPF_existente(agendamento.CPF);
    solicitar_CRM_existente(agendamento.CRM);

    if (!verificar_CPF(agendamento.CPF)) {
        printf("Erro: CPF não encontrado no banco de dados de pacientes.\n");
        printf("Pressione ENTER para continuar...\n");
        getchar();
        return; 
    }

    if (!verificar_CRM(agendamento.CRM)) {
        printf("Erro: CRM não encontrado no banco de dados de médicos.\n");
        printf("Pressione ENTER para continuar...\n");
        getchar();
        return;  
    }

    int codigoProcedimento;
    printf("║ ↪ Informe o código do procedimento: ");
    scanf("%d", &codigoProcedimento);
    getchar();

    // Verifica se o código do procedimento existe
    if (!verificar_codigo_procedimento(codigoProcedimento)) {
        printf("Erro: Código do procedimento não encontrado no banco de dados.\n");
        printf("Pressione ENTER para continuar...\n");
        getchar();
        return;  
    }

    // Preenche o campo do procedimento com o código
    snprintf(agendamento.procedimento, sizeof(agendamento.procedimento), "%d", codigoProcedimento);

    // Salva o agendamento no arquivo
    salvar_agendamento(&agendamento);

    exibeAgendamento(&agendamento, codigoProcedimento);
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
            printf("==⊳ Pressione ENTER para tentar novamente                                    ║\n");
            valido = 0; // Marca como não válido
        }
    } while (!valido); // até ser válido
}

void solicitar_CRM_existente(char *crm) {
    int valido = 0;
    do {
        printf("║ ↪ CRM do médico (formato 0000000-UF): ");
        scanf(" %[^\n]", crm);  // Lê o CRM informado

        // Verifica se o CRM está cadastrado
        if (verificar_CRM(crm)) {
            valido = 1;  // CRM encontrado
        } else {
            printf("==⊳ O CRM informado não está cadastrado. Por favor, insira outro.            ║\n");
            printf("==⊳ Pressione ENTER para tentar novamente                                    ═══╝\n");
            valido = 0;  // CRM não encontrado, pede para tentar novamente
            while (getchar() != '\n');  // Limpa o buffer
        }
    } while (!valido);  // Repete até o CRM ser encontrado
}

int verificar_CRM(const char *crm) {
    FILE *fp = fopen("medico/medico.dat", "rb"); 
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de médicos.\n");
        exit(1);
    }

    Medico medico;
    int encontrado = 0;
    while (fread(&medico, sizeof(Medico), 1, fp)) {
        if (strcmp(medico.CRM, crm) == 0) {
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Médico com CRM %s não encontrado.\n", crm);
    }

    fclose(fp);
    return encontrado;
}


void solicitar_CPF_existente(char *cpf) {
    int valido = 0;
    do {
        printf("║ ↪ CPF do paciente (somente números, sem pontos e traços): ");
        scanf(" %[^\n]", cpf);  // Lê o CPF informado

        // Verifica se o CPF está cadastrado
        if (verificar_CPF(cpf)) {
            valido = 1;  // CPF encontrado
        } else {
            printf("==⊳ O CPF informado não está cadastrado.        ║\n");
            printf("==⊳ Pressione ENTER para tentar novamente                                    ║\n");
            valido = 0;  // CPF não encontrado, pede para tentar novamente
            while (getchar() != '\n');  // Limpa o buffer
        }
    } while (!valido);  // Repete até o CPF ser encontrado
}

int verificar_CPF(const char *cpf) {
    FILE *fp = fopen("paciente/paciente.dat", "rb"); 
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    Paciente paciente;
    int encontrado = 0;
    while (fread(&paciente, sizeof(Paciente), 1, fp)) {
        if (strcmp(paciente.CPF, cpf) == 0) {
            if (paciente.status == 'i') {
                printf("\nO paciente com CPF:%s está inativo.",paciente.CPF);
                encontrado = 1;
                break;
            }else{
                encontrado = 1;
                break;
            }
        }
    }
    if (!encontrado) {
        printf("Paciente com CPF %s não encontrado.\n", cpf);
    }
    fclose(fp);
    return encontrado;
}

int verificar_codigo_procedimento(int codigo) {
    FILE* fp = fopen("procedimentos.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de procedimentos.\n");
        return 0;
    }

    Procedimento procedimento;
    while (fread(&procedimento, sizeof(Procedimento), 1, fp) == 1) {
        if (procedimento.ID_procedimento == codigo && procedimento.status == 1) {
            fclose(fp);
            return 1; // Código encontrado
        }
    }

    fclose(fp);
    return 0; // Código não encontrado
}

void salvar_agendamento(Agendamentos *agendamentos) {
    FILE *fp = fopen("agendamentos.dat", "ab");  // Abrir o arquivo para adicionar (append)
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de agendamentos.\n");
        return;
    }
    
    // Grava o agendamento no arquivo
    fwrite(agendamentos, sizeof(Agendamentos), 1, fp);
    fclose(fp);
}

int obterProximoIDAgendamento(const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        return 1; // Arquivo não existe ainda, ID inicial é 1
    }
    Agendamentos agen;
    int ultimoID = 0;
    while (fread(&agen, sizeof(Agendamentos), 1, arquivo) == 1) {
        ultimoID = agen.id; // Obtém o ID do último registro
    }
    fclose(arquivo);
    return ultimoID + 1; // Próximo ID
}

void exibeAgendamento(Agendamentos* agen, int codigoProcedimento) {
    if (agen == NULL) {
      printf("\n= = = Agendamento Inexistente = = =\n");
    } else {
      printf("\n= = = Agendamento Cadastrado = = =\n");
      printf("║ ID: %d\n", agen->id);
      printf("║ Data: %s\n", agen->data);
      printf("║ Hora: %s\n", agen->hora);
      printf("║ CPF: %s\n", agen->CPF);
      printf("║ CRM: %s\n", agen->CRM);
      printf("║ Procedimento: %d\n", codigoProcedimento);
    }
    printf("Tecle <ENTER> para continuar...");
    getchar();
}
