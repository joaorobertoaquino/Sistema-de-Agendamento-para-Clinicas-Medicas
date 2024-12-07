typedef struct paciente{
    char nome[51];
    char CPF [13];
    char data_nascimento[11];
    char celular[13];
    char email[51];
    char endereco[80];    
} Paciente;


// ASSINATURA DE PACIENTE

void modulo_paciente(void);
int tela_paciente(void);
void tela_cadastrar_paciente(void);
void tela_atualizar_paciente(void);
void tela_deletar_paciente(void);
void tela_ver_paciente(void);
void solicitar_nome(char *nome);
void solicitar_CPF(char *CPF);
void solicitar_data_nascimento(char *data_nascimento);
void solicitar_celular(char *celular);
void solicitar_email(char *email);
void solicitar_endereco(char *endereco);
void salvar_paciente(Paciente *paciente1);
void buscar_paciente(const char *cpf_busca);
void exibir_paciente(Paciente paciente);
void alterar_paciente(const char *cpf_busca);
int verificar_CPF_existente(const char *cpf_busca);

