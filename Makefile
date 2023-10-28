CC = clang
CFLAGS = -std=c11 -Wall -Wextra -Werror -Wpedantic
LDFLAGS = $(LIB_DIR)/$(LIB)
INCLUDES = -I$(INC_DIR) -I$(LIB_DIR)/$(INC_DIR)

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = inc

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRC:%.c=%.o))

LIB_DIR = libmx
LIB = libmx.a

TARGET = pathfinder

.PHONY: install clean uninstall reinstall help
.DEFAULT_GOAL := help

install: $(LIB) $(TARGET) ## Build the project

$(LIB):
	make -C $(LIB_DIR)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) $^ $(LDFLAGS) -o $@

$(OBJ): $(SRC)
	mkdir $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $^
	mv *.o $(OBJ_DIR)

uninstall: ## Delete all files and directories created during the building process
	rm -f $(TARGET)
	make -C $(LIB_DIR) uninstall

clean: ## Delete all files, excluding executables and libraries
	rm -rf $(OBJ_DIR)
	make -C $(LIB_DIR) clean

reinstall: ## Delete all created files and build the project again
	make -C $(LIB_DIR) reinstall
	make clean
	make uninstall
	make install
	
run: ## Run the program with parametr file=<filename>
	./$(TARGET) $(file)

help:
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | awk 'BEGIN {FS = ":.*?## "}; {printf "\033[36m%-30s\033[0m %s\n", $$1, $$2}'


