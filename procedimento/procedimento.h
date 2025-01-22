#ifndef PROCEDIMENTO_H
#define PROCEDIMENTO_H

typedef struct procedimento{
    int ID_procedimento;
    char nome[52];
    char duracao[6]; 
    int status; 
} Procedimento;

void tela_procedimentos(void);
Procedimento* preencheProcedimento(void);
Procedimento* pesquisarProcedimento(void);
void exibeProcedimento(Procedimento* pro);
void tela_atualizar_procedimento(void);
void tela_deletar_procedimento(void);
void tela_ver_procedimento(void);
void solicitar_ID();
void solicitar_nome_procedimento(char *nome);
void solicitar_tempo(char *duracao);
int obterProximoIDProcedimento(const char* nomeArquivo);

#endif