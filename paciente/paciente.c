#include <stdio.h>
#include <stdlib.h>
// #include <unistd.h>
#include "paciente.h"
#include "../validacoes/validacoes.h"

void modulo_paciente(void){
  int opcao;
  do{
    opcao = tela_paciente();
    switch (opcao) {
      case 1:
        tela_cadastrar_paciente();
        break;
      case 2:
        tela_ver_paciente();
        break;
      case 3:
        tela_atualizar_paciente();
        break;
      case 4:
        tela_deletar_paciente();
        break;
      case 0:
        break;
      default:
        printf("Valor invalido");
        break;
    }
  }while(opcao != 0);

}
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
  char CPF [12];
  char data_nascimento[10];
  char celular[13];
  system("clear||cls");
  printf("\n");
  solicitar_nome(nome);
  solicitar_CPF(CPF);
  solicitar_data_nascimento(data_nascimento);
  solicitar_celular();
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                           CADASTRAR PACIENTE                                ║\n");
  printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
  printf("║                                                                             ║\n");
  printf("║    Nome:                                                                    ║\n");
  printf("Nome: %s\n",nome);
  printf("║    CPF:                                                                     ║\n");
  printf("CPF: %s\n",CPF);
  printf("║    Data de nascimento:                                                      ║\n");
  printf("Data nascimento:%s\n",data_nascimento);
  printf("║    Celular:                                                                 ║\n");
  printf("║    Email:                                                                   ║\n");
  printf("║    Endereço:                                                                ║\n");
  printf("║                                                                             ║\n");
  printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
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

//o ponteiro permite que a função modifique diretamente o conteúdo de nome sem precisar retornar o valor.
void solicitar_nome(char *nome) {
    int valido = 0; // Inicializando como não válido
    do {
        printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
        printf("║  ↪Informe o nome completo do paciente:                                      ║\n");
        printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
        printf("╚══ Nome Completo:");
        scanf(" %[^\n]", nome);
        getchar();
        if (validarNome(nome)==1) { 
            valido = 1; // Marca como válido
        } else {
            printf("╠══↪Entrada inválida, digite apenas letras e espaços                       ═══╣\n");
            printf("╠══↪DIGITE ENTER para continuar                                            ═══╣\n");
            valido = 0; // Marca como não válido
            while (getchar() != '\n'); // Limpar o buffer
        }
    } while (!valido); // até ser valido
}
void solicitar_CPF(char *CPF){
  int valido = 0; // Inicializando como não válido
  do {
      printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
      printf("║  ↪Informe o CPF do paciente:                                                ║\n");
      printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
      printf("╚══ CPF:");
      scanf(" %[^\n]", CPF); 
      getchar();
      if (validar_cpf(CPF)==1) { 
          valido = 1; // Marca como válido
      } else {
          printf("╠══↪Entrada inválida, digite apenas números                                ═══╣\n");
          printf("╠══↪DIGITE ENTER para continuar                                            ═══╣\n");
          valido = 0; // Marca como não válido
          while (getchar() != '\n'); // Limpar o buffer
      }
  } while (!valido); // até ser valido

}
void solicitar_data_nascimento(char *data_nascimento){
  int valido = 0; // Inicializando como não válido
  do {
      printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
      printf("║  ↪Informe o data de Nascimento do paciente:                                 ║\n");
      printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
      printf("╚══ Data:");
      scanf(" %[^\n]", data_nascimento); 
      getchar();
      if (validar_data(data_nascimento)==1) { 
          valido = 1; // Marca como válido
      } else {
          printf("╠══↪Entrada inválida, digite apenas números                                ═══╣\n");
          printf("╠══↪DIGITE ENTER para continuar                                            ═══╣\n");
          valido = 0; // Marca como não válido
          while (getchar() != '\n'); // Limpar o buffer
      }
  } while (!valido); // até ser valido

}

