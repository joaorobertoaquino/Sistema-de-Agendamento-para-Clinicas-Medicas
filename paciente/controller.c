#include <stdio.h>
#include <stdlib.h>
#include "controller.h"
#include "view.h"
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

cadastrar_paciente(){
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
}



//o ponteiro permite que a função modifique diretamente o conteúdo de nome sem precisar retornar o valor.
void solicitar_nome(char *nome) {
    int valido = 0; // Inicializando como não válido
    do {
        printf("║ ↪Nome Completo:");
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
void solicitar_CPF(char *CPF){
  int valido = 0; // Inicializando como não válido
  do {
      printf("║ ↪CPF:");
      scanf(" %[^\n]", CPF); 
      getchar();
      if (validar_cpf(CPF)==1) { 
          valido = 1; // Marca como válido
      } else {
          printf("==⊳ Entrada inválida, digite apenas números                                   ║\n");
          printf("==⊳ DIGITE ENTER para continuar                                            ═══╝\n");
          valido = 0; // Marca como não válido
          while (getchar() != '\n'); // Limpar o buffer
      }
  } while (!valido); // até ser valido

}
void solicitar_data_nascimento(char *data_nascimento){
  int valido = 0; // Inicializando como não válido
  do {
      printf("║ ↪Data de Nascimento:");
      scanf(" %[^\n]", data_nascimento); 
      getchar();
      if (validar_data(data_nascimento)==1) { 
          valido = 1; // Marca como válido
      } else {
          printf("==⊳ Entrada inválida, digite apenas números                                   ║\n");
          printf("==⊳ DIGITE ENTER para continuar                                            ═══╝\n");
          valido = 0; // Marca como não válido
          while (getchar() != '\n'); // Limpar o buffer
      }
  } while (!valido); // até ser valido

}
void solicitar_celular(char *celular){
  int valido = 0; // Inicializando como não válido
  do {
      printf("║ ↪Celular:");
      scanf(" %[^\n]", celular); 
      getchar();
      if (validar_celular(celular)==1) { 
          valido = 1; // Marca como válido
      } else {
          printf("==⊳ Entrada inválida, digite apenas números                                   ║\n");
          printf("==⊳ DIGITE ENTER para continuar                                            ═══╝\n");
          valido = 0; // Marca como não válido
          while (getchar() != '\n'); // Limpar o buffer
      }
  } while (!valido); // até ser valido

}
void solicitar_email(char *email){
  int valido = 0; // Inicializando como não válido
  do {
      printf("║ ↪Email:");
      scanf(" %[^\n]", email); 
      getchar();
      if (validar_email(email)==1) { 
          valido = 1; // Marca como válido
      } else {
          printf("==⊳ Entrada inválida, Digite o Email correto                                  ║\n");
          printf("==⊳ DIGITE ENTER para continuar                                            ═══╝\n");
          valido = 0; // Marca como não válido
          while (getchar() != '\n'); // Limpar o buffer
      }
  } while (!valido); // até ser valido

}
void solicitar_endereco(char *endereco){
  int valido = 0; // Inicializando como não válido
  do {
      printf("║ ↪Endereço:");
      scanf(" %[^\n]", endereco); 
      getchar();
      if (validar_endereco(endereco)==1) { 
          valido = 1; // Marca como válido
      } else {
          printf("==⊳ Entrada inválida, Digite o endereço correto                               ║\n");
          printf("==⊳ DIGITE ENTER para continuar                                            ═══╝\n");
          valido = 0; // Marca como não válido
          while (getchar() != '\n'); // Limpar o buffer
      }
  } while (!valido); // até ser valido

}


