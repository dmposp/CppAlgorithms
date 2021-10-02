# *****************************
# Control Makefile operations

CFLAGS = -Wall -g
CXX = g++
CC = gcc

# *****************************
# Targets to update executable

# VPATH = CppAlgorithms:CppAlgorithms/LRUCache

main: main.o Node.o LRUCache.o
	g++ -o a.out main.o LRUCache.o Node.o

main.o: main.cpp
	g++ -c main.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

LRUCache.o: LRUCache.cpp LRUCache.h
	g++ -c LRUCache.cpp