#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "relatorio.h"
#include "../util/util.h"
#include "../paciente/paciente.h"
#include "../medico/medico.h"
#include "../agendamento/agendamento.h"
#include "../procedimento/procedimento.h"

typedef struct paciente Paciente;

void tela_relatorio(void){
  int opcao;
  do{
    system("clear||cls");
    printf("\n");
    printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                            Relatórios                                       ║\n");
    printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                                                                             ║\n");
    printf("║                       1. Agendamentos de hoje                               ║\n");
    printf("║                       2. Agendamentos por Data                              ║\n");
    printf("║                       3. Listar Pacientes por ordem alfabética              ║\n");
    printf("║                       4. Listar Médicos por ordem alfabética                ║\n");
    printf("║                       5. Listar Procedimentos por ordem alfabética          ║\n");
    printf("║                                                                             ║\n");
    printf("║                       0. Sair                                               ║\n");
    printf("║                                                                             ║\n");
    printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║  ↪Escolha a opção desejada: ");
    scanf("%d",&opcao);
    getchar();
    switch (opcao){
      case 1:
        listarAgendamentosDeHoje();
        break;
      case 2:
        listarAgendamentosPorData();
        break;
      case 3:
        listarPacientesOrdemAlfabetica();
        break;
      case 4:
        ListarMedicosOrdemAlfabetica();
        break;
      case 5:
        ListarProcedimentosOrdemAlfabetica();
        break;
      case 0:
        break;
      default:
        break;
    }
  }while(opcao != 0);
}


int compararDatas(const char *data1, const char *data2) {
    // Função para comparar as datas no formato "DDMMYYYY"
    return strcmp(data1, data2);
}

void listarAgendamentosDeHoje(void) {
    FILE *fp = fopen("agendamentos.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de agendamentos.\n");
        return;
    }

    Agendamentos agendamento;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    // Formatar a data atual no formato "DDMMYYYY"
    char dataAtual[9];
    snprintf(dataAtual, sizeof(dataAtual), "%02d%02d%04d", tm.tm_mday, tm.tm_mon + 1, tm.tm_year + 1900);

    // Imprimir a data atual para depuração
    printf("Data atual: %s\n", dataAtual);

    int encontrou = 0;

    system("clear||cls");
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                  AGENDAMENTOS DE HOJE                                          ║\n");
    printf("╠════╦══════════════════╦═════════════════════╦═══════╦══════════════════╦═══════════════════════╣\n");
    printf("║ ID ║ CPF              ║ Data do Agendamento ║ Hora  ║ Procedimento     ║ CRM                   ║\n");
    printf("╠════╬══════════════════╬═════════════════════╬═══════╬══════════════════╬═══════════════════════╣\n");

    while (fread(&agendamento, sizeof(Agendamentos), 1, fp)) {
        // Comparar a data do agendamento com a data atual
        if (compararDatas(agendamento.data, dataAtual) == 0){
            printf("║ %-2d ║ %-16s ║ %-19s ║ %-5s ║ %-16d ║ %-21s ║\n", 
                  agendamento.id, 
                  agendamento.CPF, 
                  agendamento.data, 
                  agendamento.hora, 
                  agendamento.procedimento, 
                  agendamento.CRM);
            encontrou = 1;
        }
    }

    printf("╚════════════════════════════════════════════════════════════════════════════════════════════════╝\n");

    if (!encontrou) {
        printf("Nenhum agendamento para hoje.\n");
    }

    fclose(fp);

    printf("\nPressione <ENTER> para continuar...");
    getchar();
    getchar(); // Espera o ENTER para continuar
}


