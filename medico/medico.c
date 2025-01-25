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
    printf("║                           5. Listar Médicos                                 ║\n");
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
        case 5:
            listar_medicos();
            break;
        case 0:
            break;
        default:
        printf("Valor invalido");
        break;
        
        }
    }while(opcao != 0);
}


// ##########################
// ##      Cadastrar       ##
// ##########################
void tela_cadastrar_medico() {
    Medico *medico1 = malloc(sizeof(Medico)); // free está dentro da função salvar_medico.
    system("clear||cls");
    printf("\n");
    printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                           CADASTRAR MÉDICO                                  ║\n");
    printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
    solicitar_CRM(medico1->CRM);
    solicitar_nome_medico(medico1->nome);
    solicitar_especializacao(medico1->especializacao);
    medico1->status = 'a'; // Define o status como 'a' para ativo ao cadastrar o médico
    salvar_medico(medico1);
    printf("\n");
    printf("MÉDICO cadastrado com sucesso.");
    printf("\n");
    printf("Pressione a tecla <ENTER> para continuar...\n");
    getchar();
}


// ##########################
// ##      Pesquisar       ##
// ##########################
void tela_ver_medico() {
    char CRM_test[13];
    system("clear||cls");
    printf("\n");
    printf("↪ Informe o CRE do médico que deseja ver informações: ");
    scanf("%s",CRM_test);
    buscar_medico_ativo(CRM_test);
    getchar();
    printf("\n");
    printf("Pressione a tecla <ENTER> para continuar...\n");
    getchar();
}


void buscar_medico_ativo(const char *crm_busca) {
    FILE *fp = fopen("medico/medicos.dat", "rb"); // Abrir para leitura binária
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }
    Medico medico;
    int encontrado = 0;
    // Ler cada registro do arquivo
    while (fread(&medico, sizeof(Medico), 1, fp)) { //fread ler os blocos de dados binários
        // Verificar se o CRM coincide
        if (strcmp(medico.CRM, crm_busca) == 0) { //strcmp compara as strings
            if(medico.status == 'i'){
                printf("O medico com o CRM: %s está inativo\n",medico.CRM);
                encontrado = 1; // encontrado inativo
                break;
            }else{
                exibir_medico(medico); // Chama a função que exibe os dados do médico
                encontrado = 1; // encontrado ativo
                break;
            }
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
// ##       Atualizar      ##
// ##########################
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


// ##########################
// ##        Deletar       ##
// ##########################
void tela_deletar_medico() {
    char CRM_test[13];
    system("clear||cls");
    printf("\n↪ Informe o CRE do médico que deseja deletar: ");
    scanf("%s", CRM_test);
    printf("\n");
    printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                             DELETAR MÉDICO                                  ║\n");
    printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
    excluirMedico(CRM_test);
    
    getchar();
    printf("\n");
    printf("\nPressione a tecla <ENTER> para continuar...\n");
    getchar();
}


// ##########################
// ##   Listar Medico    ##
// ##########################
void listar_medicos() {
    int opcao;
    system("clear||cls");
    printf("\n");
    printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                            LISTAR MÉDICOS CADASTRADOS                       ║\n");
    printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                  1. Listar Todos os Médicos (Ativos e Inativos)             ║\n");
    printf("║                  2. Listar Apenas Médicos Ativos                            ║\n");
    printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
    printf("\n ↪ Escolha a opção para listar os médicos: ");
    scanf("%d", &opcao);
    system("clear||cls");

    FILE *fp = fopen("medico/medicos.dat", "rb");
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo de médicos.\n");
        return;
    }

    Medico medico;
    int encontrou = 0;
    
    printf("\n");
    printf("╔═══════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                         LISTAR TODOS OS MÉDICOS                           ║\n");
    printf("╠═══════════╦══════════════════════╦══════════════════╦═════════════════════╗\n");
    printf("║ CRM       ║ Nome                 ║ Especialização   ║ Status              ║\n");
    printf("╠═══════════╬══════════════════════╬══════════════════╬═════════════════════╣\n");

    while (fread(&medico, sizeof(Medico), 1, fp)) {
        if ((opcao == 1) || (opcao == 2 && medico.status == 'a')) { 
            printf("║ %-4s ║ %-20s ║ %-16s ║ %-19c ║\n", 
                medico.CRM, 
                medico.nome, 
                medico.especializacao, 
                medico.status);
            encontrou = 1;
        }
    }

    printf("╚═══════════════════════════════════════════════════════════════════════════╝");
    if (!encontrou) {
        printf("Nenhum médico encontrado.\n");
    }

    fclose(fp);

    printf("\nPressione <ENTER> para continuar...");
    getchar(); 
    getchar(); // Espera o ENTER para continuar
}


// ##########################
// ##    Funçoes de Ler    ##
// ##########################
void solicitar_nome_medico(char *nome) {
    int valido = 0; // Inicializando como não válido
    do {
        printf("║ ↪ Nome Completo do Médico:");
        scanf(" %[^\n]", nome);
        getchar();
        if (validarNome(nome)==1) { 
            valido = 1; // Marca como válido
        } else {
            printf("==⊳ Entrada inválida, digite apenas letras e espaços                          ║\n");
            printf("==⊳ DIGITE ENTER para continuar                                            ═══╝\n");
            valido = 0; // Marca como não válido
            while (getchar() != '\n'); // Limpar o buffer
        }
    } while (!valido); // até ser valido
}
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
    FILE *fp = fopen("medico/medicos.dat", "rb"); // Abrir o arquivo para leitura binária
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
    FILE *fp = fopen("medico/medicos.dat", "ab"); // Abrir para adicionar binário
    if (fp == NULL) {
        printf("Erro na Abertura");
        exit(1);
    }
    fwrite(medico1, sizeof(Medico), 1, fp); // Grava o conteúdo do struct
    fclose(fp);
    free(medico1);
}


