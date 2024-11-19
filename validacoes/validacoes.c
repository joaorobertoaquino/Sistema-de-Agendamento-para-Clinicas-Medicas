#include <stdio.h>
#include <stdlib.h>
#include "validacoes.h"
#include <string.h>
#include <ctype.h>
#include <stdint.h>

//############################################################## 
//#####                  Validar Letra                     #####  
//##############################################################
/// Retorna 1 se o caractere recebido for um caractere alfabético 
/// (letra entre 'A' e 'Z' ou entre 'a' e 'z') ou retorna 0 caso contrário
int ehLetra(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= 'a' && c <= 'z') {
        return 1;
    } else {
        return 0;
    }
}// Autor: Flavius Gorgonio
// referencia: https://github.com/FlaviusGorgonio/LinguaSolta_2021/blob/main/util.c


//############################################################## 
//#####                  Validar Nome                      #####  
//##############################################################
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
}// Autor: Flavius Gorgonio
// referencia: https://github.com/FlaviusGorgonio/LinguaSolta_2021/blob/main/util.c


//############################################################## 
//#####                  Validar CPF                       #####  
//##############################################################
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
} // Referência: https://github.com/joaorobertoaquino/Validacoes.git.


//############################################################## 
//#####                  Validar Data                      #####  
//##############################################################
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
}// referencia: https://github.com/jGean09/Bibliotecas-em-C/blob/main/validar_data.c


//############################################################## 
//#####                 Validar Celular                    #####  
//##############################################################
/// Retorna 1 se o número de celular recebido for válido (apenas números e 11 dígitos)
/// ou retorna 0 caso contrário.
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
} //https://github.com/jGean09/Bibliotecas-em-C/blob/main/validar_celular



//############################################################## 
//#####                 Validar Email                      #####  
//##############################################################
/// Função que verifica se o e-mail contém apenas caracteres válidos:
/// letras, números, '@', '.', '_', e '-'.
/// Retorna 1 se o e-mail é válido e 0 caso contrário.
int validar_email(const char *email) {
    int i, atPos = -1, dotPos = -1;
    int len = strlen(email);

    // Verifica o comprimento mínimo de um email (ex: a@b.co)
    if (len < 5) return 0;

    // Percorre cada caractere do email
    for (i = 0; i < len; i++) {
        char c = email[i];

        // Verifica se há exatamente um '@' e sua posição
        if (c == '@') {
            if (atPos != -1) return 0; // Mais de um '@'
            atPos = i;
        }
        // Verifica a posição do último ponto após o '@'
        else if (c == '.' && atPos != -1) {
            dotPos = i;
        }
        // Verifica caracteres inválidos (não alfanuméricos ou símbolos permitidos)
        else if (!isalnum(c) && c != '.' && c != '-' && c != '_') {
            return 0;
        }
    }

    // Verifica se '@' e '.' estão em posições válidas
    if (atPos == -1 || dotPos == -1) return 0; // Ausência de '@' ou '.'
    if (atPos < 1 || dotPos < atPos + 2 || dotPos >= len - 1) return 0;

    return 1; // Email válido
}


