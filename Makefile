OBJS = ./src/*.cpp
CC = g++
COMPILER_FLAGS = -w -std=c++14
LINKER_FLAGS = -lSDL2 -lSOIL -lSDL2_image -lGLEW -framework OpenGL
OBJ_NAME = game

all: $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

run:
	./$(OBJ_NAME)
