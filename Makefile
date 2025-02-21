# DIRS
CURDIR = $(shell pwd)
BIN_DIR = $(CURDIR)/bin
BUILD_DIR = $(CURDIR)/build
SOURCE_DIR = $(CURDIR)/src

# TARGETS
TARGET = $(BIN_DIR)/main

# OBJECT FILES 
TRAITS_OBJ = $(BUILD_DIR)/traits/traits.o

# SOURCES 
MAIN_SRC = $(SOURCE_DIR)/main.cc
TRAITS_SRC = $(SOURCE_DIR)/traits/traits.cc

# FLAGS 
CFLAGS = -Wall -g -I$(SOURCE_DIR)
CC = g++

NIVELES_OBJ = $(TRAITS_OBJ)

$(BUILD_DIR)/traits:
	mkdir -p $(BUILD_DIR)/traits

# COMPILAR EL PROGRAMA PRINCIPAL
all: $(MAIN_SRC) $(NIVELES_OBJ)
	$(CC) $(CFLAGS) $(MAIN_SRC) $(NIVELES_OBJ) -o $(TARGET)

# CREAR ARCHIVOS OBJECTO 
$(TRAITS_OBJ): $(TRAITS_SRC) $(BUILD_DIR)/traits
	$(CC) $(CFLAGS) -c $(TRAITS_SRC) -o $(TRAITS_OBJ)

clean:
	rm -rf $(TARGET)
	rm -rf $(NIVELES_OBJ)
	rm -rf $(NIVELES_LIB)
	rm -rf $(BUILD_DIR)/*

