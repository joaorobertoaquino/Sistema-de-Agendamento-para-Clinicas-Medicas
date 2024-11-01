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
  char CPF [11];
  system("clear||cls");
  printf("\n");
  solicitar_nome(nome);
  printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
  printf("║                           CADASTRAR PACIENTE                                ║\n");
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
        printf("║  ↪Informe o nome comepleto do paciente:                                     ║\n");
        printf("╠═════════════════════════════════════════════════════════════════════════════╣\n");
        printf("╚══ Nome Completo:");
        scanf(" %[^\n]", nome); // coloquei pra ler até o \n
        if (validarNome(nome)==1) { 
            valido = 1; // Marca como válido
        } else {
            printf("╠══↪Entrada inválida, digite apenas letras e espaços                       ═══╣\n");
            valido = 0; // Marca como não válido
            while (getchar() != '\n'); // Limpar o buffer
        }
    } while (!valido); // até ser valido
}
