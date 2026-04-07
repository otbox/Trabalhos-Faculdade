CC = g++
CFLAGS = -Wall -std=c++11
LIBS = -lglut -lGLU -lGL -lX11 -lm

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)

TARGET = hello-opengl

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) -o $@ $^ $(LIBS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f *.o $(TARGET)