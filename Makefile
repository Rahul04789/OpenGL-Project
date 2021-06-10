# WORKDIR = `pwd`

CC = gcc
CXX = g++
AR = ar
LD = g++
WINDRES = windres

INC = -I inc
INC += -I SOIL2
SRC = src
CFLAGS = -Wall
RESINC = 
LIBDIR = 
STATICLIB = staticlib
SHAREDLIB = sharedlib/assimp
LIB =  -lGL -lGLU -lglfw3 -lX11 -lXxf86vm -lXrandr -lpthread -lXi -ldl -lGLEW -lassimp
LDFLAGS = 

INC_DEBUG = $(INC)
CFLAGS_DEBUG = $(CFLAGS) -g
RESINC_DEBUG = $(RESINC)
RCFLAGS_DEBUG = $(RCFLAGS)
LIBDIR_DEBUG = $(LIBDIR)
LIBSTATIC_DEBUG = $(STATICLIB)
LIBSHARED_DEBUG = -L$(SHAREDLIB)
LIB_DEBUG = $(LIB)
LDFLAGS_DEBUG = $(LDFLAGS)
OBJDIR_DEBUG = obj/Debug
DEP_DEBUG = 
OUT_DEBUG = bin/Debug/OpenGLTest

INC_RELEASE = $(INC)
CFLAGS_RELEASE = $(CFLAGS) -O2
RESINC_RELEASE = $(RESINC)
RCFLAGS_RELEASE = $(RCFLAGS)
LIBDIR_RELEASE = $(LIBDIR)
LIB_RELEASE = $(LIB)
LDFLAGS_RELEASE = $(LDFLAGS) -s
OBJDIR_RELEASE = obj/Release
DEP_RELEASE = 
OUT_RELEASE = bin/Release/OpenGLTest

OBJ_DEBUG = $(OBJDIR_DEBUG)/main.o $(OBJDIR_DEBUG)/Window.o $(OBJDIR_DEBUG)/Shader_old.o $(OBJDIR_DEBUG)/Utility.o $(OBJDIR_DEBUG)/Mesh.o $(OBJDIR_DEBUG)/Projection.o $(OBJDIR_DEBUG)/KeyListener.o $(OBJDIR_DEBUG)/MouseListener.o $(OBJDIR_DEBUG)/ScrollListener.o $(OBJDIR_DEBUG)/Camera.o $(OBJDIR_DEBUG)/objects/Light.o $(OBJDIR_DEBUG)/objects/Material.o $(OBJDIR_DEBUG)/objects/Object.o $(OBJDIR_DEBUG)/Texture.o $(OBJDIR_DEBUG)/MeshAssimp.o
OBJ_RELEASE = $(OBJDIR_RELEASE)/main.o $(OBJDIR_RELEASE)/Window.o $(OBJDIR_RELEASE)/Utility.o #$(OBJDIR_RELEASE)/Shader_old.o $(OBJDIR_RELEASE)/Mesh.o
all: debug

clean: clean_debug

before_debug: 
	test -d bin/Debug || mkdir -p bin/Debug
	test -d $(OBJDIR_DEBUG) || mkdir -p $(OBJDIR_DEBUG)
	test -d $(OBJDIR_DEBUG)/objects || mkdir -p $(OBJDIR_DEBUG)/objects
	@echo " Linking library file..."
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/local/lib

after_debug: 

debug: before_debug out_debug after_debug

out_debug: before_debug $(OBJ_DEBUG) $(DEP_DEBUG)
	@echo " Linking..."
	$(LD) $(LIBDIR_DEBUG) -o $(OUT_DEBUG) $(OBJ_DEBUG)  $(LDFLAGS_DEBUG) $(LIB_DEBUG) $(LIBSTATIC_DEBUG)/libsoil2-debug.a $(LIBSHARED_DEBUG)

$(OBJDIR_DEBUG)/Texture.o: $(SRC)/Texture.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c $(SRC)/Texture.cpp -o $(OBJDIR_DEBUG)/Texture.o

$(OBJDIR_DEBUG)/stb_image.o: stb_image.c
	$(CC) $(CFLAGS_DEBUG) $(INC_DEBUG) -c stb_image.c -o $(OBJDIR_DEBUG)/stb_image.o

$(OBJDIR_DEBUG)/Shader_old.o: $(SRC)/Shader_old.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c $(SRC)/Shader_old.cpp -o $(OBJDIR_DEBUG)/Shader_old.o

$(OBJDIR_DEBUG)/obj_loader.o: obj_loader.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c obj_loader.cpp -o $(OBJDIR_DEBUG)/obj_loader.o

$(OBJDIR_DEBUG)/Mesh.o: $(SRC)/Mesh.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c $(SRC)/Mesh.cpp -o $(OBJDIR_DEBUG)/Mesh.o

