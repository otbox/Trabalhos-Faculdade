CC = g++
CFLAGS = -Wall -std=c++14 -MMD -MP
LIBS = -lglut -lGLU -lGL -lX11 -lm

# Lista todos os arquivos .cpp
SRC = $(wildcard *.cpp)
# Cria uma lista de .o para cada .cpp
OBJ = $(SRC:.cpp=.o)
# Cria uma lista de .d (arquivos de dependência) para cada .cpp
DEPS = $(SRC:.cpp=.d)

TARGET = hello-opengl

# O primeiro alvo é o padrão
all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Inclui os arquivos de dependência gerados pelo GCC
# O '-' no início evita erros se os arquivos ainda não existirem
-include $(DEPS)

clean:
	rm -f *.o *.d $(TARGET)

.PHONY: all clean