void alterar_medico(const char *crm_busca) {
    FILE *fp = fopen("medico/medicos.dat", "rb+"); // Abrir para leitura e escrita binária
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
            
            // Alterar o status, se necessário
            printf("║ ↪ O médico está ativo? (Digite 1 para ativo, 0 para inativo): ");
            int status;
            scanf("%d", &status);
            if (status == 1) {
                medico.status = 'a'; // Médico ativo
            } else {
                medico.status = 'i'; // Médico inativo
            }

            // Voltar ao início do registro e sobrescrever
            fseek(fp, -sizeof(Medico), SEEK_CUR);
            fwrite(&medico, sizeof(Medico), 1, fp); // Sobrescreve o registro

            printf("\n╠══════ Dados do médico atualizados com sucesso! ═════════════════════════════╝\n");
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Médico com CRM %s não encontrado.\n", crm_busca);
    }
    fclose(fp);
}

void excluirMedico(const char *crm_busca) {
    FILE *fp = fopen("medico/medicos.dat", "rb+"); // Abrir para leitura e escrita binária
    if (fp == NULL) {
        printf("Erro ao abrir o arquivo\n");
        exit(1);
    }

    Medico medico;
    int encontrado = 0;
    while (fread(&medico, sizeof(Medico), 1, fp)) {
        if (strcmp(medico.CRM, crm_busca) == 0) {
            // Antes de deletar, altere o status para inativo
            medico.status = 'i'; // Marca como inativo
            fseek(fp, -sizeof(Medico), SEEK_CUR);  // Volta ao local do registro
            fwrite(&medico, sizeof(Medico), 1, fp);  // Sobrescreve com o novo status
            printf("Médico %s agora está inativo.\n", crm_busca);
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("Médico com CRM %s não encontrado.\n", crm_busca);
    }

    fclose(fp);
}

// Função para listar médicos com a opção de escolher entre todos ou apenas ativos