//############################################################## 
//#####               Validar Endereço                     #####  
//##############################################################
int validar_endereco(char *endereco) {
    if (strlen(endereco) == 0) {
        printf("Erro: o endereço não pode ser vazio.\n");
        return 0; // Endereço inválido
    }
    // Verifica se todos os caracteres são válidos
    for (size_t i = 0; i < strlen(endereco); i++) {
        char c = endereco[i];
        
        // Verifica se o caractere não é alfanumérico, espaço ou um dos caracteres especiais permitidos
        if (!((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') 
        || c == ' ' || c == '.' || c == '-' || c == '/' || c == ',')) {
            printf("Erro: o endereço deve conter apenas caracteres válidos.\n");
            return 0; // Endereço inválido
        }
    }
    return 1; // Endereço válido
}//https://github.com/jGean09/Bibliotecas-em-C/blob/main/validar_endereco.


//############################################################## 
//#####              Validar Data Cadastro                 #####  
//##############################################################
int validar_data_cadastro(const char *data_cadastro) {
    // Array para armazenar a data sem barras
    char data_formatada[9] = ""; 
    int j = 0;

    // Remove barras e formata a data
    for (size_t i = 0; i < strlen(data_cadastro); i++) {
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


//############################################################## 
//#####                 Validar Hora                       #####  
//##############################################################
int validar_hora(const char *hora) {
    // Verifica se a hora tem o formato HH:MM
    if (strlen(hora) != 5 || hora[2] != ':') {
        return 0; // Formato inválido
    }

    // Extrai horas e minutos
    int hora_int = (hora[0] - '0') * 10 + (hora[1] - '0');
    int minuto_int = (hora[3] - '0') * 10 + (hora[4] - '0');

    // Verifica se a hora e os minutos estão em intervalos válidos
    if (hora_int < 0 || hora_int > 23 || minuto_int < 0 || minuto_int > 59) {
        return 0; // Hora inválida
    }

    return 1; // Hora válida
}


//############################################################## 
//#####                 Validar CRM                        #####  
//##############################################################
int validar_CRM(const char *CRM) {
    int length = strlen(CRM);

    // Verifica se o comprimento está entre 7 e 11 (4-8 dígitos, hífen, 2 letras)
    if (length < 7 || length > 11) {
        return 0; // Formato inválido
    }

    // Verifica se os primeiros caracteres (antes do hífen) são todos dígitos
    int i = 0;
    while (i < length && isdigit(CRM[i])) {
        i++;
    }

    // Verifica se a quantidade de dígitos está entre 4 e 8
    if (i < 4 || i > 8) {
        return 0; // Quantidade inválida de dígitos
    }

    // Verifica se há um hífen logo após os dígitos
    if (CRM[i] != '-') {
        return 0; // Hífen ausente no formato correto
    }
    i++; // Avança para a verificação da sigla do estado

    // Verifica se os dois últimos caracteres são letras maiúsculas (sigla do estado)
    if (!isupper(CRM[i]) || !isupper(CRM[i + 1]) || CRM[i + 2] != '\0') {
        return 0; // Formato inválido para a sigla do estado
    }

    return 1; // Formato válido
}//chat gpt

//############################################################## 
//#####             Validar Especialização                 #####  
//##############################################################
int validarEspecializacao(char *especializacao) {
    for (size_t i = 0; i < strlen(especializacao); i++) {
        if (!isalpha(especializacao[i]) && !isspace(especializacao[i])) {
            return 0; // Retorna inválido se encontrar caracteres que não são letras ou espaços
        }
    }
    return 1; // Retorna válido
}

//############################################################## 
//#####                   Validar ID                       #####  
//##############################################################
int validar_ID(const char *id) {
    for (size_t i = 0; i < strlen(id); i++) {
        if (!isdigit(id[i])) { // Verifica se cada caractere é um dígito
            return 0; // Inválido se encontrar algo que não seja número
        }
    }
    return 1; // Válido se todos os caracteres forem números
}

//############################################################## 
//#####                 Validar tempo                      #####  
//##############################################################
int validar_tempo(char *duracao) {
    int horas = 0;
    int minutos = 0;

    // Verificação manual do formato "HH:MM" e dos valores
    for (int i = 0; i < 5; i++) {
        // Verifica o caractere na posição 2 (deve ser ':')
        if (i == 2) {
            if (duracao[i] != ':') {
                printf("Formato incorreto: falta o separador ':' na posição correta.\n");
                return 0;
            }
        } else {
            // Verifica se é um número entre '0' e '9'
            if (duracao[i] < '0' || duracao[i] > '9') {
                printf("Formato incorreto: todos os caracteres fora ':' devem ser números.\n");
                return 0;
            }
        }
    }

    // Calcula as horas e minutos convertendo os caracteres diretamente
    horas = (duracao[0] - '0') * 10 + (duracao[1] - '0');
    minutos = (duracao[3] - '0') * 10 + (duracao[4] - '0');

    // Verifica se as horas e minutos estão dentro dos limites válidos
    if (horas < 0 || horas > 23 || minutos < 0 || minutos > 59) {
        printf("Valores de horas ou minutos fora do intervalo permitido.\n");
        return 0;
    }

    return 1; // Formato de tempo válido
}
//https://github.com/jGean09/Bibliotecas-em-C/blob/main/validar_tempo