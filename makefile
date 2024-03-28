CC = g++
SRC_DIR = src
OBJ_DIR = obj
BULD_DIR = bin

all:allways build_app

$(OBJ_DIR)/main.o:
	$(CC) -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o

build_app:clean $(OBJ_DIR)/main.o
	$(CC) $(OBJ_DIR)/main.o -o $(BULD_DIR)/out

allways:
	mkdir -p bin obj
clean:
	rm -rf $(OBJ_DIR)/*