CC = gcc
CXX = g++
AR = ar
LD = g++

INC = -I inc
INC += -I SOIL2
SRC_DIR = src
CFLAGS = -Wall
BIN_DIR = bin
BUILD_DIR := build
STATICLIB := staticlib
SHAREDLIB := sharedlib/assimp
LIB =  -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lGLEW -lassimp

INC_DEBUG = $(INC)
BINDIR_DEBUG = $(BIN_DIR)/Debug
CFLAGS_DEBUG = $(CFLAGS) -g
LIBSTATIC_DEBUG = $(STATICLIB)
LIBSHARED_DEBUG = -L$(SHAREDLIB)
LIB_DEBUG = $(LIB)
BUILDDIR_DEBUG = $(BUILD_DIR)/Debug

GREEN := \033[0;32m
NC := \033[0m

FILES_CPP := Texture.cpp
FILES_CPP += Shader_old.cpp
FILES_CPP += Mesh.cpp
FILES_CPP += main.cpp
FILES_CPP += Window.cpp
FILES_CPP += Utility.cpp
FILES_CPP += Projection.cpp
FILES_CPP += KeyListener.cpp
FILES_CPP += MouseListener.cpp
FILES_CPP += ScrollListener.cpp
FILES_CPP += Camera.cpp
FILES_CPP += Object.cpp
FILES_CPP += Light.cpp
FILES_CPP += Material.cpp
FILES_CPP += MeshAssimp.cpp

OBJECTS += $(patsubst %.cpp, $(BUILDDIR_DEBUG)/%.o, $(FILES_CPP))

#DEPS = $(OBJECTS:%.o=%.d)

#-include $(DEPS)
$(BUILDDIR_DEBUG)/%.o: $(SRC_DIR)/%.cpp
	@echo -e " $(GREEN)Compiling CPP File1... $<${NC}"
	@mkdir -p $(BUILDDIR_DEBUG)
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -MMD -c -o $@ $<
#	-MMD option is used to create dependencies .d files

$(BUILDDIR_DEBUG)/%.o: $(SRC_DIR)/objects/%.cpp
	@echo -e " $(GREEN)Compiling CPP File2... $<${NC}"
	@mkdir -p $(BUILDDIR_DEBUG)
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -MMD -c -o $@ $<

OUTPUT := $(BINDIR_DEBUG)/output

.PHONY: all
all: $(OUTPUT)
$(OUTPUT): $(OBJECTS)
	@echo " Linking..."
#	@echo "$(OBJECTS)"
	@mkdir -p $(BINDIR_DEBUG)
	$(LD) -o $@ $(OBJECTS) $(LIB_DEBUG) $(LIBSTATIC_DEBUG)/libsoil2-debug.a $(LIBSHARED_DEBUG)

.PHONY: clean
clean:
	@echo " Cleaning Debug..."
	rm -rf $(BUILDDIR_DEBUG)/*.[od] $(BINDIR_DEBUG)/*

