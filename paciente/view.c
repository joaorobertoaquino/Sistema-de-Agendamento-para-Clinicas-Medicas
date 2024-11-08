#include <stdio.h>
#include <stdlib.h>
#include "view.h"
#include "controller.h"
#include "../validacoes/validacoes.h"


//PACIENTE
int tela_paciente(void) {
    int opcao;
    system("clear||cls");
    printf("\n");
    printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                          ------ PACIENTE ------                             ║\n");
    printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
    printf("║                                                                             ║\n");
    printf("║                          1. Cadastrar Paciente                              ║\n");
    printf("║                          2. Pesquisar Paciente                              ║\n");
    printf("║                          3. Atualizar Paciente                              ║\n");
    printf("║                          4. Remover Paciente                                ║\n");
    printf("║                                                                             ║\n");
    printf("║                          0. Cancelar e sair                                 ║\n");
    printf("║                                                                             ║\n");
    printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
    printf("║  ↪Escolha a opção desejada: ");
  
    scanf("%d", &opcao);
    getchar();
    return opcao;
}


void tela_cadastrar_paciente() {
  char nome[51];
  char CPF [13];
  char data_nascimento[11];
  char celular[13];
  char email[51];
  char endereco[80];
  system("clear||cls");
  printf("\n");
  solicitar_nome(nome);
  solicitar_CPF(CPF);
  solicitar_data_nascimento(data_nascimento);
  solicitar_celular(celular);
  solicitar_email(email);
  solicitar_endereco(endereco);
  printf("\n");
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                           CADASTRAR PACIENTE                                ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                                                                             ║\n");
  printf("║    Nome: %-67s║\n", nome);
  printf("║    CPF: %-68s║\n", CPF);
  printf("║    Data de nascimento: %-53s║\n", data_nascimento);
  printf("║    Celular: %-64s║\n", celular);
  printf("║    Email: %-66s║\n", email);
  printf("║    Endereço: %-63s║\n", endereco);
  printf("║                                                                             ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
  printf("CLIENTE cadastrado com sucesso.");
  printf("\n");
  printf("Pressione a tecla <ENTER> para continuar...\n");
  getchar();
}

void tela_atualizar_paciente() {
  system("clear||cls");
  printf("\n");
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                          ATUALIZAR PACIENTE                                 ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║  ↪Informe o CPF do paciente que deseja atualizar:                           ║\n");
  printf("║                                                                             ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
  printf("\n");
  printf("Pressione a tecla <ENTER> para continuar...\n");
  getchar();
}

void tela_deletar_paciente() {
  system("clear||cls");
  printf("\n");
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                            DELETAR PACIENTE                                 ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║  ↪Informe o CPF do paciente que deseja deletar:                             ║\n");
  printf("║                                                                             ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
  printf("\n");
  printf("Pressione a tecla <ENTER> para continuar...\n");
  getchar();
}

void tela_ver_paciente() {
  system("clear||cls");
  printf("\n");
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                               VER PACIENTE                                  ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║  ↪Informe o CPF do paciente que deseja ver informações:                     ║\n");
  printf("║                                                                             ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
  printf("\n");
  printf("Pressione a tecla <ENTER> para continuar...\n");
  getchar();
}