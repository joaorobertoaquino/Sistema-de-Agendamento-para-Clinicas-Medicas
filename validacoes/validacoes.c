#include <stdio.h>
#include <stdlib.h>
#include "validacoes.h"


///
/// Retorna 1 se o caractere recebido for um caractere alfabético 
/// (letra entre 'A' e 'Z' ou entre 'a' e 'z') ou retorna 0 caso contrário
///
int ehLetra(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= 'a' && c <= 'z') {
        return 1;
    } else {
        return 0;
    }
}
// Autor: Flavius Gorgonio
// referencia: https://github.com/FlaviusGorgonio/LinguaSolta_2021/blob/main/util.c

///
/// Retorna 1 se string recebido for exclusivamente alfabético ou
/// retorna 0 caso contrário
/// Adaptado para Valida se a string é composta apenas por letras e espaços
int validarNome(char* nome) {
    for (int i = 0; nome[i] != '\0'; i++) { // percorre até o \0
        // Se não for letra e não for espaço, retorna 0
        if (!ehLetra(nome[i]) && nome[i] != ' ') {
            return 0; // Nome inválido
        }
    }
    return 1; // Nome válido
}
// Autor: Flavius Gorgonio
// referencia: https://github.com/FlaviusGorgonio/LinguaSolta_2021/blob/main/util.c
