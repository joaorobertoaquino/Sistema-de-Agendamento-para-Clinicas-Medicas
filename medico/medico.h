typedef struct medico {
    char CRM[10];
    char nome[50];
    char especializacao[31];
    char status;
} Medico;

// MÉDICO
void tela_medico(void);
void tela_cadastrar_medico(void);
void tela_atualizar_medico(void);
void tela_deletar_medico(void);
void tela_ver_medico(void);
void solicitar_nome_medico(char *nome);
void solicitar_especializacao(char *especializacao);
void salvar_medico(Medico *medico1);
void buscar_medico_ativo(const char *crm_busca);
int verificar_CRM_existente(const char *crm_busca);
void exibir_medico(Medico medico);
void alterar_medico(const char *crm_busca);
void excluirMedico(const char *crm_busca);
void listar_medicos();