# Configurações do compilador
CXX = g++
CXXFLAGS = -std=c++11 -Wall

# Nome do executável
TARGET = main

# Lista de arquivos fonte
SRCS = main.cpp sistema.cpp atleta.cpp

# Lista de cabeçalhos
HEADERS = atleta.hpp arvore.hpp sistema.hpp

# Lista de objetos a serem gerados (automaticamente derivado de SRCS)
OBJS = $(SRCS:.cpp=.o)

# Regras de compilação
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Regras de compilação de cada arquivo .cpp
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpeza dos arquivos temporários e executável
clean:
	rm -f $(OBJS) $(TARGET)
