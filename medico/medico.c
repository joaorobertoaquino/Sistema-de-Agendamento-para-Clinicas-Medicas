#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "medico.h"
#include "../paciente/paciente.h"
#include "../validacoes/validacoes.h"
#include "../agendamento/agendamento.h"
typedef struct medico Medico;

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
    Medico *medico1 = malloc(sizeof(Medico));
    system("clear||cls");
    printf("\n");
    printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                           CADASTRAR MÉDICO                                  ║\n");
    printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
    solicitar_nome(medico1->nome);
    solicitar_CRM(medico1->CRM);
    solicitar_especializacao(medico1->especializacao);
    salvar_medico(medico1);
    printf("\n");
    printf("MÉDICO cadastrado com sucesso.");
    printf("\n");
    printf("Pressione a tecla <ENTER> para continuar...\n");
    getchar();
}
void tela_atualizar_medico() {
    char CRM_test[13];
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
    scanf("%s", CRM_test);
    
    // Verificar se o CRM existe
    if (verificar_CRM_existente(CRM_test)) {
        // Se o CRM existir, alterar os dados
        alterar_medico(CRM_test);
    } else {
        printf("Médico com CRM %s não encontrado.\n", CRM_test);
    }
    getchar();
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
    printf("\n");
    printf("↪ Informe o CRE do médico que deseja ver informações: ");
    scanf("%s",CRM_test);
    buscar_medico(CRM_test);
    getchar();
    printf("\n");
    printf("Pressione a tecla <ENTER> para continuar...\n");
    getchar();
}

void buscar_medico(const char *crm_busca) {
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
            exibir_medico(medico); // Chama a função que exibe os dados do médico
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Médico com CRM %s não encontrado.\n", crm_busca);
    }
    fclose(fp);
}

void exibir_medico(Medico medico) {
    printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               VER MÉDICO                                    ║\n");
    printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                                                                             ║\n");
    printf("║    CRM: %-68s║\n", medico.CRM);
    printf("║    Nome: %-67s║\n", medico.nome);
    printf("║    Especialização: %-57s║\n", medico.especializacao);
    printf("║                                                                             ║\n");
    printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
}


// ##########################
// ##    Funçoes de Ler    ##
// ##########################
void solicitar_especializacao(char *especializacao) {
    int valido = 0;  
    do {
        printf("║ ↪ Especialização: ");
        scanf(" %29[^\n]", especializacao); // Limite de 29 caracteres para evitar overflow
        if (validarEspecializacao(especializacao)) { 
            valido = 1;
        } else {
            printf("==⊳ Entrada inválida, digite apenas letras e espaços                    ║\n");
            printf("==⊳ Pressione ENTER para tentar novamente                                    ═══╝\n");
        }
    } while (!valido);
}

void solicitar_CRM(char *CRM) {
    int valido = 0;
    do {
        printf("║ ↪ CRM do médico (formato 0000000-UF): ");
        scanf(" %12[^\n]", CRM); // Limite de 12 caracteres para evitar overflow
        // Primeiro valida o formato do CRM
        if (!validar_CRM(CRM)) {
            printf("==⊳ Entrada inválida, digite no formato 0000000-UF                          ║\n");
            printf("==⊳ Pressione ENTER para tentar novamente                                    ═══╝\n");
            getchar(); // Consome o ENTER
            continue;  // Pede nova entrada
        }
        // Depois verifica se já está cadastrado
        if (verificar_CRM_existente(CRM)) {
            printf("==⊳ O CRM informado já está cadastrado. Por favor, insira outro.            ║\n");
            printf("==⊳ Pressione ENTER para tentar novamente                                    ═══╝\n");
            getchar(); // Consome o ENTER
            continue;  // Pede nova entrada
        }
        // Se passou em ambas as verificações, é válido
        valido = 1;
    } while (!valido);
}

// ##########################
// ##       Arquivo        ##
// ##########################
int verificar_CRM_existente(const char *crm_busca) {
    FILE *fp = fopen("medico/medico.dat", "rb"); // Abrir o arquivo para leitura binária
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return 0; // Retorna 0 porque não foi possível verificar
    }
    Medico medico;
    while (fread(&medico, sizeof(Medico), 1, fp)) {
        // Verifica se o CRM buscado coincide com o CRM no registro
        if (strcmp(medico.CRM, crm_busca) == 0) {
            fclose(fp); // Fecha o arquivo antes de retornar
            return 1;   // CRM encontrado
        }
    }
    fclose(fp); // Fecha o arquivo antes de retornar
    return 0;   // CRM não encontrado
}

void salvar_medico(Medico *medico1) {
    FILE *fp = fopen("medico/medico.dat", "ab"); // Abrir para adicionar binário
    if (fp == NULL) {
        printf("Erro na Abertura");
        exit(1);
    }
    fwrite(medico1, sizeof(Medico), 1, fp); // Grava o conteúdo do struct
    fclose(fp);
    free(medico1);
}


void alterar_medico(const char *crm_busca) {
    FILE *fp = fopen("medico/medico.dat", "rb+"); // Abrir para leitura e escrita binária
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
            exibir_medico(medico); // Exibe os dados atuais
            // Solicitar novas informações
            printf("\n");
            printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
            printf("║                           ALTERAR DADOS DO MÉDICO                           ║\n");
            printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
            printf("║                                                                             ║\n");
            solicitar_nome(medico.nome);
            solicitar_especializacao(medico.especializacao);
            // Não é necessário solicitar o CRM novamente, pois é o mesmo
            // Voltar ao início do arquivo e sobrescrever o registro do médico
            fseek(fp, -sizeof(Medico), SEEK_CUR);
            fwrite(&medico, sizeof(Medico), 1, fp); // Sobrescreve o registro
            printf("\n╠══════ Dados do médico atualizados com sucesso! ══════╣\n");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Médico com CRM %s não encontrado.\n", crm_busca);
    }
    fclose(fp);
}