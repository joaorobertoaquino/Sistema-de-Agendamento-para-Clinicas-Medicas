# Nome do executável
EXEC = sistema_agendamento

# Compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall

# Diretórios de arquivos-fonte e objeto
SRCDIR = .
OBJDIR = obj

# Lista de arquivos objeto, considerando que os arquivos fonte estão em suas respectivas pastas
OBJS = $(OBJDIR)/main.o $(OBJDIR)/paciente.o $(OBJDIR)/medico.o $(OBJDIR)/agendamento.o \
       $(OBJDIR)/procedimento.o $(OBJDIR)/informacoes.o $(OBJDIR)/relatorio.o \
       $(OBJDIR)/validacoes.o

# Regra padrão
all: $(OBJDIR) $(EXEC)

# Regras para compilar o executável
$(EXEC): $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

# Criação do diretório obj caso não exista
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Regras para compilar os arquivos-fonte em arquivos objeto
$(OBJDIR)/main.o: main.c | $(OBJDIR)
	$(CC) $(CFLAGS) -c main.c -o $(OBJDIR)/main.o

$(OBJDIR)/paciente.o: paciente/paciente.c paciente/paciente.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c paciente/paciente.c -o $(OBJDIR)/paciente.o

$(OBJDIR)/medico.o: medico/medico.c medico/medico.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c medico/medico.c -o $(OBJDIR)/medico.o

$(OBJDIR)/agendamento.o: agendamento/agendamento.c agendamento/agendamento.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c agendamento/agendamento.c -o $(OBJDIR)/agendamento.o

$(OBJDIR)/procedimento.o: procedimento/procedimento.c procedimento/procedimento.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c procedimento/procedimento.c -o $(OBJDIR)/procedimento.o

$(OBJDIR)/informacoes.o: informacoes/informacoes.c informacoes/informacoes.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c informacoes/informacoes.c -o $(OBJDIR)/informacoes.o

$(OBJDIR)/relatorio.o: relatorio/relatorio.c relatorio/relatorio.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c relatorio/relatorio.c -o $(OBJDIR)/relatorio.o

$(OBJDIR)/validacoes.o: validacoes/validacoes.c validacoes/validacoes.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c validacoes/validacoes.c -o $(OBJDIR)/validacoes.o

# Limpeza dos arquivos gerados
clean:
	rm -rf $(OBJDIR)/*.o $(EXEC)
