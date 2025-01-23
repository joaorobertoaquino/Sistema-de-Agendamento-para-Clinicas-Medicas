#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
        break;
      case 2:
        tela_relatorio_medico();
        break;
      case 3:
        listarPacientesOrdemAlfabetica();
        break;
      case 4:
        ListarMedicosOrdemAlfabetica();
        break;
      case 0:
        break;
      default:
        break;
    }
  }while(opcao != 0);
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
    printf("╔═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                                             RELATÓRIO DE PACIENTES ORDENADOS ALFABETICAMENTE                                          ║\n");
    printf("╠═══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╣\n");
    printf("╠════╦══════════════════════╦══════════════════╦═════════════════════╦══════════════════╦════════════════════╦══════════════════════════╗\n");
    printf("║ ID ║ Nome                 ║ CPF              ║ Data de Nascimento  ║ Celular          ║ Email              ║ Endereço                 ║\n");
    printf("╠════╬══════════════════════╬══════════════════╬═════════════════════╬══════════════════╬════════════════════╬══════════════════════════╣\n");

    int id = 1;
    for (int i = 0; i < count; i++) {
        if (pacientes[i].status == 'a') {
            printf("║ %-2d ║ %-20s ║ %-16s ║ %-19s ║ %-16s ║ %-18s ║ %-24s ║\n", 
                  id++, 
                  pacientes[i].nome, 
                  pacientes[i].CPF, 
                  pacientes[i].data_nascimento, 
                  pacientes[i].celular, 
                  pacientes[i].email, 
                  pacientes[i].endereco);
        }
    }
    printf("╚══════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════════╝\n");
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
