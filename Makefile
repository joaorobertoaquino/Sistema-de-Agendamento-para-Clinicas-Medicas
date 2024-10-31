
# Nome do executável
EXEC = sistema_agendamento

# Compilador
CC = gcc

# Opções de compilação
CFLAGS = -Wall

# Diretórios de arquivos-fonte
SRCDIR = .
OBJDIR = obj

# Lista de arquivos objeto
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

$(OBJDIR)/medico.o: medico.c medico.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c medico.c -o $(OBJDIR)/medico.o

$(OBJDIR)/agendamento.o: agendamento.c agendamento.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c agendamento.c -o $(OBJDIR)/agendamento.o

$(OBJDIR)/procedimento.o: procedimento.c procedimento.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c procedimento.c -o $(OBJDIR)/procedimento.o

$(OBJDIR)/informacoes.o: informacoes.c informacoes.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c informacoes.c -o $(OBJDIR)/informacoes.o

$(OBJDIR)/relatorio.o: relatorio.c relatorio.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c relatorio.c -o $(OBJDIR)/relatorio.o

$(OBJDIR)/validacoes.o: validacoes.c validacoes.h | $(OBJDIR)
	$(CC) $(CFLAGS) -c validacoes.c -o $(OBJDIR)/validacoes.o

# Limpeza dos arquivos gerados
clean:
	rm -f $(OBJDIR)/*.o $(EXEC)
