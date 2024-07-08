# Diretório do pybind11
PYBIND11_DIR := ./pybind11/include

# Diretório do Python (ajuste conforme necessário)
PYTHON_INCLUDE_DIR := C:/msys64/ucrt64/include/python3.11
PYTHON_LIB_DIR := C:/msys64/ucrt64/lib

# Compilador e flags
CXX := g++
CXXFLAGS := -std=c++11 -O2 -I$(PYBIND11_DIR) -I$(PYTHON_INCLUDE_DIR) -I./include
LDFLAGS := -L$(PYTHON_LIB_DIR) -lpython3.11

# Nome do seu executável
TARGET := main

# Fonte e objetos
SRC := src/bindings.cpp src/sistemaTarefas.cpp src/tarefa.cpp src/main.cpp
OBJ := $(SRC:.cpp=.o)

# Diretório de dados
DATA_DIR := ./data

# Regras de compilação
all: $(TARGET)

# Compilar o executável
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET) $(LDFLAGS)
	cmd /c copy $(DATA_DIR)\tarefas.txt .
	cmd /c copy $(DATA_DIR)\tarefasConcluidas.txt .

# Compilar arquivos .cpp
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	del $(OBJ) $(TARGET) tarefas.txt tarefasConcluidas.txt  # Comando para deletar arquivos no Windows

.PHONY: clean
