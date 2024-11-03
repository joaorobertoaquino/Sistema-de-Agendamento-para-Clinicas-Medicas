#include <stdio.h>
#include <stdlib.h>
#include "validacoes.h"
#include <string.h>
#include <ctype.h>

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


int validar_cpf(const char *cpf) {
    // Remove caracteres não numéricos e verifica o comprimento
    char numeros[12];
    int j = 0;
    for (int i = 0; cpf[i] != '\0'; i++) {
        if (isdigit(cpf[i])) {
            if (j < 11) {
                numeros[j++] = cpf[i];
            }
        }
    }
    numeros[j] = '\0';

    // Verifica se o CPF tem 11 dígitos e não é uma sequência repetida
    if (strlen(numeros) != 11 || (numeros[0] == numeros[1] && strncmp(numeros, numeros + 1, 10) == 0)) {
        return 0; // CPF inválido
    }

    // Calcula o primeiro dígito verificador
    int soma = 0;
    for (int i = 0; i < 9; i++) {
        soma += (numeros[i] - '0') * (10 - i);
    }
    int digito1 = 11 - (soma % 11);
    if (digito1 > 9) {
        digito1 = 0;
    }

    // Verifica o primeiro dígito verificador
    if ((numeros[9] - '0') != digito1) {
        return 0; // CPF inválido
    }

    // Calcula o segundo dígito verificador
    soma = 0;
    for (int i = 0; i < 10; i++) {
        soma += (numeros[i] - '0') * (11 - i);
    }
    int digito2 = 11 - (soma % 11);
    if (digito2 > 9) {
        digito2 = 0;
    }

    // Verifica o segundo dígito verificador
    if ((numeros[10] - '0') != digito2) {
        return 0; // CPF inválido
    }

    return 1; // CPF válido
}
// Referência: https://github.com/joaorobertoaquino/Validacoes.git.

int validar_data(char* data) {
    // Verifica se a data tem exatamente 8 caracteres
    if (strlen(data) != 8) {
        printf("Data inválida. Use o formato DDMMAAAA com 8 dígitos.\n");
        return 0;
    }

    // Verifica se todos os caracteres são numéricos
    for (int i = 0; i < 8; i++) {
        if (data[i] < '0' || data[i] > '9') {
            printf("Data inválida. A data deve conter apenas números.\n");
            return 0;
        }
    }

    // Extrai o dia, mês e ano da string
    int dia = (data[0] - '0') * 10 + (data[1] - '0');  // Converte "dd" para inteiro
    int mes = (data[2] - '0') * 10 + (data[3] - '0');  // Converte "mm" para inteiro
    int ano = (data[4] - '0') * 1000 + (data[5] - '0') * 100 + (data[6] - '0') * 10 + (data[7] - '0'); // Converte "aaaa" para inteiro

    // Valida o mês (deve ser entre 1 e 12)
    if (mes < 1 || mes > 12) {
        printf("Data inválida. O mês deve estar entre 01 e 12.\n");
        return 0;
    }

    // Valida o dia com base no mês e no ano
    int diasPorMes[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Ajusta para ano bissexto se o mês for fevereiro
    if (mes == 2) {
        int anoBissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
        if (anoBissexto) {
            diasPorMes[1] = 29;
        }
    }

    // Valida o dia (deve estar dentro do limite para o mês)
    if (dia < 1 || dia > diasPorMes[mes - 1]) {
        printf("Data inválida. O dia está fora do intervalo permitido para o mês.\n");
        return 0;
    }

    return 1;  // Data válida
}

// referencia: https://github.com/jGean09/Bibliotecas-em-C/blob/main/validar_data.c


///
/// Retorna 1 se o número de celular recebido for válido (apenas números e 11 dígitos)
/// ou retorna 0 caso contrário.
///
int validar_celular(char *celular) {
    // Verifica se o celular tem exatamente 11 dígitos
    if (strlen(celular) != 11) { // Comprimento esperado
        printf("Quantidade de números do celular inválida. Deve ter 11 dígitos.\n");
        return 0; // Número de celular inválido
    }

    // Verifica se todos os caracteres são numéricos
    for (int i = 0; i < 11; i++) {
        if (celular[i] < '0' || celular[i] > '9') { // Verifica se não é um número entre '0' e '9'
            printf("O celular deve conter apenas dígitos.\n");
            return 0; // Número de celular inválido
        }
    }

    return 1; // Número de celular válido
}
//https://github.com/jGean09/Bibliotecas-em-C/blob/main/validar_celular


////
/// Função que verifica se o e-mail contém apenas caracteres válidos:
/// letras, números, '@', '.', '_', e '-'.
/// Retorna 1 se o e-mail é válido e 0 caso contrário.
///
int validar_email(char *email) {
    int posArroba = -1; // Posição do '@'
    int posPonto = -1;  // Posição do último '.'

    for (int i = 0; email[i] != '\0'; i++) {
        char c = email[i];

        // Verifica se o caractere atual é um dos permitidos
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || 
            (c >= '0' && c <= '9') || c == '@' || c == '.' || 
            c == '_' || c == '-') {

            // Se for '@', salva a posição e verifica se já existe um '@'
            if (c == '@') {
                if (posArroba != -1) {
                    printf("Erro: múltiplos '@' não são permitidos.\n");
                    return 0; // E-mail inválido
                }
                posArroba = i;
            }
            
            // Se for '.', salva a posição do último ponto
            if (c == '.') {
                posPonto = i;
            }
        } else {
            // Caractere inválido encontrado
            printf("Erro: caractere '%c' inválido no e-mail.\n", c);
            return 0; // E-mail inválido
        }
    }

    // Verifica se '@' e '.' estão em posições corretas
    if (posArroba == -1 || posPonto == -1 || posPonto < posArroba || posPonto == strlen(email) - 1) {
        printf("Erro: o e-mail precisa de '@' e '.' em posições corretas.\n");
        return 0; // E-mail inválido
    }

    return 1; // E-mail válido
}
//https://github.com/jGean09/Bibliotecas-em-C/blob/main/validar_email.c


