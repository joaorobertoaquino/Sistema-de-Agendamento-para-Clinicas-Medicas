#ifndef UTIL_H
#define UTIL_H
#include <stddef.h>
#include "../procedimento/procedimento.h"
#include "../agendamento/agendamento.h"

int obterProximoID(const char* nomeArquivo, size_t tamanhoEstrutura);
void gravaArquivo(char nomeDoArquivo[], void* estrutura, size_t tamanhoEstrutura);
void* encontrarPeloID(void* estrutura, char* nomeArquivo, size_t tamanhoEstrutura, int id);

#endif