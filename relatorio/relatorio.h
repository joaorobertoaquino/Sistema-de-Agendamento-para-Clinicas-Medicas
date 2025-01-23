#ifndef RELATORIO_H
#define RELATORIO_H
// Assinaturas RELATORIO
void listarPacientesOrdemAlfabetica();
void ListarMedicosOrdemAlfabetica();
void ListarProcedimentosOrdemAlfabetica();
int comparar_procedimentos_por_nome(const void *a, const void *b);
int comparar_medicos_por_nome(const void *a, const void *b);
int comparar_nomes(const void *a, const void *b);
void tela_relatorio(void);
void tela_relatorio_medico(void);
void tela_relatorio_paciente(void);
void tela_relatorio_procedimento(void);
void tela_relatorio_agendamento(void);
int compararDatas(const char *data1, const char *data2);
void listarAgendamentosDeHoje(void);
void listarAgendamentosPorData(void);

#endif