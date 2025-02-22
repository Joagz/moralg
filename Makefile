# DIRS
CURDIR              = $(shell pwd)
BIN_DIR             = $(CURDIR)/bin
BUILD_DIR           = $(CURDIR)/build
SOURCE_DIR          = $(CURDIR)/src

# TARGETS
TARGET              = $(BIN_DIR)/main

# OBJECT FILES 
TRAITS_OBJ          = $(BUILD_DIR)/traits/traits.o
ALGORITHM_OBJ       = $(BUILD_DIR)/algorithm/algorithm.o
GAUSSIAN_OBJ        = $(BUILD_DIR)/math/gaussian/gaussian.o
FUNCTIONS_OBJ       = $(SOURCE_DIR)/math/functions.o

# SOURCES 
MAIN_SRC            = $(SOURCE_DIR)/main.cc
TRAITS_SRC          = $(SOURCE_DIR)/traits/traits.cc
ALGORITHM_SRC       = $(SOURCE_DIR)/algorithm/algorithm.cc
GAUSSIAN_SRC        = $(SOURCE_DIR)/math/gaussian.cc
FUNCTIONS_SRC       = $(SOURCE_DIR)/math/functions.cc

# FLAGS 
CFLAGS              = -Wall -g -I$(SOURCE_DIR) -I$(SOURCE_DIR)/traits -I$(SOURCE_DIR)/algorithm
CC                  = g++

OBJECTS             = $(TRAITS_OBJ) $(ALGORITHM_OBJ) $(GAUSSIAN_OBJ) $(FUNCTIONS_OBJ)

$(BUILD_DIR)/traits:
	mkdir -p $(BUILD_DIR)/traits

$(BUILD_DIR)/algorithm:
	mkdir -p $(BUILD_DIR)/algorithm

$(BUILD_DIR)/math/gaussian:
	mkdir -p $(BUILD_DIR)/math/gaussian

$(BUILD_DIR)/math/functions:
	mkdir -p $(BUILD_DIR)/math/functions

# COMPILAR EL PROGRAMA PRINCIPAL
all                 : $(MAIN_SRC) $(OBJECTS)
	$(CC) $(CFLAGS) $(MAIN_SRC) $(OBJECTS) -o $(TARGET)

# CREAR ARCHIVOS OBJECTO 
$(TRAITS_OBJ)       : $(TRAITS_SRC) $(BUILD_DIR)/traits
	$(CC) $(CFLAGS) -c $(TRAITS_SRC) -o $(TRAITS_OBJ)

$(ALGORITHM_OBJ)    : $(ALGORITHM_SRC) $(BUILD_DIR)/algorithm
	$(CC) $(CFLAGS) -c $(ALGORITHM_SRC) -o $(ALGORITHM_OBJ)

$(GAUSSIAN_OBJ)     : $(GAUSSIAN_SRC) $(BUILD_DIR)/math/gaussian
	$(CC) $(CFLAGS) -c $(GAUSSIAN_SRC) -o $(GAUSSIAN_OBJ)

$(FUNCTIONS_OBJ)    : $(FUNCTIONS_SRC) $(BUILD_DIR)/math/functions
	$(CC) $(CFLAGS) -c $(FUNCTIONS_SRC) -o $(FUNCTIONS_OBJ)


clean               : 
	rm -rf $(TARGET)
	rm -rf $(BUILD_DIR)/*

