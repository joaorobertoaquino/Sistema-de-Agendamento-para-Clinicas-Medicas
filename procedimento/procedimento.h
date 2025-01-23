#ifndef PROCEDIMENTO_H
#define PROCEDIMENTO_H

typedef struct procedimento{
    int ID_procedimento;
    char nome[52];
    char duracao[6]; 
    int status; 
} Procedimento;

void tela_procedimentos(void);
Procedimento* preencheProcedimento(int id);
Procedimento* pesquisarProcedimento(void);
void exibeProcedimento(Procedimento* pro);
void atualizarProcedimento(void);
void deletarProcedimento(void);
void solicitar_ID();
void solicitar_nome_procedimento(char *nome);
void solicitar_tempo(char *duracao);
int obterProximoIDProcedimento(const char* nomeArquivo);
void regravarProcedimento(Procedimento* procedimento);

#endif