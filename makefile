CC = g++
SRC_DIR = src
OBJ_DIR = obj
BULD_DIR = bin
LIBS = libs
all:allways build_app

$(OBJ_DIR)/main.o:
	$(CC) -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/tools.o:
	$(CC) -c $(SRC_DIR)/tools.cpp -o $(OBJ_DIR)/tools.o

build_app:clean $(OBJ_DIR)/main.o $(OBJ_DIR)/tools.o
	$(CC) $(OBJ_DIR)/main.o $(OBJ_DIR)/tools.o -I $(LIBS) -o $(BULD_DIR)/out
launch:
	exec $(BULD_DIR)/out
allways:
	mkdir -p bin obj
clean:
	rm -rf $(OBJ_DIR)/*