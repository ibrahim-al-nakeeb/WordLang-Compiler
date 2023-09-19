# Compiler
CC = g++
FLAGS = -std=c++14 -Iheaders

# Directories
SRC_DIR = sources
INC_DIR = headers
OBJ_DIR = obj
BIN_DIR = bin
SUBDIRS = conditions controls expressions statements symbol_table term flex bison

# Files
SRCS = $(foreach dir,$(SUBDIRS),$(wildcard $(SRC_DIR)/$(dir)/*.cpp))
OBJS = $(filter-out $(OBJ_DIR)/bison/wordlang.tab.o $(OBJ_DIR)/flex/lex.yy.o, $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS)))

# Default rule
all: create-dirs $(BIN_DIR)/wordlang

# Create directories
create-dirs:
	@mkdir -p $(SRC_DIR)/{bison,flex,output}
	@mkdir -p $(INC_DIR)/bison
	@mkdir -p $(OBJ_DIR)/{bison,flex}
	@mkdir -p $(BIN_DIR)

# Compile .cpp to .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(FLAGS) -c $< -o $@


# Flex and Bison
$(SRC_DIR)/bison/wordlang.tab.cpp $(INC_DIR)/bison/wordlang.tab.hpp: wordlang.y
	bison -d --defines=$(INC_DIR)/bison/wordlang.tab.hpp -o $(SRC_DIR)/bison/wordlang.tab.cpp wordlang.y

$(OBJ_DIR)/bison/wordlang.tab.o: $(SRC_DIR)/bison/wordlang.tab.cpp
	$(CC) $(FLAGS) -c $< -o $@

$(SRC_DIR)/flex/lex.yy.cpp: wordlang.l
	flex -o $(SRC_DIR)/flex/lex.yy.cpp wordlang.l

$(OBJ_DIR)/flex/lex.yy.o: $(SRC_DIR)/flex/lex.yy.cpp
	$(CC) $(FLAGS) -c $< -o $@

# Linking
$(BIN_DIR)/wordlang: $(OBJS) $(OBJ_DIR)/bison/wordlang.tab.o $(OBJ_DIR)/flex/lex.yy.o
	$(CC) $(FLAGS) $^ -o $@

$(BIN_DIR)/output: $(SRC_DIR)/output/output.cpp $(OBJS)
	$(CC) $(FLAGS) $^ -o $@

# Run target
run: $(BIN_DIR)/output
	$(BIN_DIR)/output

# Clean
clean:
	@rm -rf $(OBJ_DIR)
	@rm -rf $(BIN_DIR)
	@rm -rf $(SRC_DIR)/{bison,flex, output}
	@rm -rf $(INC_DIR)/bison


# Phony targets
.PHONY: all clean
