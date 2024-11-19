# Makefile

# Compiler
CC := gcc

# Compiler flags
CFLAGS := -Wall -Wextra -pedantic

# Source files
SRCS := main.c agendamento/agendamento.c informacoes/informacoes.c medico/medico.c paciente/paciente.c procedimento/procedimento.c relatorio/relatorio.c validacoes/validacoes.c

# Object files
OBJS := $(SRCS:.c=.o)

# Header files
HDRS := agendamento/agendamento.h informacoes/informacoes.h medico/medico.h paciente/paciente.h procedimento/procedimento.h relatorio/relatorio.h validacoes/validacoes.h

# Executable name
TARGET := main

# Windows-specific settings
ifeq ($(OS),Windows_NT)
    RM := del /Q
    TARGET := $(TARGET).exe
else
    RM := rm -f
endif

# Default target
all: $(TARGET)

# Compile object files
%.o: %.c $(HDRS)
	$(CC) $(CFLAGS) -c $< -o $@

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Run the executable
run: $(TARGET)
	./$(TARGET)

# Clean up object files and executable
clean:
	$(RM) $(OBJS) $(TARGET)

# Reference: https://github.com/Lleusxam/c-recipes/blob/main/makefile