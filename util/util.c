#include <stdio.h>
#include <stdlib.h>
#include "../util/util.h"
#include "../procedimento/procedimento.h"
#include "../agendamento/agendamento.h"

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

void* encontrarPeloID(void* estrutura, char* nomeArquivo, size_t tamanhoEstrutura, int id) {
    int encontrado = 0;
    FILE* fp = fopen(nomeArquivo, "rb");
    if (fp == NULL) {
        printf("Ops! Erro na abertura do arquivo!\n");
        printf("Não é possível continuar...\n");
        free(estrutura);
        fclose(fp);
        return NULL;
        // exit(1);
    }
    while (fread(estrutura, tamanhoEstrutura, 1, fp) == 1) {
        // verifica se o último id é igual ao id informado
        if (*(int*)estrutura == id) {
            encontrado = 1;
            break;
        }
    }
    fclose(fp);
    if (encontrado) {
        return estrutura;
    } else {
        // free(estrutura);
        return NULL;
    }
}
