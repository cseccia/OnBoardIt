#
# Cross Platform Makefile
# Compatible with MSYS2/MINGW, Ubuntu 14.04.1 and Mac OS X
#
# You will need SDL2 (http://www.libsdl.org):
# Linux:
#   apt-get install libsdl2-dev
# Mac OS X:
#   brew install sdl2
# MSYS2:
#   pacman -S mingw-w64-i686-SDL
#

#CXX = g++
#CXX = clang++

OBJDIR = obj

EXE = OnBoardIt
SOURCES = ./src/Env.cpp ./src/Imgui_env.cpp ./src/main.cpp ./src/Game.cpp ./src/Tool.cpp ./src/ANode.cpp ./src/NodeManager.cpp ./src/TurnSketch.cpp
SOURCES += ./src/node/Print.cpp
SOURCES += ./lib/imgui/examples/imgui_impl_sdl.cpp ./lib/imgui/examples/imgui_impl_opengl3.cpp
SOURCES += ./lib/imgui/imgui.cpp ./lib/imgui/imgui_demo.cpp ./lib/imgui/imgui_draw.cpp ./lib/imgui/imgui_widgets.cpp
OBJS = $(addprefix $(OBJDIR)/, $(addsuffix .o, $(basename $(notdir $(SOURCES)))))
UNAME_S := $(shell uname -s)

CXXFLAGS = -I./lib/imgui/examples/ -I./lib/imgui/
CXXFLAGS += -g -Wall -Wformat
LIBS =

##---------------------------------------------------------------------
## OPENGL LOADER
##---------------------------------------------------------------------

## Using OpenGL loader: gl3w [default]
SOURCES += ./lib/imgui/examples/libs/gl3w/GL/gl3w.c
CXXFLAGS += -I./lib/imgui/examples/libs/gl3w

## Using OpenGL loader: glew
## (This assumes a system-wide installation)
# CXXFLAGS = -lGLEW -DIMGUI_IMPL_OPENGL_LOADER_GLEW

## Using OpenGL loader: glad
## (You'll also need to change the rule at line ~77 of this Makefile to compile/link glad.c/.o)
# SOURCES += ../libs/glad/src/glad.c
# CXXFLAGS = -I../libs/glad/include -DIMGUI_IMPL_OPENGL_LOADER_GLAD

##---------------------------------------------------------------------
## BUILD FLAGS PER PLATFORM
##---------------------------------------------------------------------

ifeq ($(UNAME_S), Linux) #LINUX
	ECHO_MESSAGE = "Linux"
	LIBS += -lGL -ldl `sdl2-config --libs`

	CXXFLAGS += -I./lib/imgui/examples/libs/gl3w `sdl2-config --cflags`
	CFLAGS = $(CXXFLAGS)
endif

ifeq ($(UNAME_S), Darwin) #APPLE
	ECHO_MESSAGE = "Mac OS X"
	LIBS += -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo `sdl2-config --libs`
	LIBS += -L/usr/local/lib -L/opt/local/lib

	CXXFLAGS += -I./lib/imgui/examples/libs/gl3w `sdl2-config --cflags`
	CXXFLAGS += -I/usr/local/include -I/opt/local/include
	CFLAGS = $(CXXFLAGS)
endif

ifeq ($(findstring MINGW,$(UNAME_S)),MINGW)
   ECHO_MESSAGE = "MinGW"
   LIBS += -lgdi32 -lopengl32 -limm32 `pkg-config --static --libs sdl2`

   CXXFLAGS += -I./lib/imgui/examples/libs/gl3w `pkg-config --cflags sdl2`
   CFLAGS = $(CXXFLAGS)
endif

##---------------------------------------------------------------------
## BUILD RULES
##---------------------------------------------------------------------

$(OBJDIR)/%.o:./lib/imgui/examples/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJDIR)/%.o:./lib/imgui/%.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJDIR)/%.o:./src/node/%.cpp
	$(CXX) $(CXXFLAGS) -std=c++11 -c -o $@ $<

$(OBJDIR)/%.o:./src/%.cpp
	$(CXX) $(CXXFLAGS) -std=c++11 -c -o $@ $<

$(OBJDIR)/%.o:./lib/imgui/examples/libs/gl3w/GL/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

all: $(EXE)
	@echo Build complete for $(ECHO_MESSAGE)

$(EXE): $(OBJS)
	$(CXX) -o $@ $^ $(CXXFLAGS) $(LIBS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(EXE)

re: fclean all

test:
	echo $(OBJS)