void listarAgendamentosPorData(void) {
    FILE *fp = fopen("agendamentos.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de agendamentos.\n");
        return;
    }

    Agendamentos agendamento;
    char dataBusca[9];

    // Solicita a data a ser buscada no formato "DDMMYYYY"
    printf("Digite a data para buscar agendamentos (formato DDMMYYYY): ");
    scanf("%8s", dataBusca);
    getchar(); // Limpa o buffer de entrada


    int encontrou = 0;

    system("clear||cls");
    printf("\n");
    printf("╔════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                AGENDAMENTOS POR DATA                                           ║\n");
    printf("╠════╦══════════════════╦═════════════════════╦═══════╦══════════════════╦═══════════════════════╣\n");
    printf("║ ID ║ CPF              ║ Data do Agendamento ║ Hora  ║ Procedimento     ║ CRM                   ║\n");
    printf("╠════╬══════════════════╬═════════════════════╬═══════╬══════════════════╬═══════════════════════╣\n");

    while (fread(&agendamento, sizeof(Agendamentos), 1, fp)) {
        // Comparar a data do agendamento com a data buscada
        if (compararDatas(agendamento.data, dataBusca) == 0) {
            printf("║ %-2d ║ %-16s ║ %-19s ║ %-5s ║ %-16d ║ %-21s ║\n", 
                  agendamento.id, 
                  agendamento.CPF, 
                  agendamento.data, 
                  agendamento.hora, 
                  agendamento.procedimento, 
                  agendamento.CRM);
            encontrou = 1;
        }
    }

    printf("╚════════════════════════════════════════════════════════════════════════════════════════════════╝\n");

    if (!encontrou) {
        printf("Nenhum agendamento encontrado para a data informada.\n");
    }

    fclose(fp);

    printf("\nPressione <ENTER> para continuar...");
    getchar();
}

//Creditos: ChatGpt
void listarPacientesOrdemAlfabetica(void) {
    FILE *fp = fopen("paciente/paciente.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de pacientes.\n");
        return;
    }

    Paciente *pacientes = NULL;
    int count = 0, capacity = 10;

    // Alocação inicial do array dinâmico
    pacientes = malloc(capacity * sizeof(Paciente));
    if (pacientes == NULL) {
        printf("Erro de alocação de memória.\n");
        fclose(fp);
        return;
    }

    // Ler pacientes do arquivo
    while (fread(&pacientes[count], sizeof(Paciente), 1, fp)) {
        count++;
        if (count >= capacity) {
            capacity *= 2;
            pacientes = realloc(pacientes, capacity * sizeof(Paciente));
            if (pacientes == NULL) {
                printf("Erro de alocação de memória.\n");
                fclose(fp);
                return;
            }
        }
    }
    fclose(fp);

    // Ordenar pacientes alfabeticamente pelo nome
    qsort(pacientes, count, sizeof(Paciente), comparar_nomes);

    // Exibir pacientes ordenados
    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                              RELATÓRIO DE PACIENTES ORDENADOS ALFABETICAMENTE                                            ║\n");
    printf("╠════╦══════════════════════╦══════════════════╦═════════════════════╦══════════════════╦═══════════════════════╦══════════════════════════╗\n");
    printf("║ ID ║ Nome                 ║ CPF              ║ Data de Nascimento  ║ Celular          ║ Email                 ║ Endereço                 ║\n");
    printf("╠════╬══════════════════════╬══════════════════╬═════════════════════╬══════════════════╬═══════════════════════╬══════════════════════════╣\n");

    int id = 1;
    for (int i = 0; i < count; i++) {
        if (pacientes[i].status == 'a') {
            printf("║ %-2d ║ %-20s ║ %-16s ║ %-19s ║ %-16s ║ %-21s ║ %-24s ║\n", 
                  id++, 
                  pacientes[i].nome, 
                  pacientes[i].CPF, 
                  pacientes[i].data_nascimento, 
                  pacientes[i].celular, 
                  pacientes[i].email, 
                  pacientes[i].endereco);
        }
    }
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\nPressione <ENTER> para continuar...");
    getchar();

    // Liberar memória
    free(pacientes);
}

