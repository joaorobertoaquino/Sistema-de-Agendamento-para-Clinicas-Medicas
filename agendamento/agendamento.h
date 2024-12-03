
struct agendamentos{
    char data[11];
    char hora[6];
    char CPF[13];
    char CRM[10];
};

void tela_agendamento(void);
void tela_cadastrar_agendamento(void);
void tela_atualizar_agendamento(void);
void tela_deletar_agendamento(void);
void tela_ver_agendamento(void);
void solicitar_data(char *data_cadastro);
void solicitar_hora(char *hora);
void solicitar_CPF(char *CPF);
void solicitar_CRM(char *CRM);