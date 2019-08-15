# Program name: Final Project
# Name: Jason Rash
# Date: 8-13-19
# Description: makefile for Final Project

#https://www.gnu.org/software/make/manual/html_node/make-Deduces.html

#OBJS specifies which .o files to create as part of the project
OBJS = main.o menu.o validation.o bunker.o camp.o game.o house.o item.o player.o space.o street.o

#CC is the compiler to use
CC = g++

#CXXFLAGS specifies the additional compilation options
CXXFLAGS = -std=c++0x -Wall

#EXE_NAME specifies the name of our exectuable
EXE_NAME = Final

#This is the target that compiles our executable
all : $(OBJS)
	$(CC) $(CXXFLAGS) $(LINKER_FLAGS) -o $(EXE_NAME) $(OBJS)

main.o : menu.hpp
menu.o : game.hpp
validation.o : validation.hpp
bunker.o : bunker.hpp space.hpp item.hpp validation.hpp
camp.o : camp.hpp space.hpp item.hpp validation.hpp
game.o : game.hpp menu.hpp validation.hpp space.hpp house.hpp camp.hpp street.hpp bunker.hpp player.hpp
house.o : house.hpp space.hpp item.hpp validation.hpp
item.o : item.hpp
player.o : player.hpp item.hpp validation.hpp
space.o : space.hpp item.hpp validation.hpp
street.o : space.hpp

.PHONY : clean

#removes all .o files from current directory
clean :
	rm *.o $(EXE_NAME)

