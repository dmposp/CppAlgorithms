# *****************************
# Control Makefile operations

CFLAGS = -Wall -g
CXX = g++
CC = gcc

# *****************************
# Targets to update executable

# VPATH = CppAlgorithms:CppAlgorithms/LRUCache

main: main.o doubly_list.o lrucache.o
	g++ -o a.out main.o lrucache.o doubly_list.o

main.o: main.cc
	g++ -c main.cc

doubly_list.o: doubly_list.cc doubly_list.h
	g++ -c doubly_list.cc

lrucache.o: lrucache.cc lrucache.h
	g++ -c lrucache.cc