int validar_endereco(char *endereco) {
    if (strlen(endereco) == 0) {
        printf("Erro: o endereço não pode ser vazio.\n");
        return 0; // Endereço inválido
    }

    // Verifica se todos os caracteres são válidos
    for (int i = 0; i < strlen(endereco); i++) {
        char c = endereco[i];
        
        // Verifica se o caractere não é alfanumérico, espaço ou um dos caracteres especiais permitidos
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') 
        || c == ' ' || c == '.' || c == '-' || c == '/' || c == ',')) {
            printf("Erro: o endereço deve conter apenas caracteres válidos.\n");
            return 0; // Endereço inválido
        }
    }

    return 1; // Endereço válido
}
//https://github.com/jGean09/Bibliotecas-em-C/blob/main/validar_endereco.

int validar_data_cadastro(const char *data_cadastro) {
    // Array para armazenar a data sem barras
    char data_formatada[9] = ""; 
    int j = 0;

    // Remove barras e formata a data
    for (int i = 0; i < strlen(data_cadastro); i++) {
        if (isdigit(data_cadastro[i])) {
            data_formatada[j++] = data_cadastro[i];
        }
    }
    data_formatada[j] = '\0'; // Adiciona o terminador de string

    // Verifica se a data sem barras tem exatamente 8 caracteres (DDMMYYYY)
    if (strlen(data_formatada) != 8) {
        return 0; // Formato inválido
    }

    // Extrai dia, mês e ano
    int dia = (data_formatada[0] - '0') * 10 + (data_formatada[1] - '0'); // Converte para inteiro
    int mes = (data_formatada[2] - '0') * 10 + (data_formatada[3] - '0'); // Converte para inteiro
    int ano = (data_formatada[4] - '0') * 1000 + (data_formatada[5] - '0') * 100 +
              (data_formatada[6] - '0') * 10 + (data_formatada[7] - '0'); // Converte para inteiro

    // Verifica se mês e dia estão em intervalos válidos
    if (mes < 1 || mes > 12 || dia < 1 || dia > 31) {
        return 0; // Data inválida
    }

    // Verificação de dias válidos para cada mês
    if ((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30) {
        return 0; // Meses com 30 dias
    }
    if (mes == 2) { // Fevereiro
        int bissexto = (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0);
        if ((bissexto && dia > 29) || (!bissexto && dia > 28)) {
            return 0; // Fevereiro inválido
        }
    }

    return 1; // Data válida
}