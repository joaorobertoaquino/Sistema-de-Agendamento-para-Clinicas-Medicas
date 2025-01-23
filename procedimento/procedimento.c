#include <stdio.h>
#include <stdlib.h>
#include "procedimento.h"
#include "../validacoes/validacoes.h"
#include "../util/util.h"

void tela_procedimentos(void) {
  Procedimento* pro;
  int opcao;
  do {
    system("clear||cls");
    printf("\n");
    printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                        ------ PROCEDIMENTOS ------                          ║\n");
    printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                                                                             ║\n");
    printf("║                         1. Cadastrar Procedimento                           ║\n");
    printf("║                         2. Pesquisar Procedimento                           ║\n");
    printf("║                         3. Atualizar Procedimento                           ║\n");
    printf("║                         4. Remover Procedimento                             ║\n");
    printf("║                                                                             ║\n");
    printf("║                         0. Cancelar e sair                                  ║\n");
    printf("║                                                                             ║\n");
    printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║  ↪Escolha a opção desejada: ");
    scanf("%d", &opcao);
    getchar();
    switch (opcao) {
      case 1:
        pro = preencheProcedimento(0);
        exibeProcedimento(pro);
        gravaArquivo("procedimentos.dat", pro, sizeof(Procedimento));
        break;
      case 2:
        pro = pesquisarProcedimento();
        exibeProcedimento(pro);
        getchar();
        break;
      case 3:
        atualizarProcedimento();
        break;
      case 4:
        tela_deletar_procedimento();
        break;
      default:
        printf("Valor invalido");
        break;
    }
  } while(opcao != 0);

}

Procedimento* preencheProcedimento(int id) {
  Procedimento* pro;
  pro = (Procedimento*) malloc(sizeof(Procedimento));
  if (pro == NULL) {
    printf("Erro ao alocar memória para o procedimento.\n");
    exit(1);
  }
  system("clear||cls");
  printf("\n");
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                          CADASTRAR PROCEDIMENTO                             ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  const char* arquivoProcedimentos = "procedimentos.dat";
  if (id) {
    pro->ID_procedimento = id;
  }else {
    pro->ID_procedimento = obterProximoIDProcedimento(arquivoProcedimentos);
  }
  solicitar_nome_procedimento(pro->nome);
  solicitar_tempo(pro->duracao);
  pro->status = 1;
  printf("Pressione a tecla <ENTER> para continuar...\n");
  getchar();
  return pro;
}

Procedimento* pesquisarProcedimento(void){
    FILE *fp;
    Procedimento* pro;
    int id;

    system("clear||cls");
    printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                               Pesquisar Procedimento                          ║\n");
    printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║ Informe o ID do Procedimento: ");
    scanf("%d", &id);
    pro = (Procedimento*) malloc(sizeof(Procedimento));
    fp = fopen("procedimentos.dat", "rb");
    if (fp == NULL) {
      printf("Ops! Erro na abertura do arquivo!\n");
      printf("Não é possível continuar...\n");
      exit(1);
    }
    while (fread(pro, sizeof(Procedimento), 1, fp) == 1) {
      if (pro->ID_procedimento == id && pro->status == 1) {
        fclose(fp);
        return pro;
      }
    }
    fclose(fp);
    return NULL;
    getchar();
}

void exibeProcedimento(Procedimento* pro) {
    if (pro == NULL) {
      printf("\n= = = Procedimento Inexistente = = =\n");
    } else {
      printf("\n= = = Procedimento Cadastrado = = =\n");
      printf("║ ID: %d\n", pro->ID_procedimento);
      printf("║ Nome: %s\n", pro->nome);
      printf("║ Tempo de Duração: %s\n", pro->duracao);
    }
    printf("Tecle <ENTER> para continuar...");
    getchar();
}