$(OBJDIR_DEBUG)/main.o: $(SRC)/main.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c $(SRC)/main.cpp -o $(OBJDIR_DEBUG)/main.o

$(OBJDIR_DEBUG)/Window.o: $(SRC)/Window.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c $(SRC)/Window.cpp -o $(OBJDIR_DEBUG)/Window.o

$(OBJDIR_DEBUG)/Utility.o: $(SRC)/Utility.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c $(SRC)/Utility.cpp -o $(OBJDIR_DEBUG)/Utility.o

$(OBJDIR_DEBUG)/Projection.o: $(SRC)/Projection.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c $(SRC)/Projection.cpp -o $(OBJDIR_DEBUG)/Projection.o

$(OBJDIR_DEBUG)/KeyListener.o: $(SRC)/KeyListener.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c $(SRC)/KeyListener.cpp -o $(OBJDIR_DEBUG)/KeyListener.o

$(OBJDIR_DEBUG)/MouseListener.o: $(SRC)/MouseListener.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c $(SRC)/MouseListener.cpp -o $(OBJDIR_DEBUG)/MouseListener.o

$(OBJDIR_DEBUG)/ScrollListener.o: $(SRC)/ScrollListener.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c $(SRC)/ScrollListener.cpp -o $(OBJDIR_DEBUG)/ScrollListener.o

$(OBJDIR_DEBUG)/Camera.o: $(SRC)/Camera.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c $(SRC)/Camera.cpp -o $(OBJDIR_DEBUG)/Camera.o

$(OBJDIR_DEBUG)/objects/Light.o: $(SRC)/objects/Light.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c $(SRC)/objects/Light.cpp -o $(OBJDIR_DEBUG)/objects/Light.o

$(OBJDIR_DEBUG)/objects/Material.o: $(SRC)/objects/Material.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c $(SRC)/objects/Material.cpp -o $(OBJDIR_DEBUG)/objects/Material.o

$(OBJDIR_DEBUG)/objects/Object.o: $(SRC)/objects/Object.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c $(SRC)/objects/Object.cpp -o $(OBJDIR_DEBUG)/objects/Object.o

$(OBJDIR_DEBUG)/MeshAssimp.o: $(SRC)/MeshAssimp.cpp
	$(CXX) $(CFLAGS_DEBUG) $(INC_DEBUG) -c $(SRC)/MeshAssimp.cpp -o $(OBJDIR_DEBUG)/MeshAssimp.o

clean_debug: 
	rm -rf $(OBJ_DEBUG) $(OUT_DEBUG) 
	rm -rf bin/Debug
	rm -rf $(OBJDIR_DEBUG)

before_release: 
	test -d bin/Release || mkdir -p bin/Release
	test -d $(OBJDIR_RELEASE) || mkdir -p $(OBJDIR_RELEASE)

after_release: 

release: before_release out_release after_release

out_release: before_release $(OBJ_RELEASE) $(DEP_RELEASE)
	$(LD) $(LIBDIR_RELEASE) -o $(OUT_RELEASE) $(OBJ_RELEASE)  $(LDFLAGS_RELEASE) $(LIB_RELEASE)

$(OBJDIR_RELEASE)/texture.o: texture.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c texture.cpp -o $(OBJDIR_RELEASE)/texture.o

$(OBJDIR_RELEASE)/stb_image.o: stb_image.c
	$(CC) $(CFLAGS_RELEASE) $(INC_RELEASE) -c stb_image.c -o $(OBJDIR_RELEASE)/stb_image.o

$(OBJDIR_RELEASE)/Shader_old.o: $(SRC)/Shader_old.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c $(SRC)/Shader_old.cpp -o $(OBJDIR_RELEASE)/Shader_old.o

$(OBJDIR_RELEASE)/obj_loader.o: obj_loader.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c obj_loader.cpp -o $(OBJDIR_RELEASE)/obj_loader.o

$(OBJDIR_RELEASE)/mesh.o: $(SRC)/Mesh.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c $(SRC)/Mesh.cpp -o $(OBJDIR_RELEASE)/mMsh.o

$(OBJDIR_RELEASE)/main.o: $(SRC)/main.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c $(SRC)/main.cpp -o $(OBJDIR_RELEASE)/main.o

$(OBJDIR_RELEASE)/Window.o: $(SRC)/Window.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c $(SRC)/Window.cpp -o $(OBJDIR_RELEASE)/Window.o

$(OBJDIR_RELEASE)/Utility.o: $(SRC)/Utility.cpp
	$(CXX) $(CFLAGS_RELEASE) $(INC_RELEASE) -c $(SRC)/Utility.cpp -o $(OBJDIR_RELEASE)/Utility.o

clean_release: 
	rm -f $(OBJ_RELEASE) $(OUT_RELEASE)
	rm -rf bin/Release
	rm -rf $(OBJDIR_RELEASE)

.PHONY: before_debug after_debug clean_debug before_release after_release clean_release
