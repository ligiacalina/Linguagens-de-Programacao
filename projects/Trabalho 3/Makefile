# Definindo o compilador
CXX = g++

# Flags de compilação
CXXFLAGS = -Wall -std=c++11

# Nome do executável
EXEC = main

# Arquivos de cabeçalho
HEADERS = disciplina.hpp historico.hpp

# Arquivos fonte
SOURCES = disciplina.cpp historico.cpp main.cpp

# Arquivos objeto (são gerados automaticamente a partir dos arquivos fonte)
OBJECTS = $(SOURCES:.cpp=.o)

# Regra padrão que gera o executável
$(EXEC): $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJECTS)

# Regra para compilar arquivos .cpp em arquivos .o
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Regra para limpar os arquivos gerados pela compilação
clean:
	del /F $(OBJECTS) $(EXEC).exe

# Regra para executar o programa
run: $(EXEC)
	$(EXEC)

# Phony targets (para evitar conflitos com arquivos de mesmo nome)
.PHONY: clean run
