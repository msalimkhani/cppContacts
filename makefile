CC = g++
SRC_DIR = src
OBJ_DIR = obj
BUILD_DIR = bin
OBJS = $(OBJ_DIR)/main.o
APP = out
all:allways build_app

$(OBJ_DIR)/main.o:
	@printf "Compiling %s\n" $(OBJ_DIR)/main.o
	@$(CC) -c $(SRC_DIR)/main.cpp -o $(OBJ_DIR)/main.o

build_app:clean $(OBJS)
	@printf "Linking all together -> %s\n" $(BUILD_DIR)/$(APP)
	@$(CC) $(OBJS) -o $(BUILD_DIR)/$(APP)
launch:
	@printf "Running %s\n" $(BUILD_DIR)/$(APP)
	@exec $(BUILD_DIR)/out
allways:
	@printf "App name Set: %s\n" $(APP)
	@printf "CC: %s\nBuild Directory: %s\n" $(CC) $(BUILD_DIR)
	@printf "Creating Necessary Directories\n"
	@mkdir -p bin obj
clean:
	@printf "Cleaning Up...\n"
	@rm -rf $(OBJ_DIR)/*
	@rm -rf $(BUILD_DIR)/*
