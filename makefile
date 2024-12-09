# Nome do executável final
TARGET = Pizzaria_Joao_Fortao

# Diretórios
SRC_DIR = Trabalho-AEDS-I/code
HEAD_DIR = Trabalho-AEDS-I/head
MAIN = Trabalho-AEDS-I/main.c
OBJ_DIR = Trabalho-AEDS-I/obj
BIN_DIR = Trabalho-AEDS-I/bin

# Compilador e flags
CC = gcc
CFLAGS = -Wall -Wextra -I$(HEAD_DIR)

# Arquivos fonte e objeto
SRCS = $(wildcard $(SRC_DIR)/*.c) $(MAIN)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS:$(MAIN)=$(OBJ_DIR)/main.o))

# Regra padrão
all: $(BIN_DIR)/$(TARGET)

# Regra para criar o executável
$(BIN_DIR)/$(TARGET): $(OBJS)
	@mkdir -p $(BIN_DIR)
	$(CC) $(OBJS) -o $@
	@echo "Executável gerado em $(BIN_DIR)/$(TARGET)"

# Regra para criar os objetos
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Regra específica para o main
$(OBJ_DIR)/main.o: $(MAIN)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpar objetos e executáveis
clean:
	rm -rf $(OBJ_DIR)/*.o $(BIN_DIR)/$(TARGET)

# Limpar tudo, incluindo diretórios
clean-all:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Regra para compilar sem erros
.PHONY: all clean clean-all
