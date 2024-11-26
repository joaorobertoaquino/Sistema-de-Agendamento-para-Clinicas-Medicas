struct procedimentos{
    int ID_procedimento;
    char nome[52];
    char duracao[6];  
};

void tela_procedimentos(void);
void tela_cadastrar_procedimento(void);
void tela_atualizar_procedimento(void);
void tela_deletar_procedimento(void);
void tela_ver_procedimento(void);
void solicitar_ID();
void solicitar_nome_procedimento(char *nome);
void solicitar_tempo(char *duracao);