void ListarMedicosOrdemAlfabetica() {
    FILE *fp = fopen("medico/medico.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de médicos.\n");
        return;
    }

    // Contar quantos médicos existem no arquivo
    fseek(fp, 0, SEEK_END);
    long tamanho = ftell(fp);
    int total_medicos = tamanho / sizeof(Medico);
    rewind(fp); // Retorna ao início do arquivo

    if (total_medicos == 0) {
        printf("Nenhum médico cadastrado.\n");
        fclose(fp);
        return;
    }

    // Alocar memória para armazenar os médicos
    Medico *medicos = malloc(total_medicos * sizeof(Medico));
    if (medicos == NULL) {
        printf("Erro ao alocar memória.\n");
        fclose(fp);
        return;
    }

    // Ler os médicos do arquivo
    fread(medicos, sizeof(Medico), total_medicos, fp);
    fclose(fp);

    // Ordenar os médicos pelo nome (usando qsort)
    qsort(medicos, total_medicos, sizeof(Medico), comparar_medicos_por_nome);

    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                           MÉDICOS EM ORDEM ALFABÉTICA                        ║\n");
    printf("╠═══════════════╦════════════════════════════════════════╦═════════════════════╣\n");
    printf("║      CRM      ║                 Nome                   ║    Especialização   ║\n");
    printf("╠═══════════════╬════════════════════════════════════════╬═════════════════════╣\n");
    for (int i = 0; i < total_medicos; i++) {
        if (medicos[i].status == 'a') { // Exibir apenas médicos ativos
            printf("║ %-13s ║ %-38s ║ %-19s ║\n", medicos[i].CRM, medicos[i].nome, medicos[i].especializacao);
        }
    }
    printf("╚═══════════════╩════════════════════════════════════════╩═════════════════════╝\n");

    free(medicos); // Liberar a memória alocada
    printf("Pressione <ENTER> para continuar...\n");
    getchar();
}

void ListarProcedimentosOrdemAlfabetica() {
    FILE *fp = fopen("procedimentos.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de procedimentos.\n");
        return;
    }

    // Contar quantos procedimentos existem no arquivo
    fseek(fp, 0, SEEK_END);
    long tamanho = ftell(fp);
    int total_procedimentos = tamanho / sizeof(Procedimento);
    rewind(fp); // Retorna ao início do arquivo

    if (total_procedimentos == 0) {
        printf("Nenhum procedimento cadastrado.\n");
        fclose(fp);
        return;
    }

    // Alocar memória para armazenar os procedimentos
    Procedimento *procedimentos = malloc(total_procedimentos * sizeof(Procedimento));
    if (procedimentos == NULL) {
        printf("Erro ao alocar memória.\n");
        fclose(fp);
        return;
    }

    // Ler os procedimentos do arquivo
    fread(procedimentos, sizeof(Procedimento), total_procedimentos, fp);
    fclose(fp);

    // Ordenar os procedimentos pelo nome (usando qsort)
    qsort(procedimentos, total_procedimentos, sizeof(Procedimento), comparar_procedimentos_por_nome);

    system("clear||cls");
    printf("\n");
    printf("╔══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                      PROCEDIMENTOS EM ORDEM ALFABÉTICA                       ║\n");
    printf("╠═══════════╦════════════════════════════════════════╦═════════════════════════╣\n");
    printf("║     ID    ║                 Nome                   ║       Duração           ║\n");
    printf("╠═══════════╬════════════════════════════════════════╬═════════════════════════╣\n");
    for (int i = 0; i < total_procedimentos; i++) {
        if (procedimentos[i].status == 1) { // Exibir apenas procedimentos ativos
            printf("║ %-9d ║ %-38s ║ %-23s ║\n", 
                procedimentos[i].ID_procedimento, 
                procedimentos[i].nome, 
                procedimentos[i].duracao);
        }
    }
    printf("╚═══════════╩════════════════════════════════════════╩═════════════════════════╝\n");

    free(procedimentos); // Liberar a memória alocada
    printf("Pressione <ENTER> para continuar...\n");
    getchar();
}

// Função auxiliar para comparar os nomes dos procedimentos
int comparar_procedimentos_por_nome(const void *a, const void *b) {
    Procedimento *procedimentoA = (Procedimento *)a;
    Procedimento *procedimentoB = (Procedimento *)b;
    return strcmp(procedimentoA->nome, procedimentoB->nome);
}

// Função auxiliar para comparar os nomes dos médicos
int comparar_medicos_por_nome(const void *a, const void *b) {
    Medico *medicoA = (Medico *)a;
    Medico *medicoB = (Medico *)b;
    return strcmp(medicoA->nome, medicoB->nome);
}
int comparar_nomes(const void *a, const void *b) {
    Paciente *p1 = (Paciente *)a;
    Paciente *p2 = (Paciente *)b;
    return strcmp(p1->nome, p2->nome);
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
