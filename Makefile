# Nome do executável
EXEC = cadastroFuncionarios

# Compilador e flags
CXX = g++
CXXFLAGS = -O0 -g -Wall -ansi -pedantic -c

# Arquivos fonte e objetos
SRC = main.cpp funcoes.cpp
OBJ = main.o funcoes.o

# Regra padrão
all: $(EXEC)

# Compilação do executável
$(EXEC): $(OBJ)
	$(CXX) -o $(EXEC) $(OBJ)

# Compilação dos arquivos fonte
main.o: main.cpp cadastro.h
	$(CXX) $(CXXFLAGS) main.cpp

funcoes.o: funcoes.cpp cadastro.h
	$(CXX) $(CXXFLAGS) funcoes.cpp

clean:
	rm -f $(OBJ) $(EXEC)
