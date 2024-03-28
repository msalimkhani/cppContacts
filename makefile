CC = g++
SRC_DIR = src
OBJ_DIR = obj
BULD_DIR = bin
OBJS = $(OBJ_DIR)/main.o
all:allways build_app

$(OBJ_DIR)/main.o:
	$(CC) -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o

build_app:clean $(OBJS)
	$(CC) $(OBJS) -o $(BULD_DIR)/out
launch:
	exec $(BULD_DIR)/out
allways:
	mkdir -p bin obj
clean:
	rm -rf $(OBJ_DIR)/*