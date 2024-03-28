CC = g++
SRC_DIR = src
OBJ_DIR = obj
BULD_DIR = bin
LIBS = libs
OBJS = $(OBJ_DIR)/main.o $(OBJ_DIR)/tools.o $(OBJ_DIR)/Color.o $(OBJ_DIR)/Console.o
all:allways build_app

$(OBJ_DIR)/main.o:
	$(CC) -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/tools.o:
	$(CC) -c $(SRC_DIR)/tools.cpp -o $(OBJ_DIR)/tools.o
$(OBJ_DIR)/Color.o:
	$(CC) -c $(SRC_DIR)/Color.cpp -o $(OBJ_DIR)/Color.o
$(OBJ_DIR)/Console.o:
	$(CC) -c $(SRC_DIR)/Console.cpp -o $(OBJ_DIR)/Console.o

build_app:clean $(OBJS)
	$(CC) $(OBJS) -I $(LIBS) -o $(BULD_DIR)/out
launch:
	exec $(BULD_DIR)/out
allways:
	mkdir -p bin obj
clean:
	rm -rf $(OBJ_DIR)/*