void atualizarProcedimento(void) {
  Procedimento* pro = (Procedimento*) malloc(sizeof(Procedimento));
  Procedimento* novoPro = (Procedimento*) malloc(sizeof(Procedimento));
  system("clear||cls");
  printf("\n╔═══════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                          Atualizar Dados do Procedimento                      ║\n");
  printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n"); 
  printf("║ Informe o ID do Procedimento: ");
  scanf("%d", &pro->ID_procedimento);
  pro = encontrarPeloID(pro, "procedimentos.dat", sizeof(Procedimento), pro->ID_procedimento);
  if (pro == NULL) {
    printf("Procedimento não encontrado!!\n\n");
    free(pro);
    free(novoPro);
    return;
  }else {
    pro->status = 0;
    novoPro = preencheProcedimento(pro->ID_procedimento);
    regravarProcedimento(novoPro);
    free(pro);
  }

  printf("║                                                                               ║\n");
  printf("║                  Procedimento Atualizado com sucesso!                         ║\n");
  printf("║                                   Aguarde...                                  ║\n");
  printf("╚═══════════════════════════════════════════════════════════════════════════════╝\n");
  printf("Tecle <ENTER> para continuar...");
  getchar();
}

void regravarProcedimento(Procedimento* procedimento) {
    int achou = 0;
    FILE* fp;
    Procedimento* procedLido = (Procedimento*) malloc(sizeof(Procedimento));

    fp = fopen("procedimentos.dat", "r+b");

    if (fp == NULL) {
        printf("Erro ao abrir arquivo!!\n\n");
        getchar();
        fclose(fp);
        free(procedimento);
        free(procedLido);
        return;
    }

    while (fread(procedLido, sizeof(Procedimento), 1, fp) && !achou) {
        if (procedLido->ID_procedimento == procedimento->ID_procedimento) {
            achou = 1;
            fseek(fp, -1*sizeof(Procedimento), SEEK_CUR);
            fwrite(procedimento, sizeof(Procedimento), 1, fp);
        }
    }

    fclose(fp);
    free(procedimento);
    free(procedLido);
}

void tela_deletar_procedimento() {
  system("clear||cls");
  printf("\n");
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                            DELETAR PROCEDIMENTO                             ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                                                                             ║\n");
  printf("║    Informe o ID do procedimento que deseja deletar:                         ║\n");
  printf("║                                                                             ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
  printf("\n");
  printf("Pressione a tecla <ENTER> para continuar...\n");
  getchar();
}
void solicitar_nome_procedimento(char *nome) {
    int valido = 0; // Inicializando como não válido
    do {
        printf("║ ↪Nome do Procedimento:");
        scanf(" %[^\n]", nome);
        getchar();
        if (validarNome_procedimento(nome)==1) { 
            valido = 1; // Marca como válido
        } else {
            printf("==⊳ Entrada inválida, digite apenas letras e espaços                          ║\n");
            printf("==⊳ DIGITE ENTER para continuar                                            ═══╝\n");
            valido = 0; // Marca como não válido
            while (getchar() != '\n'); // Limpar o buffer
        }
    } while (!valido); // até ser valido
}
void solicitar_tempo(char *duracao) {
    int valido = 0; // Inicializando como não válido
    do {
        printf("║ ↪Digite Duração em HH:MM:");
        scanf(" %[^\n]", duracao);
        getchar();
        if (validar_tempo(duracao)==1) { 
            valido = 1; // Marca como válido
        } else {
            printf("==⊳ Entrada inválida, digite a duração no formato HH:MM                       ║\n");
            printf("==⊳ DIGITE ENTER para continuar                                            ═══╝\n");
            valido = 0; // Marca como não válido
            while (getchar() != '\n'); // Limpar o buffer
        }
    } while (!valido); // até ser valido
}

int obterProximoIDProcedimento(const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "rb");
    if (arquivo == NULL) {
        return 1; // Arquivo não existe ainda, ID inicial é 1
    }
    Procedimento pro;
    int ultimoID = 0;
    while (fread(&pro, sizeof(Procedimento), 1, arquivo) == 1) {
        ultimoID = pro.ID_procedimento; // Obtém o ID do último registro
    }
    fclose(arquivo);
    return ultimoID + 1; // Próximo ID
}