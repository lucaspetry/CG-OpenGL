LIBS = -lGL -lGLU -lglut
INCLUDES = -I./usr/include/GL
CC = g++
CPPFLAGS = -DGTEST_HAS_PTHREAD=0
CXXFLAGS = -g
EXECUTABLE = ModHierarquicoOpenGL

SRC_DIR = src
SRCS = $(SRC_DIR)/OpenGL.cpp \

all:
	g++ $(SRCS) -o $(EXECUTABLE) $(INCLUDES) $(LIBS)
	@echo 'Build complete!'

clean:
	rm -rf $(EXECUTABLE)