#include <stdio.h>
#include <stdlib.h>
#include "../util/util.h"
#include "../procedimento/procedimento.h"
#include "../agendamento/agendamento.h"

int obterProximoID(const char* nomeArquivo, size_t tamanhoEstrutura) {
    FILE* arquivo = fopen(nomeArquivo, "rb+");
    if (arquivo == NULL) {
        return 1;
    }
    int ultimoID = 0;
    char buffer[tamanhoEstrutura];

    while (fread(buffer, tamanhoEstrutura, 1, arquivo) == 1) {
        ultimoID = ((int*)buffer)[0];
    }

    fclose(arquivo);
    return ultimoID + 1;
}

void gravaArquivo(char nomeDoArquivo[], void* estrutura, size_t tamanhoEstrutura) {
    FILE* fp;
    fp = fopen(nomeDoArquivo, "ab");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Não é possível continuar...\n");
        exit(1);
    }
    fwrite(estrutura, tamanhoEstrutura, 1, fp);
    fclose(fp);
}