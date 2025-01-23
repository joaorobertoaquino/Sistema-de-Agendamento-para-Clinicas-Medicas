#ifndef AGENDAMENTO_H
#define AGENDAMENTO_H
typedef struct agendamentos {
    int id;
    char data[11];
    char hora[6];
    char CPF[12];
    char CRM[8];
    char procedimento[50];
} Agendamentos;

void tela_agendamento(void);
void tela_cadastrar_agendamento();
Agendamentos* preencherAgendamento(int id);
Agendamentos* pesquisarAgendamento(void);
void atualizarAgendamentos(void);
void tela_deletar_agendamento(void);
void solicitar_data(char *data_cadastro);
void solicitar_hora(char *hora);
void solicitar_CPF(char *CPF);
void solicitar_CRM(char *CRM);
int verificar_CPF(const char *cpf);
int verificar_codigo_procedimento(int codigo);
void solicitar_CRM_existente(char *crm);
void solicitar_CPF_existente(char *cpf);
int verificar_CRM(const char *crm);
void salvar_agendamento(Agendamentos *agendamentos);
int obterProximoIDAgendamento(const char* nomeArquivo);
void exibeAgendamento(Agendamentos* agen, int codigoProcedimento);
void regravarAgendamento(Agendamentos* agendamentos);

#endif